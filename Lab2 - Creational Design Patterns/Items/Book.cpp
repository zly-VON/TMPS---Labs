#include "Book.h"
#include <iostream>

Book::Book(const std::string& title, const std::string& author) 
    : title(title), author(author) {}

void Book::displayInfo() const 
{
    std::cout << "Book: " << title << " by " << author << std::endl;
}

std::string Book::getTitle() const 
{
    return title;
}

ILibraryItemPrototype* Book::clone() const 
{
    return new Book(*this);
}