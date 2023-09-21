#include "Library/LibraryInfo.h"
#include "Repository/LibraryItemRepository.h"
#include "Items/Book.h"
#include "Members/LibraryMember.h"
#include "Library/Library.h"

int main() {
    LibraryItemRepository itemRepository; // Create a repository for library items

    // Create a LibraryInfo object with library information
    LibraryInfo libraryInfo("My Sample Library", "123 Main St.");

    // Create a Library object and pass in the library info and item repository
    Library myLibrary(libraryInfo, itemRepository);
    // Display library information
    libraryInfo.displayInfo();

    // Add books to the library
    Book book1("The Great Gatsby", "F. Scott Fitzgerald");
    Book book2("Pride and Prejudice", "Jane Austen");

    myLibrary.addLibraryItem(&book1);
    myLibrary.addLibraryItem(&book2);

    // Register members
    LibraryMember member1("John Doe");
    LibraryMember member2("Jane Smith");

    // Borrow and return books
    member1.borrowItem(myLibrary.findLibraryItem("The Great Gatsby"));
    member2.borrowItem(myLibrary.findLibraryItem("Pride and Prejudice"));

    member1.returnItem(myLibrary.findLibraryItem("The Great Gatsby"));

    return 0;
}
