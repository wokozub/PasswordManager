#include "../include/PinEntry.hpp"
#include <string>
#include <iostream>
#include <fstream>

namespace wk {

    PinEntry::PinEntry() {}

    PinEntry::PinEntry(const std::string& title, const int& pin, const std::string& description)
        : Entry(title, description), m_pin(pin) {}

    char PinEntry::getType() const {
        return 'n';
    }

    void PinEntry::display() const {
        std::cout << "\n" << title
                    << "\nPIN: " << m_pin
                    << "\ndescription: " << description
                    << std::endl;
    }

    void PinEntry::save(std::ostream& stream) const {
        char type = this->getType();
        stream.write(&type, sizeof(type));

        size_t titleSize = title.size();
        stream.write(reinterpret_cast<const char*>(&titleSize), sizeof(titleSize));
        stream.write(title.data(), titleSize);

        stream.write(reinterpret_cast<const char*>(&m_pin), sizeof(m_pin));

        size_t descSize = description.size();
        stream.write(reinterpret_cast<const char*>(&descSize), sizeof(descSize));
        stream.write(description.data(), descSize);
    }

    void PinEntry::load(std::istream& stream) {
        size_t titleSize;
        stream.read(reinterpret_cast<char*>(&titleSize), sizeof(titleSize));
        title.resize(titleSize);
        stream.read(&title[0], titleSize);

        stream.read(reinterpret_cast<char*>(&m_pin), sizeof(m_pin));

        size_t descSize;
        stream.read(reinterpret_cast<char*>(&descSize), sizeof(descSize));
        description.resize(descSize);
        stream.read(&description[0], descSize);
    }

    int PinEntry::getPin() const {
        return m_pin;
    }

    void PinEntry::setPin(int pin) {
        m_pin = pin;
    }

}