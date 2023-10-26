#ifndef TAGGEDLIBRARYITEM_H
#define TAGGEDLIBRARYITEM_H

#include "../../../Items/ILibraryItem.h"
#include "ILibraryDecorator.h"

class TaggedLibraryItem : public ILibraryDecorator 
{
private:
    ILibraryItem* item;
    std::string tag;

public:
    TaggedLibraryItem(ILibraryItem* item, const std::string& tag);
    void displayInfo() const override;
    void displayFullInfo() const override;
    std::string getTitle() const override;
    std::string getAuthor() const override;
};

#endif // TAGGEDLIBRARYITEM_H