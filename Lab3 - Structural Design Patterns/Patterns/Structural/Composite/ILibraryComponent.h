#ifndef ILIBRARYCOMPONENT_H
#define ILIBRARYCOMPONENT_H

#include <iostream>

class ILibraryComponent 
{
public:
    virtual void displayInfo() const = 0;
    virtual std::string getTitle() const = 0;
};

#endif // ILIBRARYCOMPONENT_H