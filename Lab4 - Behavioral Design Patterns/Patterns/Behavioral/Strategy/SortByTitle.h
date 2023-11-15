// SortByNameStrategy.h

#ifndef SORTBYNAME_H
#define SORTBYNAME_H

#include "IStrategy.h"
#include "../../../Items/ILibraryItem.h"
#include <algorithm>

class SortByTitle : public IStrategy 
{
public:
    std::string getStrategyName() const override;
    void sort(std::vector<ILibraryItem*>& items) const override;
};

#endif // SORTBYNAME_H
