#ifndef ENCRYPTOR_HPP
#define ENCRYPTOR_HPP

#include <string>
#include <openssl/evp.h>
#include <openssl/sha.h>

namespace wk {

    /**
     * \ingroup Utils
     * \class Encryptor
     * \brief A class responsible for encrypting and decrypting data using AES-256-CBC.
     * 
     * The `Encryptor` class uses the OpenSSL library to encrypt and decrypt data with the AES-256-CBC algorithm.
     * It generates an encryption key and an initialization vector (IV) from the provided password using SHA-512.
     * This class requires the OpenSSL library.
     */
    class Encryptor {
    public:
        /**
         * \brief Parametrized constructor
         * 
         * This constructor generates the encryption key and IV using SHA-512 based on the provided password.
         * 
         * \param password The password used to generate the encryption key and IV.
         */
        Encryptor(const std::string& password);

        /**
         * \brief Destructor.
         * 
         * Cleans up any allocated resources.
         */
        ~Encryptor();

        /**
         * \brief Encrypts the provided data and saves it to a binary file.
         * 
         * Using in 'Database::saveToFile'
         * This method encrypts the input data using AES-256-CBC and writes the encrypted content to an output file.
         * 
         * \param data The input data to be encrypted.
         * \param outputFile The binary file to save the encrypted data.
         * \return True if encryption is successful, false otherwise.
         */
        bool encryptData(const std::string& data, const std::string& outputFile);

        /**
         * \brief Decrypts data from an input binary file.
         *
         * Using in 'Database::loadFromFile'
         * This method reads the encrypted data from the input file and decrypts it using AES-256-CBC.
         * 
         * \param inputFile The binary file containing the encrypted data.
         * \param output The string to store the decrypted data.
         * \return True if decryption is successful, false otherwise.
         */
        bool decryptData(const std::string& inputFile, std::string& output);

    private:
        unsigned char key[EVP_MAX_KEY_LENGTH]; /**< The encryption key generated from the password */
        unsigned char iv[EVP_MAX_IV_LENGTH];  /**< The initialization vector (IV) */
    };

}

#endif