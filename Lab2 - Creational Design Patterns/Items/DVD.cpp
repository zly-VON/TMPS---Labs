#include "DVD.h"
#include <iostream>

DVD::DVD(const std::string& title, const std::string& director) : title(title), director(director) {}

void DVD::displayInfo() const 
{
    std::cout << "DVD: " << title << " directed by " << director << std::endl;
}

std::string DVD::getTitle() const 
{
    return title;
}

ILibraryItemPrototype* DVD::clone() const
{
    return new DVD(*this);
}