#ifndef LIBRARYITEMDIRECTOR_H
#define LIBRARYITEMDIRECTOR_H

#include "ILibraryItemBuilder.h"

class LibraryItemDirector 
{
public:
    ILibraryItem* construct(ILibraryItemBuilder& builder, const std::string& title, const std::string& creator = "");
};

#endif // LIBRARYITEMDIRECTOR_H