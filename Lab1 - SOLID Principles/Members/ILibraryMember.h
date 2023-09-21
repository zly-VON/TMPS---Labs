#ifndef ILIBRARYMEMBER_H
#define ILIBRARYMEMBER_H

#include "../Items/ILibraryItem.h"

class ILibraryMember 
{
    public:
        virtual void borrowItem(ILibraryItem* item) = 0;
        virtual void returnItem(ILibraryItem* item) = 0;
        // virtual ~ILibraryMember() {}
};

#endif // ILIBRARYMEMBER_H
