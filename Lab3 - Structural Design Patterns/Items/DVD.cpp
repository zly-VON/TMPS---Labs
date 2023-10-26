#include "DVD.h"
#include <iostream>

DVD::DVD(const std::string& title, const std::string& director, const std::string& dateOfRelease) 
    : title(title), director(director), dateOfRelease(dateOfRelease) {}

void DVD::displayInfo() const 
{
    std::cout << std:: endl;
    std::cout << "DVD: " << title << " directed by " << director << std::endl;
}

void DVD::displayFullInfo() const 
{
    std::cout << std:: endl;
    std::cout << "Book: " << title << " by " << director << std::endl;
    std::cout << "Date of release:  " << dateOfRelease << std::endl;
}

std::string DVD::getTitle() const 
{
    return title;
}

std::string DVD::getAuthor() const 
{
    return director;
}

ILibraryItemPrototype* DVD::clone() const
{
    return new DVD(*this);
}