
#ifndef SPREADSHEETCELL_DOUBLECELL_H
#define SPREADSHEETCELL_DOUBLECELL_H

#include "SpreadsheetCell.h"


class DoubleCell : public SpreadsheetCell<double> {
public:
    /* Constructors */
    DoubleCell();
    explicit DoubleCell(double value);

    /* Override pure virtual method from parent */
    void printCell(std::ostream& outs) const override;


    /* Overloaded operators */
    friend DoubleCell operator + (const DoubleCell &lhs, const DoubleCell &rhs);
    DoubleCell& operator += (const DoubleCell &rhs);
    friend DoubleCell operator - (const DoubleCell &lhs, const DoubleCell &rhs);
    DoubleCell& operator -= (const DoubleCell &rhs);
    friend DoubleCell operator * (const DoubleCell &lhs, const DoubleCell &rhs);
    DoubleCell& operator *= (const DoubleCell &rhs);
    // TODO: After implementing DoubleCell, uncomment and implement the following function
    friend DoubleCell operator / (const DoubleCell &lhs, const DoubleCell &rhs);
    DoubleCell& operator /= (const DoubleCell &rhs);
    friend bool operator == (const DoubleCell &lhs, const DoubleCell &rhs);
    friend bool operator != (const DoubleCell &lhs, const DoubleCell &rhs);
    friend bool operator < (const DoubleCell &lhs, const DoubleCell &rhs);
    friend bool operator <= (const DoubleCell &lhs, const DoubleCell &rhs);
    friend bool operator > (const DoubleCell &lhs, const DoubleCell &rhs);
    friend bool operator >= (const DoubleCell &lhs, const DoubleCell &rhs);

};


#endif //SPREADSHEETCELL_DOUBLECELL_H
