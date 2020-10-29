#include <iomanip>
#include <iostream>
#include "StringCell.h"

using namespace std;

StringCell::StringCell() : SpreadsheetCell() {
}

StringCell::StringCell(string value) : SpreadsheetCell(value) {
}

void StringCell::printCell(std::ostream &outs) const {
    if (value) {
        outs << "|" << left << setw(numChars) << *value;
    } else {
        outs << "|" << left << setw(numChars) << "";
    }
}

StringCell operator + (const StringCell &lhs, const StringCell &rhs) {
    StringCell returnVal;
    if (lhs.value && rhs.value) {
        returnVal.setValue(*lhs.value + *rhs.value);
    }
    return returnVal;
}

StringCell StringCell::operator += (const StringCell &rhs) {
    if (rhs.value) {
        setValue(*value + *rhs.value);
    }
    return *this;
}

StringCell operator * (unsigned int &r, const StringCell &rhs) {
    StringCell returnVal;
    if (rhs.value) {
        for (int i = 0; i < r; ++i) {
            returnVal.setValue(*returnVal.getValue() + *rhs.value);
        }
    }
    return returnVal;
}

StringCell StringCell::operator *= (unsigned int &r) {
    if (r == 1) {
        return *this;
    } else {
        string toAdd = *this->getValue();
        for (int i = 1; i < r; ++i) {
            setValue(*this->value += toAdd);
        }
    }
    return *this;
}

bool operator == (const StringCell &lhs, const StringCell &rhs) {
    if (lhs.value && rhs.value) {
        return *lhs.value == *rhs.value;
    }
    return false;
}

bool operator != (const StringCell &lhs, const StringCell &rhs) {
    if (lhs.value && rhs.value) {
        return *lhs.value != *rhs.value;
    }
    return false;
}

bool operator < (const StringCell &lhs, const StringCell &rhs) {
    if (lhs.value && rhs.value) {
        return *lhs.value < *rhs.value;
    }
}

bool operator <= (const StringCell &lhs, const StringCell &rhs) {
    if (lhs.value && rhs.value) {
        return *lhs.value <= *rhs.value;
    }
}

bool operator > (const StringCell &lhs, const StringCell &rhs) {
    if (lhs.value && rhs.value) {
        return *lhs.value > *rhs.value;
    }
}

bool operator >= (const StringCell &lhs, const StringCell &rhs) {
    if (lhs.value && rhs.value) {
        return *lhs.value >= *rhs.value;
    }
}
