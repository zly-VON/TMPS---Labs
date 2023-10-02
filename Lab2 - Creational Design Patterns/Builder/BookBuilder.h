#ifndef BOOKBUILDER_H
#define BOOKBUILDER_H

#include "ILibraryItemBuilder.h"

class BookBuilder : public ILibraryItemBuilder 
{
private:
    std::string title;
    std::string author;

public:
    void buildTitle(const std::string& title) override;
    void buildCreator(const std::string& author) override;
    ILibraryItem* getResult() override;
};

#endif // BOOKBUILDER_H