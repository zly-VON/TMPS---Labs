#ifndef LIBRARYMEMBER_H
#define LIBRARYMEMBER_H

#include "ILibraryMember.h"
#include "../Patterns/Behavioral/Observer/ILibraryObserver.h"
#include "../Patterns/Behavioral/Command/CommandQueue.h"
#include <string>
#include <vector>

class LibraryMember : public ILibraryMember, public ILibraryObserver
{
    private:
        std::string name;
        std::vector<ILibraryItem*> borrowedItems;
        CommandQueue commandQueue;
        
    public:
        LibraryMember(const std::string& name);
        void borrowItem(ILibraryItem* item) override;
        void returnItem(ILibraryItem* item) override;
        void displayBorrowedItems() const override;
        std::string getName() const override;
        void displayInfo() const;
        void update() override;
        void executeBorrowCommand(ILibraryItem* item);
        void enqueueCommand(ILibraryCommand* command);
};

#endif // LIBRARYMEMBER_H
