#include "LibraryMember.h"
#include <iostream>
#include <algorithm>

LibraryMember::LibraryMember(const std::string& name) : name(name) 
{
    std::cout << "New Library Member Registered: " << name << std::endl;
}

void LibraryMember::borrowItem(ILibraryItem* item) 
{
    borrowedItems.push_back(item);
    std::cout << name << " borrowed: ";
    item->displayInfo();
}

void LibraryMember::returnItem(ILibraryItem* item) 
{
    auto it = std::find(borrowedItems.begin(), borrowedItems.end(), item);
    if (it != borrowedItems.end()) {
        borrowedItems.erase(it);
        std::cout << name << " returned: ";
        item->displayInfo();
    }
}

void LibraryMember::displayInfo() const 
{
    std::cout << "Library Member: " << name << std::endl;
}
