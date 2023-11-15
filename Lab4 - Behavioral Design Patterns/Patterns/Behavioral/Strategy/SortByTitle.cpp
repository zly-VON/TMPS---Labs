#include "SortByTitle.h"
#include <algorithm>

std::string SortByTitle::getStrategyName() const {
    return "Title";
}

void SortByTitle::sort(std::vector<ILibraryItem*>& items) const {
    std::sort(items.begin(), items.end(),
              [](const ILibraryItem* a, const ILibraryItem* b) {
                  return a->getTitle() < b->getTitle();
              });
}