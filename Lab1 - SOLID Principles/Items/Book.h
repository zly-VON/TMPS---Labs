#ifndef BOOK_H
#define BOOK_H

#include "ILibraryItem.h"
#include <string>

class Book : public ILibraryItem 
{
    private:
        std::string title;
        std::string author;

    public:
        Book(const std::string& title, const std::string& author);
        void displayInfo() const override;
        std::string getTitle() const override;
};

#endif // BOOK_H
