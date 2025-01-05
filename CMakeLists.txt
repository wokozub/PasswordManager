cmake_minimum_required(VERSION 3.10)

project(PasswordManager)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(OpenSSL REQUIRED)
# to install:
# sudo apt update
# sudo apt install libssl-dev

include_directories(include)

set(SOURCES
    src/Entry.cpp
    src/PasswordEntry.cpp
    src/PinEntry.cpp
    src/main.cpp
    src/Database.cpp    
    src/Encryptor.cpp
    src/PasswordManager.cpp
)

add_executable(PasswordManager ${SOURCES})

target_link_libraries(PasswordManager PRIVATE OpenSSL::Crypto)