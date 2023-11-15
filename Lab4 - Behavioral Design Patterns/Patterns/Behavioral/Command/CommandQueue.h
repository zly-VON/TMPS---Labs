#ifndef COMMANDQUEUE_H
#define COMMANDQUEUE_H

#include <deque>
#include "ILibraryCommand.h"

class CommandQueue 
{
private:
    std::deque<ILibraryCommand*> commands;

public:
    void addCommand(ILibraryCommand* command);
    void executeCommands();
    void printBooksInQueue() const;

    std::deque<ILibraryCommand*>::const_iterator begin() const 
    {
        return commands.cbegin();
    }

    std::deque<ILibraryCommand*>::const_iterator end() const 
    {
        return commands.cend();
    }
};

#endif // COMMANDQUEUE_H
