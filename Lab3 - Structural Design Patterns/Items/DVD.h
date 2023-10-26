#ifndef DVD_H
#define DVD_H

#include "ILibraryItem.h"
#include "../Patterns/Creational/Prototype/ILibraryItemPrototype.h"
#include <string>

class DVD : public ILibraryItem, public ILibraryItemPrototype
{
private:
    std::string title;
    std::string director;
    std::string dateOfRelease;

public:
    DVD(const std::string& title, const std::string& director, const std::string& dateOfRelease);
    void displayInfo() const override;
    void displayFullInfo() const override;
    std::string getTitle() const override;
    std::string getAuthor() const override;
    ILibraryItemPrototype* clone() const override;
};

#endif // DVD_H