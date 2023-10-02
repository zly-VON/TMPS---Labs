#ifndef DVD_H
#define DVD_H

#include "ILibraryItem.h"
#include "../Prototype/ILibraryItemPrototype.h"
#include <string>

class DVD : public ILibraryItem, public ILibraryItemPrototype
{
private:
    std::string title;
    std::string director;

public:
    DVD(const std::string& title, const std::string& director);
    void displayInfo() const override;
    std::string getTitle() const override;
    ILibraryItemPrototype* clone() const override;
};

#endif // DVD_H