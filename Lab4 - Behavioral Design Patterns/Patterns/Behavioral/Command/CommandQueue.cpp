#include "CommandQueue.h"
#include "BorrowCommand.h"
#include <iostream>

void CommandQueue::addCommand(ILibraryCommand* command) 
{
    commands.push_back(command);
}

void CommandQueue::executeCommands() 
{
    printBooksInQueue();
    while (!commands.empty()) {
        ILibraryCommand* command = commands.front();
        command->execute();
        delete command;
        commands.pop_front();

        printBooksInQueue();
    }
}

void CommandQueue::printBooksInQueue() const 
{
    std::cout << "\nBooks in the command queue: " << std::endl;
    if (commands.empty()) 
    {
        std::cout << "No books in the queue." << std::endl;
    } else 
    {
        for (const ILibraryCommand* command : *this) 
        {
            const BorrowCommand* borrowCommand = dynamic_cast<const BorrowCommand*>(command);
            if (borrowCommand) 
            {
                std::cout << borrowCommand->getBorrowedItemTitle() << " " << std::endl;
            }
        }
    std::cout << std::endl;
    }
}