#ifndef BORROWCOMMAND_H
#define BORROWCOMMAND_H

#include "ILibraryCommand.h"
#include "../../../Members/ILibraryMember.h"

class BorrowCommand : public ILibraryCommand 
{
private:
    ILibraryItem* item;
    ILibraryMember* member;

public:
    BorrowCommand(ILibraryItem* item, ILibraryMember* member);
    void execute() override;
    std::string getBorrowedItemTitle() const;
};

#endif // BORROWCOMMAND_H