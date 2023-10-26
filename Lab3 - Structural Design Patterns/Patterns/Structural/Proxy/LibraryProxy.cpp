#include "LibraryProxy.h"
#include <iostream>

LibraryProxy::LibraryProxy(ILibraryItem* item) : realItem(item), accessCount(0)  {}

void LibraryProxy::displayInfo() const 
{
    accessCount++;
    realItem->displayInfo();
    logInteraction("displayInfo");
}

void LibraryProxy::displayFullInfo() const 
{
    accessCount++;
    realItem->displayFullInfo();
    logInteraction("displayFullInfo");
}

std::string LibraryProxy::getTitle() const 
{
    accessCount++;
    return realItem->getTitle();
    logInteraction("getTitle");
}

std::string LibraryProxy::getAuthor() const 
{
    accessCount++;
    return realItem->getAuthor();
    logInteraction("getAuthor");
}

void LibraryProxy::logInteraction(const std::string& action) const 
{
    std::cout << "\nLogged: Library Member performed action '" << action << "' on item '"
                << realItem->getTitle() << "'" << std::endl;
}

void LibraryProxy::getAccessCount() 
{
    std::cout << "Access Count on item '" << realItem->getTitle() << "'" << ": " << accessCount << std::endl;
}

void LibraryProxy::markAsBorrowed() 
{
    if (!hasBeenBorrowed) {
        logInteraction("borrowBook");
        hasBeenBorrowed = true;
        accessCount++;
    }
}
