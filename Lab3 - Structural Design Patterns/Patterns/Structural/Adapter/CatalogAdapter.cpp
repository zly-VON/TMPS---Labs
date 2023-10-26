#include "CatalogAdapter.h"
#include "iostream"

CatalogAdapter::CatalogAdapter(ILibraryItemRepository& repository) : repository(repository) {}

void CatalogAdapter::searchBooksByTitle(const std::string& title) 
{
     std::vector<ILibraryItem*> booksByTitle = repository.findLibraryItem(title);

    if (!booksByTitle.empty()) {
        std::cout << "\nItems with title '" << title << "' found in the library." << std::endl;
        std::cout << "Repository -> ";
        for (const auto& book : booksByTitle) {
            book->displayInfo();
        }
    } else {
        std::cout << "Items with title '" << title << "' not found in the library." << std::endl;
    }
}

void CatalogAdapter::searchBooksByAuthor(const std::string& author) 
{
    std::vector<ILibraryItem*> booksByAuthor = repository.findItemByAuthor(author);

    if (!booksByAuthor.empty()) {
        std::cout << "\nItems with author '" << author << "' found in the library." << std::endl;
        std::cout << "Repository -> ";
        for (const auto& book : booksByAuthor) {
            book->displayInfo();
        }
    } else {
        std::cout << "Items with title '" << author << "' not found in the library." << std::endl;
    }
}