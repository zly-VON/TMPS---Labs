#ifndef BOOK_H
#define BOOK_H

#include "ILibraryItem.h"
#include "../Patterns/Creational/Prototype/ILibraryItemPrototype.h"
#include "../Patterns/Structural/Composite/ILibraryComponent.h"
#include <string>

class Book : public ILibraryItem, public ILibraryItemPrototype, public ILibraryComponent
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
    std::string getAuthor() const override;
    ILibraryItemPrototype *clone() const override;
};

#endif // BOOK_H
