#include "Library.h"
#include "../Repository/LibraryItemRepository.h"

Library::Library(const std::string& name, const std::string& address)
    : name(name), address(address), itemRepository(LibraryItemRepository::getInstance()) {}

void Library::displayInfo() const 
{
    std::cout << "Library Info: " << name << " at " << address << std::endl;
}

void Library::addLibraryItem(ILibraryItem* item) 
{
    itemRepository.addLibraryItem(item);
}

ILibraryItem* Library::findLibraryItem(const std::string& title) const 
{
    return itemRepository.findLibraryItem(title);
}
