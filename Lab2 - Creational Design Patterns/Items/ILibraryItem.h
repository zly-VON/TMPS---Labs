#ifndef ILIBRARYITEM_H
#define ILIBRARYITEM_H

#include <string>

class ILibraryItem 
{
    public:
        virtual void displayInfo() const = 0;
        virtual void displayFullInfo() const = 0;
        virtual std::string getTitle() const = 0;
        // virtual ~ILibraryItem() {}
};

#endif // ILIBRARYITEM_H
