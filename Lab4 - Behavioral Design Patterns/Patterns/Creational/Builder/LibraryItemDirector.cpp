#include "LibraryItemDirector.h"

ILibraryItem* LibraryItemDirector::constructBook(ILibraryItemBuilder& builder, const std::string& title, const std::string& author, const std::string &dateOfRelease) 
{
    builder.buildTitle(title);
    builder.buildCreator(author);
    builder.buildDate(dateOfRelease);
    return builder.getResult();
}

ILibraryItem* LibraryItemDirector::constructDVD(ILibraryItemBuilder& builder, const std::string& title, const std::string& director, const std::string &dateOfRelease) 
{
    builder.buildTitle(title);
    builder.buildCreator(director);
    builder.buildDate(dateOfRelease);
    return builder.getResult();
}