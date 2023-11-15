#include "LibraryItemFactory.h"
#include "../../../Items/Book.h"
#include "../../../Items/DVD.h"

ILibraryItem* LibraryItemFactory::createBook(const std::string& title, const std::string& author, const std::string &dateOfRelease) 
{
    return new Book(title, author, dateOfRelease);
}

ILibraryItem* LibraryItemFactory::createDVD(const std::string& title, const std::string& director, const std::string &dateOfRelease) 
{
    return new DVD(title, director, dateOfRelease);
}