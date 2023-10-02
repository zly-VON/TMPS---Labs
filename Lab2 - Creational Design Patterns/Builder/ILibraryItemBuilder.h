#ifndef ILIBRARYITEMBUILDER_H
#define ILIBRARYITEMBUILDER_H

#include "../Items/ILibraryItem.h"

class ILibraryItemBuilder 
{
public:
    virtual void buildTitle(const std::string& title) = 0;
    virtual void buildCreator(const std::string& creator) = 0;;
    virtual ILibraryItem* getResult() = 0;
};

#endif // ILIBRARYITEMBUILDER_H