#ifndef LIBRARYITEMREPOSITORY_H
#define LIBRARYITEMREPOSITORY_H

#include "ILibraryItemRepository.h"
#include <unordered_map>
#include <string>

class LibraryItemRepository : public ILibraryItemRepository 
{
    private:
        std::unordered_map<std::string, ILibraryItem*> libraryItems;
        
    public:
        void addLibraryItem(ILibraryItem* item) override;
        ILibraryItem* findLibraryItem(const std::string& title) const override;
};

#endif // LIBRARYITEMREPOSITORY_H
