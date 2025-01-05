#include <iostream>
#include "../include/PasswordManager.hpp"

int main() {
    std::string dbName, masterPassword;    
    std::cout << "Password Manager\n" << "Enter source database name (new or existing): ";
    std::cin >> dbName;
    std::cout << "Enter master password: ";
    std::cin >> masterPassword;

    wk::PasswordManager pm(dbName, masterPassword);
    pm.run();

    return 0;
}