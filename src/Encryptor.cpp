#include "../include/Encryptor.hpp"
#include <openssl/rand.h>
#include <sstream>
#include <fstream>

namespace wk {

    Encryptor::Encryptor(const std::string& password) {
        unsigned char hash[SHA512_DIGEST_LENGTH];
        SHA512(reinterpret_cast<const unsigned char*>(password.c_str()), password.size(), hash);

        std::copy(hash, hash + EVP_MAX_KEY_LENGTH, key); // define key
        std::copy(hash + EVP_MAX_KEY_LENGTH, hash + EVP_MAX_KEY_LENGTH + EVP_MAX_IV_LENGTH, iv); // define IV
    }

    Encryptor::~Encryptor() {}

    bool Encryptor::encryptData(const std::string& data, const std::string& outputFile) {
        std::ofstream out(outputFile, std::ios::binary);
        if (!out) return false;

        // Generate IV and write it
        if (!RAND_bytes(iv, EVP_MAX_IV_LENGTH)) return false;
        out.write(reinterpret_cast<char*>(iv), EVP_MAX_IV_LENGTH);

        // Initialize encryption context
        EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
        EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), nullptr, key, iv);

        const char* input = data.data();
        size_t inputLen = data.size();

        unsigned char buffer[4096];
        int len;

        while (inputLen > 0) {
            int chunkSize = std::min(inputLen, sizeof(buffer));
            if (!EVP_EncryptUpdate(ctx, buffer, &len, reinterpret_cast<const unsigned char*>(input), chunkSize)) {
                EVP_CIPHER_CTX_free(ctx);
                return false;
            }
            out.write(reinterpret_cast<char*>(buffer), len);
            input += chunkSize;
            inputLen -= chunkSize;
        }

        if (!EVP_EncryptFinal_ex(ctx, buffer, &len)) {
            EVP_CIPHER_CTX_free(ctx);
            return false;
        }
        out.write(reinterpret_cast<char*>(buffer), len);
        EVP_CIPHER_CTX_free(ctx);

        return true;
    }

    bool Encryptor::decryptData(const std::string& inputFile, std::string& output) {
        std::ifstream in(inputFile, std::ios::binary);
        if (!in) return false;

        // Read IV
        in.read(reinterpret_cast<char*>(iv), EVP_MAX_IV_LENGTH);
        if (in.gcount() != EVP_MAX_IV_LENGTH) return false;

        // Initialize decryption context
        EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
        EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), nullptr, key, iv);

        char buffer[4096];
        unsigned char decrypted[4096];
        int len;
        std::ostringstream result;

        while (in.read(buffer, sizeof(buffer)) || in.gcount() > 0) {
            if (!EVP_DecryptUpdate(ctx, decrypted, &len, reinterpret_cast<unsigned char*>(buffer), in.gcount())) {
                EVP_CIPHER_CTX_free(ctx);
                return false;
            }
            result.write(reinterpret_cast<char*>(decrypted), len);
        }

        if (!EVP_DecryptFinal_ex(ctx, decrypted, &len)) {
            EVP_CIPHER_CTX_free(ctx);
            return false;
        }
        result.write(reinterpret_cast<char*>(decrypted), len);
        EVP_CIPHER_CTX_free(ctx);

        output = result.str();
        return true;
    }

}