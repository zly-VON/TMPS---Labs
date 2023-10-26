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


int main() {
    LibraryItemRepository& repo = LibraryItemRepository::getInstance();
    Library myLibrary("My Sample Library", "123 Main St.", repo);

    // Adapter Pattern
    std::cout << "\nADAPTER PATTERN" << std::endl;
    ILibraryItem* book = new Book("Pride and Prejudice", "Jane Austen", "December-31-2002");
    ILibraryItem* book1 = new Book("Sense and Sensibility", "Jane Austen", "April-29-2003");

    myLibrary.addLibraryItem(book);
    myLibrary.addLibraryItem(book1);
    CatalogAdapter catalogAdapter(repo);
    catalogAdapter.searchBooksByTitle("Pride and Prejudice");
    catalogAdapter.searchBooksByAuthor("Jane Austen");

    // Decorator Pattern
    std::cout << "\nDECORATOR PATTERN" << std::endl;
    ILibraryDecorator* taggedBook = new TaggedLibraryItem(book, "Romantic");

    book->displayFullInfo();
    taggedBook->displayFullInfo();

    // Composite Pattern
    std::cout << "\nCOMPOSITE PATTERN" << std::endl;
    ILibraryComponent* book2 = dynamic_cast<ILibraryComponent*>(new Book("The Great Gatsby", "F. Scott Fitzgerald", "July-1-2020"));
    ILibraryComponent* book3 = dynamic_cast<ILibraryComponent*>(new Book("To Kill a Mockingbird", "Harper Lee", "January-1-2002"));

    LibraryCollection* collection = new LibraryCollection("Classic Novels");
    collection->addLibraryComponent(book2);
    collection->addLibraryComponent(book3);

    collection->displayInfo();

    // Proxy Pattern
    std::cout << "\nPROXY PATTERN" << std::endl;
    LibraryMember member("John Doe");
    LibraryProxy itemProxy(book);

    member.borrowItem(&itemProxy);
    itemProxy.markAsBorrowed();

    itemProxy.getAccessCount();

    delete book;
    delete book1;
    delete taggedBook;
    delete collection;

    return 0;
}
