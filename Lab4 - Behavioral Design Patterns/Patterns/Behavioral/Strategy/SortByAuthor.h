// SortByAuthor.h
#ifndef SORTBYAUTHOR_H
#define SORTBYAUTHOR_H

#include "IStrategy.h"

class SortByAuthor : public IStrategy 
{
public:
    std::string getStrategyName() const override;
    void sort(std::vector<ILibraryItem*>& items) const override;
};

#endif // SORTBYAUTHOR_H
