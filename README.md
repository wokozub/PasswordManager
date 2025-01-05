# Password Manager

Student project on object-oriented programming course.

The Doxygen documentation for the project is available
[here](https://github.io).

# Building

Application requires the OpenSSL library.

## Linux

### Install the OpenSSL library
On Ubuntu, install the OpenSSL development package by running:

    sudo apt update
    sudo apt-get install libssl-dev

### Clone the repository

    git clone <repository-url>
    cd <repository-name>

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

## Introduction

Welcome to the Password Manager Documentation. This project is a tool for managing your passwords and sensitive information. It includes features such as:
- Adding and managing password entries.
- Encrypting data with OpenSSL.
- Terminal interface for database operations.

## Features
- **Secure encryption**: All data is encrypted using AES-256-CBC.
- **User-friendly**: Simple command-line interface for managing entries.
- **Flexibility**: Supports various types of entries, such as passwords and PINs.

## Usage
To start using the application:
1. Build the project.
2. Run the main executable.
3. Follow the menu options to add, view, and manage entries.

## Author
This project was developed by Wojciech Kozub.

## Copyright
GNU General Public License.