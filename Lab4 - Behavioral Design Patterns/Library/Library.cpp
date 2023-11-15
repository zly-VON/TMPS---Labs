#include "Library.h"
#include "../Repository/LibraryItemRepository.h"

Library::Library(const std::string& name, const std::string& address, LibraryItemRepository& repo)
    : name(name), address(address), itemRepository(LibraryItemRepository::getInstance()) {}

void Library::displayInfo() const 
{
    std::cout << "Library Info: " << name << " at " << address << std::endl;
}

void Library::displayLibraryItems() const 
{
    std::cout << "\nLibrary Items: " << std::endl;
    const std::vector<ILibraryItem*>& items = itemRepository.getAllLibraryItems();

    for (const ILibraryItem* item : items) 
    {
        item->displayInfo();
    }

    std::cout << std::endl;
}

void Library::addLibraryItem(ILibraryItem* item) 
{
    itemRepository.addLibraryItem(item);
    notifyObservers();
}

void Library::attachObserver(ILibraryObserver* observer) 
{
    observers.push_back(observer);
}

void Library::notifyObservers() 
{
    for (auto observer : observers) 
    {
        observer->update();
    }
}

void Library::update() 
{
    notifyObservers();
}

void Library::enqueueCommand(ILibraryCommand* command) 
{
    commandQueue.addCommand(command);
}

void Library::processCommandQueue() 
{
    commandQueue.executeCommands();
}

void Library::displaySortedBooks(IStrategy* sortingStrategy) const 
{
    std::vector<ILibraryItem*> items = itemRepository.getAllLibraryItems();

    if (sortingStrategy) {
        itemRepository.setSortingStrategy(sortingStrategy);
        itemRepository.sortItems(items);
    }

    std::cout << "\nSorted Books by " << sortingStrategy->getStrategyName() << ":" << std::endl;
    for (const auto& item : items) {
        item->displayInfo();
    }
}