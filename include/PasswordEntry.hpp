#ifndef PASSWORD_ENTRY_HPP
#define PASSWORD_ENTRY_HPP

#include "Entry.hpp"
#include <string>

namespace wk {

    /**
     * \ingroup Entries
     * \class PasswordEntry
     * \brief Represents a password entry in the password manager.
     * 
     * This class extends the `Entry` class and represents a password entry with additional
     * fields such as username and password.
     */
    class PasswordEntry : public Entry {
    public:
        /**
         * \brief Default constructor.
         */
        PasswordEntry();

        /**
         * \brief Parametrized constructor.
         * 
         * \param title The title of the entry.
         * \param username The username.
         * \param password The password.
         * \param description Additional information.
         */
        PasswordEntry(const std::string& title, const std::string& username, const std::string& password, const std::string& description);

        char getType() const override;
        void display() const override;

        void save(std::ostream& stream) const;
        void load(std::istream& stream);

        /**
         * \brief Gets the username.
         * \return The username of the entry.
         */
        std::string getUsername() const;

        /**
         * \brief Gets the password.
         * \return The password of the entry.
         */
        std::string getPassword() const;

        /**
         * \brief Sets the username.
         * \param username The new username to set.
         */
        void setUsername(std::string username);

        /**
         * \brief Sets the password.
         * \param password The new password to set.
         */
        void setPassword(std::string password);
    private:
        std::string m_username; /**< The username of the entry. */
        std::string m_password; /**< The password of the entry. */
    };

}

#endif