#ifndef LIBRARYPROXY_H
#define LIBRARYPROXY_H

#include "ILibraryProxy.h"
#include "../../../Items/ILibraryItem.h"

class LibraryProxy : public ILibraryProxy 
{
private:
    ILibraryItem* realItem;
    mutable int accessCount;
    bool hasBeenBorrowed;

public:
    LibraryProxy(ILibraryItem* item);
    void displayInfo() const override;
    void displayFullInfo() const override;
    std::string getTitle() const override;
    std::string getAuthor() const override;
    void markAsBorrowed();
    void getAccessCount();
    void logInteraction(const std::string& action) const;
};



#endif // LIBRARYPROXY_H
