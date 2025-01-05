#ifndef ENTRY_HPP
#define ENTRY_HPP

#include <string>

namespace wk {

    /**
     * \defgroup Core Core Classes
     * Fundamental classes of the application.
     */

    /**
     * \defgroup Entries Entries
     * Classes representing different types of entries.
     */

    /**
     * \defgroup Utils Utilities
     * Tools supporting the application functionality.
     */


    /**
     * \ingroup Core
     * \class Entry
     * \brief Base class for an entry (PasswordEntry, PinEntry).
     * 
     * This class represents a generic entry with a title and description. It serves 
     * as a base class for specialized entry types: PasswordEntry and PinEntry.
     */
    class Entry {
    public:
        /**
         * \brief Default constructor.
         * 
         * Initializes an empty entry with an empty title and description.
         */
        Entry();

        /**
         * \brief Parametrized constructor.
         * 
         * Initializes the entry with a specified title and description.
         * 
         * \param title The title of the entry.
         * \param description The description of the entry.
         */
        Entry(const std::string& title, const std::string& description);

        /**
         * \brief Destructor.
         * 
         * Virtual destructor to allow proper cleanup in derived classes.
         */
        virtual ~Entry();

        /**
         * \brief Returns the type of the entry.
         * \return A character: 'w' for password, 'n' for pin.
         */
        virtual char getType() const = 0;

        /**
         * \brief Displays the entry details.
         */
        virtual void display() const;

        /**
         * \brief To serialized the entry to a stream.
         * \param stream The output stream.
         */
        virtual void save(std::ostream& stream) const;

        /**
         * \brief To deserialized entry data from a stream.
         * \param stream The input stream.
         */
        virtual void load(std::istream& stream);

        /**
         * \brief Returns the title of the entry.
         */
        std::string getTitle() const;

        /**
         * \brief Returns the description of the entry.
         */
        std::string getDescription() const;

        /**
         * \brief Sets the title of the entry.
         * \param title The title to set.
         */
        void setTitle(std::string title);

        /**
         * \brief Sets the description of the entry.
         * \param description The description to set.
         */
        void setDescription(std::string description);
    protected:
        std::string title; /**< The title of the entry. */
        std::string description; /**< The description of the entry. */
    };

}

#endif