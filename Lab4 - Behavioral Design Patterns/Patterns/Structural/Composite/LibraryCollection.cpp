#include "LibraryCollection.h"
#include <iostream>

LibraryCollection::LibraryCollection(const std::string& name) : name(name) {}

void LibraryCollection::displayInfo() const 
{
    std::cout << "\n(Library Collection) " << name << ":" << std::endl;
    for (const auto& child : children) {
        child->displayInfo();
    }
}

std::string LibraryCollection::getTitle() const 
{
    return name;
}

void LibraryCollection::addLibraryComponent(ILibraryComponent* component) 
{
    children.push_back(component);
}

LibraryCollection::~LibraryCollection() 
{
    for (auto& child : children) {
        delete child; 
    }
}

