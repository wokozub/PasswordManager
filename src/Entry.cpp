#include "../include/Entry.hpp"
#include <string>

namespace wk {

    Entry::Entry() {}

    Entry::Entry(const std::string& title, const std::string& description) : title(title), description(description) {}

    Entry::~Entry() {}

    void Entry::display() const {}

    void Entry::save(std::ostream& stream) const {}

    void Entry::load(std::istream& stream) {}

    std::string Entry::getTitle() const {
        return title;
    }

    std::string Entry::getDescription() const {
        return description;
    }

    void Entry::setTitle(std::string name) {
        title = name;
    }

    void Entry::setDescription(std::string des) {
        description = des;
    }

}