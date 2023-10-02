#include "BookBuilder.h"
#include "../Items/Book.h"

void BookBuilder::buildTitle(const std::string& title) 
{
        this->title = title;
    }

void BookBuilder::buildCreator(const std::string& author) 
{
    this->author = author;
}

ILibraryItem* BookBuilder::getResult() 
{
    return new Book(title, author);
}