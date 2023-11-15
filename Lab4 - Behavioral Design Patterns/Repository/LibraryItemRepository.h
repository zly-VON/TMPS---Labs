#ifndef LIBRARYITEMREPOSITORY_H
#define LIBRARYITEMREPOSITORY_H

#include "ILibraryItemRepository.h"
#include "../Patterns/Behavioral/Strategy/IStrategy.h"
#include <unordered_map>
#include <string>
#include <iostream>
#include <vector>

class LibraryItemRepository : public ILibraryItemRepository 
{
    private:
        std::unordered_map<std::string, ILibraryItem*> libraryItems;
        LibraryItemRepository();
        static LibraryItemRepository* instance;
        IStrategy* sortingStrategy;

    public:
        static LibraryItemRepository& getInstance();
        void addLibraryItem(ILibraryItem* item) override;
        void addItem(ILibraryItem* item);
        std::vector<ILibraryItem*> findLibraryItem(const std::string& title) const override;
        std::vector<ILibraryItem*> findItemByAuthor(const std::string& author) const override;
        std::vector<ILibraryItem*> getAllLibraryItems() const;
        void setSortingStrategy(IStrategy* strategy);
        void sortItems(std::vector<ILibraryItem*>& items) const;
};

#endif // LIBRARYITEMREPOSITORY_H
