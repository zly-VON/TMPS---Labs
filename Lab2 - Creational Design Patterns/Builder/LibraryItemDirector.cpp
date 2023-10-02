#include "LibraryItemDirector.h"

ILibraryItem* LibraryItemDirector::construct(ILibraryItemBuilder& builder, const std::string& title, const std::string& creator) 
{
    builder.buildTitle(title);
    builder.buildCreator(creator);
    return builder.getResult();
}