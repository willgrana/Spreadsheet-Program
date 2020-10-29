

#ifndef SPREADSHEETCELL_STRINGCELL_H
#define SPREADSHEETCELL_STRINGCELL_H

#include <string>
#include "SpreadsheetCell.h"

class StringCell : public SpreadsheetCell<std::string> {

public:
    StringCell();

    explicit StringCell(std::string value);

    void printCell(std::ostream &outs) const override;


    friend StringCell operator + (const StringCell &lhs, const StringCell &rhs);
    StringCell operator += (const StringCell &rhs);
    friend StringCell operator * (unsigned int &r, const StringCell &rhs);
    StringCell operator *= (unsigned int &r);
    friend bool operator == (const StringCell &lhs, const StringCell &rhs);
    friend bool operator != (const StringCell &lhs, const StringCell &rhs);
    friend bool operator < (const StringCell &lhs, const StringCell &rhs);
    friend bool operator <= (const StringCell &lhs, const StringCell &rhs);
    friend bool operator > (const StringCell &lhs, const StringCell &rhs);
    friend bool operator >= (const StringCell &lhs, const StringCell &rhs);


};

#endif //SPREADSHEETCELL_STRINGCELL_H
