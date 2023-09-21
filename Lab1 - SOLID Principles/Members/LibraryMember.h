#ifndef LIBRARYMEMBER_H
#define LIBRARYMEMBER_H

#include "ILibraryMember.h"
#include <string>
#include <vector>

class LibraryMember : public ILibraryMember 
{
    private:
        std::string name;
        std::vector<ILibraryItem*> borrowedItems;
        
    public:
        LibraryMember(const std::string& name);
        void borrowItem(ILibraryItem* item) override;
        void returnItem(ILibraryItem* item) override;
        void displayInfo() const;
};

#endif // LIBRARYMEMBER_H
