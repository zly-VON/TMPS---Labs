// SortByAuthor.cpp
#include "SortByAuthor.h"
#include <algorithm>

std::string SortByAuthor::getStrategyName() const {
    return "Author";
}

void SortByAuthor::sort(std::vector<ILibraryItem*>& items) const {
    std::sort(items.begin(), items.end(),
              [](const ILibraryItem* a, const ILibraryItem* b) {
                  return a->getAuthor() < b->getAuthor();
              });
}
