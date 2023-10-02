#ifndef LIBRARY_H
#define LIBRARY_H

#include "../Repository/LibraryItemRepository.h"
#include <iostream>

class Library 
{
    private:
        std::string name;
        std::string address;
        LibraryItemRepository& itemRepository;

    public:
        Library(const std::string& name, const std::string& address);
        void displayInfo() const;
        void addLibraryItem(ILibraryItem* item);
        ILibraryItem* findLibraryItem(const std::string& title) const;
};

#endif // LIBRARY_H
