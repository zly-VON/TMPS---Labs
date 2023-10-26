#ifndef LIBRARYITEMREPOSITORY_H
#define LIBRARYITEMREPOSITORY_H

#include "ILibraryItemRepository.h"
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

    public:
        static LibraryItemRepository& getInstance();
        void addLibraryItem(ILibraryItem* item) override;
        std::vector<ILibraryItem*> findLibraryItem(const std::string& title) const override;
        std::vector<ILibraryItem*> findItemByAuthor(const std::string& author) const override;
};

#endif // LIBRARYITEMREPOSITORY_H
