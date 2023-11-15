#ifndef ISTRATEGY_H
#define ISTRATEGY_H

#include <vector>
#include "../../../Items/ILibraryItem.h"

class IStrategy {
public:
    virtual std::string getStrategyName() const = 0;
    virtual void sort(std::vector<ILibraryItem*>& items) const = 0;
    virtual ~IStrategy() {}
};

#endif // ISTRATEGY_H
