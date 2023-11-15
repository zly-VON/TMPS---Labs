#ifndef LIBRARYCOLLECTION_H
#define LIBRARYCOLLECTION_H

#include "ILibraryComponent.h"
#include "ILibraryCollection.h"
#include "vector"

class LibraryCollection : public ILibraryComponent, public ILibraryCollection 
{
private:
    std::string name;
    std::vector<ILibraryComponent*> children;

public:
    LibraryCollection(const std::string& name);
    void displayInfo() const override;
    std::string getTitle() const override;
    void addLibraryComponent(ILibraryComponent* component);
    ~LibraryCollection();
};

#endif // LIBRARYCOLLECTION_H