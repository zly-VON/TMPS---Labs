#include "TaggedLibraryItem.h"
#include <iostream>

TaggedLibraryItem::TaggedLibraryItem(ILibraryItem* item, const std::string& tag)
    : item(item), tag(tag) {}

void TaggedLibraryItem::displayInfo() const 
{
    item->displayFullInfo();
}

void TaggedLibraryItem::displayFullInfo() const 
{
    item->displayFullInfo();
    std::cout << "Tag: " << tag << std::endl;
}

std::string TaggedLibraryItem::getTitle() const 
{
    return item->getTitle();
}

std::string TaggedLibraryItem::getAuthor() const 
{
    return item->getAuthor();
}