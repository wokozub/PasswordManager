#ifndef PASSWORD_MANAGER_HPP
#define PASSWORD_MANAGER_HPP

#include "Database.hpp"
#include <string>

namespace wk {

    /**
     * \class PasswordManager
     * \brief Handles the main menu for user interaction
     * 
     * The `PasswordManager` class is responsible for interacting with the `Database` class to manage
     * password entries. It provides logic of load and saving the database from a file
     * and also provides functionality to add, remove, and display password entries.
     */
    class PasswordManager {
    public:
        /**
         * \brief Parametrized constructor.
         * 
         * This constructor initializes the password manager and sets up the database.
         * 
         * \param dbName The relative path and name of the database file (in UNIX-style path format)
         * \param masterPassword The master password used to access the database.
         */
        PasswordManager(const std::string& dbName, const std::string& masterPassword);

        /**
         * \brief Runs the password manager interface.         * 
         * This method presents a menu to the user and processes the user's choices.
         */
        void run();

    private:
        Database db; /**< The `Database` object. */
        std::string filename; /**< UNIX-style path format for database */

        /**
         * \brief Displays the main menu options.         * 
         * This method displays the list of actions the user can choose from, such as adding
         * an entry, removing an entry, displaying entries, saving the database, or exiting.
         */
        void displayMenu();

        /**
         * \brief Handle the 'Database::addEntry'
         * Adds a new entry to the database.
         */
        void newEntry();

        /**
         * \brief Handle the 'Database::removeEntry'
         * Removes an entry from the database.
         */
        void deleteEntry();

        /**
         * \brief Handle the 'Database::saveToFile'
         * Saves the current database to a file.
         */
        void saveDB();

        /**
         * \brief Handle the 'Database::loadFromFile'
         * Loads the database from a file.
         */
        void loadDB();
    };

}

#endif