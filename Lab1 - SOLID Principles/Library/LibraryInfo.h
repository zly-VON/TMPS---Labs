#ifndef LIBRARYINFO_H
#define LIBRARYINFO_H

#include <string>

class LibraryInfo 
{
    private:
        std::string name;
        std::string address;
        
    public:
        LibraryInfo(const std::string& name, const std::string& address);
        void displayInfo() const;
};

#endif // LIBRARYINFO_H
