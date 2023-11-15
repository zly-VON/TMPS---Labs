#include "BorrowCommand.h"
#include <iostream>

BorrowCommand::BorrowCommand(ILibraryItem* item, ILibraryMember* member)
    : item(item), member(member) {}

void BorrowCommand::execute() 
{
    member->borrowItem(item);
    std::cout << "BorrowCommand executed. Book: " << item->getTitle();
    std::cout << " borrowed by " << member->getName() << std::endl;
}

std::string BorrowCommand::getBorrowedItemTitle() const 
{
    return item->getTitle();
}