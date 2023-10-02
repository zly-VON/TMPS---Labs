#include "LibraryItemFactory.h"
#include "../Items/Book.h"
#include "../Items/DVD.h"

ILibraryItem* LibraryItemFactory::createBook(const std::string& title, const std::string& author) 
{
    return new Book(title, author);
}

ILibraryItem* LibraryItemFactory::createDVD(const std::string& title, const std::string& director) 
{
    return new DVD(title, director);
}