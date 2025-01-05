#ifndef DATABASE_HPP
#define DATABASE_HPP

#include "PasswordEntry.hpp"
#include "PinEntry.hpp"
#include "Encryptor.hpp"
#include <variant>
#include <vector>

namespace wk {

    /**
     * \ingroup Utils
     * \class Database
     * \brief Manages a collection of password and PIN entries.
     *
     * The Database class provides functionalities to add, remove, display, 
     * and persist entries. It supports both password and PIN entries using 
     * variants.
     */
    class Database {
    public:
        /**
         * \brief Constructs a Database with a master password.
         * \param password The master password to encrypt/decrypt file.
         */
        Database(const std::string& password);

        /**
         * \brief Checking for existing titles.
         * Using in 'PasswordManager::newEntry' to ensure that each
         * new entry added to the database has a unique title. 
         */
        bool titleExists(const std::string& title) const;

        /**
         * \brief Adds a new entry to the database.
         * \param entry A variant containing either a PasswordEntry or PinEntry.
         */
        void addEntry(const std::variant<PasswordEntry, PinEntry>& entry);

        /**
         * \brief Removes an entry from the database by title.
         * \param title The title of the entry to remove.
         */
        void removeEntry(const std::string& title);

        /**
         * \brief Displays all entries in the database.
         */
        void displayEntries() const;

        /**
         * \brief Saves all entries to a file.
         * \param filename The file to save entries into.
         */
        void saveToFile(const std::string& filename);

        /**
         * \brief Loads entries from a file.
         * \param filename The file to load entries from.
         */
        void loadFromFile(const std::string& filename);
    private:
        std::vector<std::variant<PasswordEntry, PinEntry>> entries; /**< Container for storing database entries. */
        Encryptor encryptor; /**< Handles encryption and decryption. */
    };
    
}

#endif