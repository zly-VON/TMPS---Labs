#include "LibraryMember.h"
#include "../Patterns/Behavioral/Command/BorrowCommand.h"
#include <iostream>
#include <algorithm>

LibraryMember::LibraryMember(const std::string& name) : name(name) 
{
    std::cout << "New Library Member Registered: " << name << std::endl;
}

void LibraryMember::borrowItem(ILibraryItem* item) 
{
    borrowedItems.push_back(item);
    // std::cout << name << " borrowed: ";
    // item->displayInfo();
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

void LibraryMember::displayBorrowedItems() const 
{
    std::cout << name << "'s borrowed items:" << std::endl;
    for (const auto& item : borrowedItems) 
    {
        item->displayInfo();
    }
}

std::string LibraryMember::getName() const 
{
    return name;
}

void LibraryMember::displayInfo() const 
{
    std::cout << "Library Member: " << name << std::endl;
}

void LibraryMember::update() 
{
    std::cout << name << " was notified." << std::endl;
}

void LibraryMember::executeBorrowCommand(ILibraryItem* item) 
{
    ILibraryCommand* command = new BorrowCommand(item, this);
    command->execute();
    delete command;
}

void LibraryMember::enqueueCommand(ILibraryCommand* command) 
{
    commandQueue.addCommand(command);
}