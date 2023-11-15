#ifndef ILIBRARYITEMPROTOTYPE_H
#define ILIBRARYITEMPROTOTYPE_H

class ILibraryItemPrototype {
public:
    virtual ILibraryItemPrototype* clone() const = 0;
    virtual ~ILibraryItemPrototype() {}
};

#endif // ILIBRARYITEMPROTOTYPE_H