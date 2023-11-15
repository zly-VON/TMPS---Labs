#ifndef CATALOGADAPTER_H
#define CATALOGADAPTER_H

#include "IExternalCatalog.h"
#include "../../../Items/ILibraryItem.h"
#include "../../../Repository/LibraryItemRepository.h"

class CatalogAdapter : public IExternalCatalog 
{
private:
    ILibraryItemRepository& repository;

public:
    CatalogAdapter(ILibraryItemRepository& repository);

    void searchBooksByTitle(const std::string& title) override;
    void searchBooksByAuthor(const std::string& author) override;
};

#endif // CATALOGADAPTER_H
