#ifndef IEXTERNALCATALOG_H
#define IEXTERNALCATALOG_H

#include <string>

class IExternalCatalog 
{
public:
    virtual void searchBooksByTitle(const std::string& title) = 0;
    virtual void searchBooksByAuthor(const std::string& author) = 0;
};

#endif // IEXTERNALCATALOG_H
