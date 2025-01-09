# Password Manager

Student project on object-oriented programming course.

The Doxygen documentation for the project is available
[here](https://wokozub.github.io/PasswordManager/).

## Introduction

Welcome to the Password Manager Documentation. This project is a tool for managing your passwords and sensitive information. It includes features such as:
- Adding and managing password entries.
- Encrypting data with OpenSSL.
- Terminal interface for database operations.

## Features
- **Secure encryption**: All data is encrypted using AES-256-CBC.
- **User-friendly**: Simple command-line interface for managing entries.
- **Flexibility**: Supports various types of entries, such as passwords and PINs.

# Building

Application requires the OpenSSL library.

## Linux

### Install the OpenSSL library
On Ubuntu, install the OpenSSL development package by running:

    sudo apt update
    sudo apt-get install libssl-dev

### Clone the repository

    git clone https://github.com/wokozub/PasswordManager.git
    cd PasswordManager

### Build the project using CMake

A simple way to build this project is with cmake.

    mkdir build
    cd build
    cmake ..
    make
    ./PasswordManager

### Additional Notes

Ensure you have cmake installed. If not, you can install it using:

    sudo apt-get install cmake

# Usage
To start using the application:
1. Build the project.
2. Run the main executable.
3. Create or open existing database.
4. Follow the menu options to add, view, and manage entries.

## Example database
Example with example_database.bin

Password: qwerty123

    $ ./PasswordManager 
    Password Manager
    Enter source database name (new or existing): ../example_database.bin
    Enter master password: qwerty123
    Loading database from file: ../example_database.bin
    Database loaded successfully.

        Password Manager Menu:
        1. Add Entry
        2. Remove Entry
        3. Display Entries
        4. Save and exit
        5. Exit without saving
        Choose an option: 1
    Enter title: main email       
    Choose type of entry:
    1. Password Entry
    2. PIN Entry
    1
    Enter username: wojtek@mail.com
    Enter password: password123
    Enter description: 


        Password Manager Menu:
        1. Add Entry
        2. Remove Entry
        3. Display Entries
        4. Save and exit
        5. Exit without saving
        Choose an option: 3

    fb
    username: Wojtek
    password: strongpassword
    description: meta

    Credit card
    PIN: 4321
    description: my bank

    main email
    username: wojtek@mail.com
    password: password123
    description: 

        Password Manager Menu:
        1. Add Entry
        2. Remove Entry
        3. Display Entries
        4. Save and exit
        5. Exit without saving
        Choose an option: 4
    Saving database to file: ../example_database.bin
    Database saved successfully.