#ifndef BOOK_H
#define BOOK_H

#include "ILibraryItem.h"
#include "../Prototype/ILibraryItemPrototype.h"
#include <string>

class Book : public ILibraryItem, public ILibraryItemPrototype
{
private:
    std::string title;
    std::string author;
    std::string dateOfRelease;

public:
    Book(const std::string &title, const std::string &author, const std::string &dateOfRelease);
    void displayInfo() const override;
    void displayFullInfo() const override;
    std::string getTitle() const override;
    ILibraryItemPrototype *clone() const override;
};

#endif // BOOK_H
