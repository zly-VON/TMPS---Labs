#include "Repository/LibraryItemRepository.h"
#include "Items/Book.h"
#include "Items/DVD.h"
#include "Members/LibraryMember.h"
#include "Library/Library.h"
#include "Patterns/Creational/Factory/LibraryItemFactory.h"
#include "Patterns/Creational/Builder/BookBuilder.h"
#include "Patterns/Creational/Builder/DVDBuilder.h"
#include "Patterns/Creational/Builder/LibraryItemDirector.h"
#include "Patterns/Structural/Decorator/TaggedLibraryItem.h"
#include "Patterns/Structural/Composite/LibraryCollection.h"
#include "Patterns/Structural/Proxy/LibraryProxy.h"
#include "Patterns/Structural/Adapter/CatalogAdapter.h"
#include "Patterns/Behavioral/Command/CommandQueue.h"
#include "Patterns/Behavioral/Command/BorrowCommand.h"
#include "Patterns/Behavioral/Strategy/SortByTitle.h"
#include "Patterns/Behavioral/Strategy/SortByAuthor.h"


int main() {
    LibraryItemRepository& repo = LibraryItemRepository::getInstance();
    Library myLibrary("My Sample Library", "123 Main St.", repo);

    LibraryMember member1("John Doe");
    LibraryMember member2("Jane Smith");

    ILibraryItem* book = new Book("Pride and Prejudice", "Jane Austen", "December-31-2002");
    ILibraryItem* book1 = new Book("Sense and Sensibility", "Jane Austen", "April-29-2003");
    ILibraryItem* book2 = new Book("The Great Gatsby", "Francis Scott Fitzgerald", "July-1-2020");
    ILibraryItem* book3 = new Book("To Kill a Mockingbird", "Harper Lee", "January-1-2002");

    std::cout << "\nOBSERVER PATTERN" << std::endl;
    myLibrary.attachObserver(&member1);
    myLibrary.attachObserver(&member2);
    myLibrary.addLibraryItem(book);
    myLibrary.addLibraryItem(book1);
    myLibrary.addLibraryItem(book2);
    myLibrary.addLibraryItem(book3);

    std::cout << "\nCOMMAND PATTERN" << std::endl;
    myLibrary.enqueueCommand(new BorrowCommand(book, &member1));
    myLibrary.enqueueCommand(new BorrowCommand(book1, &member2));
    myLibrary.enqueueCommand(new BorrowCommand(book2, &member1));

    myLibrary.processCommandQueue();

    std::cout << "\nSTRATEGY PATTERN" << std::endl;
    myLibrary.displayLibraryItems();

    myLibrary.displaySortedBooks(new SortByTitle());
    myLibrary.displaySortedBooks(new SortByAuthor());



    delete book;
    delete book1;
    delete book2;
    delete book3;

    return 0;
}
