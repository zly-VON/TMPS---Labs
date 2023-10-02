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

    ILibraryItem* book1 = director.construct(bookBuilder, "The Great Gatsby", "F. Scott Fitzgerald");
    ILibraryItem* dvd1 = director.construct(dvdBuilder, "Inception", "Christopher Nolan");

    // Use the LibraryItemFactory to create books and DVDs
    ILibraryItem* book2 = LibraryItemFactory::createBook("Pride and Prejudice", "Jane Austen");
    ILibraryItem* dvd2 = LibraryItemFactory::createDVD("The Matrix", "Wachowskis");

    // Create book and dvd prototype
    ILibraryItemPrototype* bookPrototype = new Book("To Kill a Mockingbird", "Harper Lee");
    ILibraryItemPrototype* dvdPrototype = new DVD("Interstellar", "Christopher Nolan");

    // Clone prototypes to create new instances
    ILibraryItem* bookClone = dynamic_cast<ILibraryItem*>(bookPrototype->clone());
    ILibraryItem* dvdClone = dynamic_cast<ILibraryItem*>(dvdPrototype->clone());

    myLibrary.addLibraryItem(book1);
    myLibrary.addLibraryItem(dvd1);
    myLibrary.addLibraryItem(book2);
    myLibrary.addLibraryItem(dvd2);
    myLibrary.addLibraryItem(bookClone);
    myLibrary.addLibraryItem(dvdClone);

    book1->displayInfo();
    dvd1->displayInfo();
    book2->displayInfo();
    dvd2->displayInfo();
    bookClone->displayInfo();
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
