#include "DVDBuilder.h"
#include "../../../Items/DVD.h"

void DVDBuilder::buildTitle(const std::string& title) 
{
    this->title = title;
}

void DVDBuilder::buildCreator(const std::string& director) 
{
    this->director = director;
}

void DVDBuilder::buildDate(const std::string& dateOfRelease) 
{
    this->dateOfRelease = dateOfRelease;
}

ILibraryItem* DVDBuilder::getResult() 
{
    return new DVD(title, director, dateOfRelease);
}