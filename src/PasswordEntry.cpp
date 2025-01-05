#include "../include/PasswordEntry.hpp"
#include <string>
#include <iostream>
#include <fstream>

namespace wk {

    PasswordEntry::PasswordEntry() {}

    PasswordEntry::PasswordEntry(const std::string& title, const std::string& username, const std::string& password, const std::string& description)
        : Entry(title, description), m_username(username), m_password(password) {}

    char PasswordEntry::getType() const {
        return 'w';
    }

    void PasswordEntry::display() const {
        std::cout  << "\n" << title
                    << "\nusername: " << m_username
                    << "\npassword: " << m_password
                    << "\ndescription: " << description
                    << std::endl;
    }

    void PasswordEntry::save(std::ostream& stream) const {
        char type = this->getType();
        stream.write(&type, sizeof(type));

        size_t titleSize = title.size();
        stream.write(reinterpret_cast<const char*>(&titleSize), sizeof(titleSize));
        stream.write(title.data(), titleSize);

        size_t usernameSize = m_username.size();
        stream.write(reinterpret_cast<const char*>(&usernameSize), sizeof(usernameSize));
        stream.write(m_username.data(), usernameSize);

        size_t passwordSize = m_password.size();
        stream.write(reinterpret_cast<const char*>(&passwordSize), sizeof(passwordSize));
        stream.write(m_password.data(), passwordSize);

        size_t descSize = description.size();
        stream.write(reinterpret_cast<const char*>(&descSize), sizeof(descSize));
        stream.write(description.data(), descSize);
    }

    void PasswordEntry::load(std::istream& stream) {
        size_t titleSize;
        stream.read(reinterpret_cast<char*>(&titleSize), sizeof(titleSize));
        title.resize(titleSize);
        stream.read(&title[0], titleSize);

        size_t usernameSize;
        stream.read(reinterpret_cast<char*>(&usernameSize), sizeof(usernameSize));
        m_username.resize(usernameSize);
        stream.read(&m_username[0], usernameSize);

        size_t passwordSize;
        stream.read(reinterpret_cast<char*>(&passwordSize), sizeof(passwordSize));
        m_password.resize(passwordSize);
        stream.read(&m_password[0], passwordSize);

        size_t descSize;
        stream.read(reinterpret_cast<char*>(&descSize), sizeof(descSize));
        description.resize(descSize);
        stream.read(&description[0], descSize);
    }


    std::string PasswordEntry::getUsername() const {
        return m_username;
    }

    std::string PasswordEntry::getPassword() const {
        return m_password;
    }

    void PasswordEntry::setUsername(std::string username) {
        m_username = username;
    }

    void PasswordEntry::setPassword(std::string password) {
        m_password = password;
    }

}