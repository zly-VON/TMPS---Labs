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

std::vector<ILibraryItem*> LibraryItemRepository::findLibraryItem(const std::string& title) const 
{
    std::vector<ILibraryItem*> itemsByTitle;

    for (const auto& entry : libraryItems) {
        ILibraryItem* item = entry.second;
        if (item->getTitle() == title) {
            itemsByTitle.push_back(item);
        }
    }

    return itemsByTitle;
}

std::vector<ILibraryItem*> LibraryItemRepository::findItemByAuthor(const std::string& author) const 
{
    std::vector<ILibraryItem*> itemsByAuthor;

    for (const auto& entry : libraryItems) {
        ILibraryItem* item = entry.second;
        if (item->getAuthor() == author) {
            itemsByAuthor.push_back(item);
        }
    }

    return itemsByAuthor;
}