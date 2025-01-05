#include "../include/Database.hpp"
#include <sstream>

namespace wk {

    Database::Database(const std::string& password) : encryptor(password) {}

    bool Database::titleExists(const std::string& title) const {
        for (const auto& entry : entries) {
            bool found = std::visit([&](const auto& specificEntry) {
                return specificEntry.getTitle() == title;
            }, entry);

            if (found) {
                return true;
            }
        }
        return false;
    }

    void Database::addEntry(const std::variant<PasswordEntry, PinEntry>& entry) {
        entries.push_back(entry);
    }

    void Database::removeEntry(const std::string& title) {
        auto it = entries.begin();
        while (it != entries.end()) {
            std::visit([&](const auto& entry) {
                if (entry.getTitle() == title) {
                    it = entries.erase(it);
                } else {
                    ++it;
                }
            }, *it);
        }
    }

    void Database::displayEntries() const {
        for (const auto& entry : entries) {
            std::visit([](const auto& e) { e.display(); }, entry);
        }
    }

    void Database::saveToFile(const std::string& filename) {
        std::ostringstream buffer;

        // Save data to stream
        for (const auto& entry : entries) {
            std::visit([&](const auto& e) {
                e.save(buffer);
            }, entry);
        }

        // Encryption stream to file
        std::string data = buffer.str();
        if (!encryptor.encryptData(data, filename)) {
            throw std::runtime_error("Encryption failed. Check password.");
        }
    }

    void Database::loadFromFile(const std::string& filename) {
        std::string decryptedData;

        // Decryption file
        if (!encryptor.decryptData(filename, decryptedData)) {
            throw std::runtime_error("Decryption failed. Check password.");
        }

        // Read data from stream
        std::istringstream buffer(decryptedData);
        entries.clear();

        while (buffer) {
            char type;
            buffer.read(&type, sizeof(type));
            if (buffer.eof()) break;

            switch (type) {
            case 'w': {
                PasswordEntry entry;
                entry.load(buffer);
                entries.push_back(entry);
                break;
            }
            case 'n': {
                PinEntry entry;
                entry.load(buffer);
                entries.push_back(entry);
                break;
            }
            default:
                throw std::runtime_error("Unknown entry type in decrypted data.");
            }
        }
    }
}