// LibraryItemFactory.h
#ifndef LIBRARYITEMFACTORY_H
#define LIBRARYITEMFACTORY_H

#include "../../../Items/ILibraryItem.h"

class LibraryItemFactory 
{
public:
    static ILibraryItem* createBook(const std::string& title, const std::string& author, const std::string &dateOfRelease);
    static ILibraryItem* createDVD(const std::string& title, const std::string& director, const std::string &dateOfRelease);
};

#endif // LIBRARYITEMFACTORY_H
