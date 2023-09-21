#include "Library.h"

Library::Library(const LibraryInfo& info, ILibraryItemRepository& itemRepository) 
    : info(info), itemRepository(itemRepository) {}

void Library::addLibraryItem(ILibraryItem* item) 
{
    itemRepository.addLibraryItem(item);
    std::cout << "New Book Added to the Repository: " << item->getTitle() << std::endl;
}

ILibraryItem* Library::findLibraryItem(const std::string& title) const 
{
    return itemRepository.findLibraryItem(title);
}
