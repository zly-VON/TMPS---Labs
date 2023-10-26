#include "Book.h"
#include <iostream>

Book::Book(const std::string& title, const std::string& author, const std::string& dateOfRelease) 
    : title(title), author(author), dateOfRelease(dateOfRelease) {}

void Book::displayInfo() const 
{
    std::cout << std:: endl;
    std::cout << "Book: " << title << " by " << author << std::endl;
}

void Book::displayFullInfo() const 
{
    std::cout << std:: endl;
    std::cout << "Book: " << title << " by " << author << std::endl;
    std::cout << "Date of release: " << dateOfRelease << std::endl;
}

std::string Book::getTitle() const 
{
    return title;
}

std::string Book::getAuthor() const 
{
    return author;
}

ILibraryItemPrototype* Book::clone() const 
{
    return new Book(*this);
}