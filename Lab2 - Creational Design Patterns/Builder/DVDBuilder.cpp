#include "DVDBuilder.h"
#include "../Items/DVD.h"

void DVDBuilder::buildTitle(const std::string& title) 
{
    this->title = title;
}

void DVDBuilder::buildCreator(const std::string& director) 
{
    this->director = director;
}

ILibraryItem* DVDBuilder::getResult() 
{
    return new DVD(title, director);
}