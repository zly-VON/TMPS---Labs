#include "LibraryItemRepository.h"

LibraryItemRepository* LibraryItemRepository::instance = nullptr;

LibraryItemRepository::LibraryItemRepository() {}

LibraryItemRepository& LibraryItemRepository::getInstance() 
{
    if (instance == nullptr) {
        instance = new LibraryItemRepository();
    }
    return *instance;
}

void LibraryItemRepository::addLibraryItem(ILibraryItem* item) 
{
    libraryItems[item->getTitle()] = item;
}

ILibraryItem* LibraryItemRepository::findLibraryItem(const std::string& title) const 
{
    auto it = libraryItems.find(title);
    if (it != libraryItems.end()) {
        return it->second;
    }
    return nullptr; // Item not found
}
