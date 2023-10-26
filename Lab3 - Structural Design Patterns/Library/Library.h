#ifndef LIBRARY_H
#define LIBRARY_H

#include "../Repository/LibraryItemRepository.h"
#include <iostream>
#include <vector>

class Library 
{
    private:
        std::string name;
        std::string address;
        LibraryItemRepository& itemRepository;

    public:
        Library(const std::string& name, const std::string& address, LibraryItemRepository& repo);
        void displayInfo() const;
        void addLibraryItem(ILibraryItem* item);
};

#endif // LIBRARY_H
