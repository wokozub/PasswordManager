#ifndef PIN_ENTRY_HPP
#define PIN_ENTRY_HPP

#include "Entry.hpp"
#include <string>

namespace wk {

    /**
     * \class PinEntry
     * \brief Represents a PIN code entry in the password manager.
     * 
     * This class extends the `Entry` class and represents a PIN entry 
     * with additional field intiger type.
     */
    class PinEntry : public Entry {
    public:
        /**
         * \brief Default constructor.
         */
        PinEntry();

        /**
         * \brief Parametrized constructor.
         * 
         * \param title The title of the entry.
         * \param pin The personal identification number.
         * \param description Additional information.
         */
        PinEntry(const std::string& title, const int& pin, const std::string& description);

        char getType() const override;
        void display() const override;

        void save(std::ostream& stream) const;
        void load(std::istream& stream);

        /**
         * \brief Gets the PIN code.
         * \return The PIN code of the entry.
         */
        int getPin() const;

        /**
         * \brief Sets the PIN code.
         * \param pin The new PIN code to set.
         */
        void setPin(int pin);
    private:
        int m_pin; /**< The PIN code of the entry. */
    };

}

#endif