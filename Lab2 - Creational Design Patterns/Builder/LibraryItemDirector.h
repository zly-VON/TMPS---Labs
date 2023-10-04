#ifndef LIBRARYITEMDIRECTOR_H
#define LIBRARYITEMDIRECTOR_H

#include "ILibraryItemBuilder.h"

class LibraryItemDirector 
{
public:
    ILibraryItem* constructBook(ILibraryItemBuilder& builder, const std::string& title, const std::string& author = "", const std::string &dateOfRelease = "");
    ILibraryItem* constructDVD(ILibraryItemBuilder& builder, const std::string& title, const std::string& director = "", const std::string &dateOfRelease = "");
};

#endif // LIBRARYITEMDIRECTOR_H