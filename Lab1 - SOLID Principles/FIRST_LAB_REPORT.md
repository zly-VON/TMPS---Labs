# Topic: *SOLID Principles*
## Author: *Cojuhari Milena*
------
## Objectives:
&ensp; &ensp; 1. Study and understand the SOLID Principles.

&ensp; &ensp; 2. Choose a domain, define its main classes/models/entities and choose the appropriate instantiation mechanisms.

&ensp; &ensp;3. Create a sample project that respects SOLID Principles.


## Used SOLID Principles: 

* SRP - Single Responsibility Principle
* OCP - Open/Closed Principle
* LSP - Liskov Substitution Principle
* ISP - Interface Segregation Principle
* DIP - Dependency Inversion Principle


## Implementation

* My project is the implementation of a sample Library Management System. Its main functionalities represents library operations, item and member management, as register book, borrow/return book. 

* __Single Responsibility Principle__ - Each class in the code has a single responsibility
    * *Book* class: Represents a book and displaying its information
    * *LibraryItemRepository* class: Manages library items
    * *LibraryInfo* class: Stores and displays library information
    * *Library* class: Manages library operations
```
class LibraryInfo {
public:
    LibraryInfo(const std::string& name, const std::string& address);
    void displayInfo() const;

private:
    std::string name;
    std::string address;
};
```

* __Open/Closed Principle__ - The code is designed to be open for extension and closed for modification. 
    * For example, new items (as DVDs, magazines) can be added by creating new classes from the *ILibraryItem* interface, therefore the existing code is not modified.
```
class ILibraryItem {
public:
    virtual void displayInfo() const = 0;
    virtual std::string getTitle() const = 0;
};
```

* __Liskov Substitution Principle__ - Every derived class should be substitutable for its parent class.
    * The *LibraryItemRepository* class implements the *ILibraryItemRepository* interface, being able to replace it without affecting the code.
```
class LibraryItemRepository : public ILibraryItemRepository {
public:
    void addLibraryItem(ILibraryItem* item) override;
    ILibraryItem* findLibraryItem(const std::string& title) const override;

private:
    std::unordered_map<std::string, ILibraryItem*> libraryItems;
};
```

* __Interface Segregation Principle__ - Interfaces are small and with their specific roles.
    * *ILibraryItem* interface contains only methods relevant to show the items information.
```
class ILibraryItem {
public:
    virtual void displayInfo() const = 0;
    virtual std::string getTitle() const = 0;
};
```
```
class ILibraryMember {
public:
    virtual void borrowItem(ILibraryItem* item) = 0;
    virtual void returnItem(ILibraryItem* item) = 0;
};
```

* __Dependency Inversion Principle__ - High-level modules (such as classes or components) should not depend on low-level modules, but should depend on abstractions.
    * The *Library* class depends on an abstraction *ILibraryItemRepository* rather than a concrete implementation *LibraryItemRepository*.
```
class Library {
public:
    Library(const LibraryInfo& info, ILibraryItemRepository& itemRepository);
    void addLibraryItem(ILibraryItem* item);
    ILibraryItem* findLibraryItem(const std::string& title) const;

private:
    LibraryInfo info;
    ILibraryItemRepository& itemRepository;
};
```

* __Screenshot__ - It shows what is displayed after we run the program.
    * As we can see, firstly, there is displayed the library information.
    * Then, some members are registered and some new books are added to the library inventory.
    * Finally, the books recently added to the library are borrowed and returned.

![image1](https://github.com/zly-VON/TMPS---Labs/blob/main/Lab1%20-%20SOLID%20Principles/Assets/image1.png)

## Conclusions / Results
&ensp; &ensp; In conclusion, during this laboratory work I successfully applied SOLID principles to my chosen domain, Library System Managament.The code I created demonstrates the principles through a sample project that shows some main features, registering members, borrowing books, returning books.

&ensp; &ensp; Finally, applying SOLID helped me to create a well-structured and extensible code.
