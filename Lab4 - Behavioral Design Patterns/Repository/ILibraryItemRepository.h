#ifndef ILIBRARYITEMREPOSITORY_H
#define ILIBRARYITEMREPOSITORY_H

#include "../Items/ILibraryItem.h"
#include <vector>

class ILibraryItemRepository 
{
    public:
        virtual void addLibraryItem(ILibraryItem* item) = 0;
        virtual std::vector<ILibraryItem*> findLibraryItem(const std::string& title) const = 0;
        virtual std::vector<ILibraryItem*> findItemByAuthor(const std::string& title) const = 0;
        // virtual ~ILibraryItemRepository() {}
};

#endif // ILIBRARYITEMREPOSITORY_H
