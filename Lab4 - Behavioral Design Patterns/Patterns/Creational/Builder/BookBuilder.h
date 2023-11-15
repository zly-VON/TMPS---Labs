#ifndef BOOKBUILDER_H
#define BOOKBUILDER_H

#include "ILibraryItemBuilder.h"

class BookBuilder : public ILibraryItemBuilder 
{
private:
    std::string title;
    std::string author;
    std::string dateOfRelease;

public:
    void buildTitle(const std::string& title) override;
    void buildCreator(const std::string& author) override;
    void buildDate(const std::string& dateOfRelease) override;
    ILibraryItem* getResult() override;
};

#endif // BOOKBUILDER_H