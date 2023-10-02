#ifndef DVDBUILDER_H
#define DVDBUILDER_H

#include "ILibraryItemBuilder.h"

class DVDBuilder : public ILibraryItemBuilder 
{
private:
    std::string title;
    std::string director;

public:
    void buildTitle(const std::string& title);
    void buildCreator(const std::string& director);
    ILibraryItem* getResult();
};

#endif // DVDBUILDER_H