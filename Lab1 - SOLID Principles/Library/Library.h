#ifndef LIBRARY_H
#define LIBRARY_H

#include "LibraryInfo.h"
#include "../Repository/ILibraryItemRepository.h"
#include <iostream>

class Library 
{
    private:
        LibraryInfo info;
        ILibraryItemRepository& itemRepository;

    public:
        Library(const LibraryInfo& info, ILibraryItemRepository& itemRepository);
        void addLibraryItem(ILibraryItem* item);
        ILibraryItem* findLibraryItem(const std::string& title) const;
};

#endif // LIBRARY_H
