#ifndef LIBRARY_H
#define LIBRARY_H

#include "../Repository/LibraryItemRepository.h"
#include "../Patterns/Behavioral/Observer/ILibraryObserver.h"
#include "../Patterns/Behavioral/Command/CommandQueue.h"
#include "../Patterns/Behavioral/Strategy/IStrategy.h"
#include <iostream>
#include <vector>

class Library : public ILibraryObserver 
{
    private:
        std::string name;
        std::string address;
        LibraryItemRepository& itemRepository;
        std::vector<ILibraryObserver*> observers;
        CommandQueue commandQueue;
        IStrategy* sortingStrategy;

    public:
        Library(const std::string& name, const std::string& address, LibraryItemRepository& repo);
        void displayInfo() const;
        void displayLibraryItems() const;
        void addLibraryItem(ILibraryItem* item);
        void attachObserver(ILibraryObserver* observer);
        void notifyObservers();
        void update() override;
        void enqueueCommand(ILibraryCommand* command);
        void processCommandQueue();
        void displaySortedBooks(IStrategy* sortingStrategy) const;
};

#endif // LIBRARY_H
