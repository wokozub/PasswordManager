#include "../include/PasswordManager.hpp"
#include <iostream>
#include <filesystem>

namespace wk {

    PasswordManager::PasswordManager(const std::string& dbName, const std::string& password) : filename(dbName), db(password) {}

    void PasswordManager::run() {
        try {
            loadDB();
        } catch (const std::exception& ex) {
            std::cerr << ex.what() << "\n";
            std::cout << "No database loaded. Start with an empty database? (y/n): ";
            char option;
            std::cin >> option;
            if (option != 'y' && option != 'Y') {
                std::cout << "Exiting...\n";
                return;
            }
        }

        int choice;
        do {
            displayMenu();
            std::cin >> choice;

            switch (choice) {
                case 1:
                    newEntry();
                    break;
                case 2:
                    deleteEntry();
                    break;
                case 3:
                    db.displayEntries();
                    break;
                case 4:
                    saveDB();
                    break;
                case 5:
                    std::cout << "Exiting...\n";
                    break;
                default:
                    std::cout << "Invalid choice. Try again.\n";
            }
        } while (choice != 4 && choice != 5);
    }


    void PasswordManager::displayMenu() {
        std::cout << "\n    Password Manager Menu:\n"
                << "    1. Add Entry\n"
                << "    2. Remove Entry\n"
                << "    3. Display Entries\n"
                << "    4. Save and exit\n"
                << "    5. Exit without saving\n"
                << "    Choose an option: ";
    }

    void PasswordManager::newEntry() {
        std::cin.ignore();
        std::string title;
        std::cout << "Enter title: ";
        std::getline(std::cin, title);

        if (db.titleExists(title)) {
            std::cout << "An entry with this title already exists. Please use a different title.\n";
            return;
        }

        int type;
        std::cout << "Choose type of entry:\n"
                << "1. Password Entry\n"
                << "2. PIN Entry\n";
        std::cin >> type;

        std::cin.ignore();
        if (type == 1) {
            std::string username, password, description;
            std::cout << "Enter username: ";
            std::getline(std::cin, username);
            std::cout << "Enter password: ";
            std::getline(std::cin, password);
            std::cout << "Enter description: ";
            std::getline(std::cin, description);
            db.addEntry(PasswordEntry(title, username, password, description));
        } else if (type == 2) {
            std::string description;
            int pin;
            std::cout << "Enter PIN: ";
            std::cin >> pin;
            std::cin.ignore();
            std::cout << "Enter description: ";
            std::getline(std::cin, description);
            db.addEntry(PinEntry(title, pin, description));
        } else {
            std::cout << "Invalid type. Returning to menu.\n";
        }
    }

    void PasswordManager::deleteEntry() {
        std::cin.ignore();
        std::string title;
        std::cout << "Enter the title of the entry to remove: ";
        std::getline(std::cin, title);
        db.removeEntry(title);
    }

    void PasswordManager::saveDB() {
        std::cout << "Saving database to file: " << filename << "\n";
        try {
            db.saveToFile(filename);
            std::cout << "Database saved successfully.\n";
        } catch (const std::exception& ex) {
            std::cerr << "Failed to save database: " << ex.what() << "\n";
        }
    }

    void PasswordManager::loadDB() {
        if (!std::filesystem::exists(filename)) {
            throw std::runtime_error("Database file does not exist.");
        }
        std::cout << "Loading database from file: " << filename << "\n";
        try {
            db.loadFromFile(filename);
            std::cout << "Database loaded successfully.\n";
        } catch (const std::exception& ex) {
            std::cerr << "Failed to load database: " << ex.what() << "\n";
            exit(0);
        }
    }

}