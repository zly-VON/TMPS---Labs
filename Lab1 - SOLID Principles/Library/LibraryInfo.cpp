#include "LibraryInfo.h"
#include <iostream>

LibraryInfo::LibraryInfo(const std::string& name, const std::string& address)
    : name(name), address(address) {}

void LibraryInfo::displayInfo() const 
{
    std::cout << "Library Info: " << name << " at " << address << std::endl;
}
