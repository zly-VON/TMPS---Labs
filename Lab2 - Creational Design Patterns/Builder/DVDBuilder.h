#ifndef DVDBUILDER_H
#define DVDBUILDER_H

#include "ILibraryItemBuilder.h"

class DVDBuilder : public ILibraryItemBuilder 
{
private:
    std::string title;
    std::string director;
    std::string dateOfRelease;

public:
    void buildTitle(const std::string& title) override;
    void buildCreator(const std::string& director) override;
    void buildDate(const std::string& dateOfRelease) override;
    ILibraryItem* getResult();
};

#endif // DVDBUILDER_H