#include "Repository/LibraryItemRepository.h"
#include "Items/Book.h"
#include "Items/DVD.h"
#include "Members/LibraryMember.h"
#include "Library/Library.h"
#include "Factory/LibraryItemFactory.h"
#include "Builder/BookBuilder.h"
#include "Builder/DVDBuilder.h"
#include "Builder/LibraryItemDirector.h"


int main() {
    // Use Singleton to create the ItemRepository;
    LibraryItemRepository& repo1 = LibraryItemRepository::getInstance();
    LibraryItemRepository& repo2 = LibraryItemRepository::getInstance();

    std::cout << "\nRepository created with Singleton" << std::endl;
    if (&repo1 == &repo2) {
        std::cout << "Only one instance of LibraryItemRepository is created." << std::endl;
    } else {
        std::cout << "Multiple instances of LibraryItemRepository were created (not expected)." << std::endl;
    }

    Library myLibrary("My Sample Library", "123 Main St.");

    // Use the LibraryItemBuilder to create books and DVDs
    LibraryItemDirector director;
    BookBuilder bookBuilder;
    DVDBuilder dvdBuilder;

    ILibraryItem* book1 = director.constructBook(bookBuilder, "The Great Gatsby", "F. Scott Fitzgerald", "July-1-2020");
    ILibraryItem* dvd1 = director.constructDVD(dvdBuilder, "Inception", "Christopher Nolan", "December-7-2010");

    myLibrary.addLibraryItem(book1);
    myLibrary.addLibraryItem(dvd1);

    std::cout << "\nItems created with Builder" << std::endl;
    book1->displayFullInfo();
    dvd1->displayInfo();

    // Use the LibraryItemFactory to create books and DVDs
    ILibraryItem* book2 = LibraryItemFactory::createBook("Pride and Prejudice", "Jane Austen", "December-31-2002");
    ILibraryItem* dvd2 = LibraryItemFactory::createDVD("The Matrix", "Wachowskis", "September-21-1999");

    myLibrary.addLibraryItem(book2);
    myLibrary.addLibraryItem(dvd2);

    std::cout << "\nItems created with Factory" << std::endl;
    book2->displayFullInfo();
    dvd2->displayInfo();

    // Create book and dvd prototype
    ILibraryItemPrototype* bookPrototype = new Book("To Kill a Mockingbird", "Harper Lee", "January-1-2002");
    ILibraryItemPrototype* dvdPrototype = new DVD("Interstellar", "Christopher Nolan", "October-13-2015");

    // Clone prototypes to create new instances
    ILibraryItem* bookClone = dynamic_cast<ILibraryItem*>(bookPrototype->clone());
    ILibraryItem* dvdClone = dynamic_cast<ILibraryItem*>(dvdPrototype->clone());

    myLibrary.addLibraryItem(bookClone);
    myLibrary.addLibraryItem(dvdClone);

    std::cout << "\nItems created with Prototype and clonned" << std::endl;
    bookClone->displayFullInfo();
    dvdClone->displayInfo();

    // LibraryMember member1("John Doe");
    // LibraryMember member2("Jane Smith");

    // member1.borrowItem(myLibrary.findLibraryItem("The Great Gatsby"));
    // member2.borrowItem(myLibrary.findLibraryItem("Pride and Prejudice"));
    // member1.borrowItem(myLibrary.findLibraryItem("Inception"));
    // member2.borrowItem(myLibrary.findLibraryItem("The Matrix"));

    // member1.returnItem(myLibrary.findLibraryItem("The Great Gatsby"));

    // member1.displayBorrowedItems();
    // member2.displayBorrowedItems();

    // Clean up the dynamically allocated memory
    delete book1;
    delete book2;
    delete dvd1;
    delete dvd2;
    delete bookPrototype;
    delete dvdPrototype;
    delete bookClone;
    delete dvdClone;

    return 0;
}
