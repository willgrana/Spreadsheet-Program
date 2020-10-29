#include "SpreadsheetCell.h"
#include "IntCell.h"
#include <iostream>
#include <vector>
#include "DoubleCell.h"
#include "StringCell.h"
using namespace std;

void testIntCell();
void testDoubleCell();
void testStringCell();

template<typename T>
void printCell(vector<vector<unique_ptr<SpreadsheetCell<T>>>> &tVec);

int main() {
    testIntCell();
    testDoubleCell();
    testStringCell();

    vector<vector<unique_ptr<SpreadsheetCell<int>>>> cells;
    vector<unique_ptr<SpreadsheetCell<int>>> row;
    row.push_back(make_unique<IntCell>());
    row.push_back(make_unique<IntCell>(300000));
    cells.push_back(move(row));
    row.clear();
    row.push_back(make_unique<IntCell>(-5));
    row.push_back(make_unique<IntCell>(90));
    cells.push_back(move(row));
    // TODO: Create a function to print the 2-D vector
    // It should work for all subclasses of SpreadsheetCell.
    //printCells(cells);

    vector<vector<unique_ptr<SpreadsheetCell<double>>>> c1;
    vector<unique_ptr<SpreadsheetCell<double>>> r1;
    r1.push_back(make_unique<DoubleCell>());
    r1.push_back(make_unique<DoubleCell>(1000000.7));
    c1.push_back(move(r1));
    r1.clear();
    r1.push_back(make_unique<DoubleCell>(12.111));
    r1.push_back(make_unique<DoubleCell>(-65.8485));
    c1.push_back(move(r1));
    r1.clear();
    r1.push_back(make_unique<DoubleCell>(-2110));
    r1.push_back(make_unique<DoubleCell>(34.098));
    c1.push_back(move(r1));
    r1.clear();
    r1.push_back(make_unique<DoubleCell>(-43.15));
    r1.push_back(make_unique<DoubleCell>(854.987));
    c1.push_back(move(r1));
    printCell(c1);

    vector<vector<unique_ptr<SpreadsheetCell<string>>>> c2;
    vector<unique_ptr<SpreadsheetCell<string>>> r2;
    r2.push_back(make_unique<StringCell>("big"));
    r2.push_back(make_unique<StringCell>("times"));
    c2.push_back(move(r2));
    r2.clear();
    r2.push_back(make_unique<StringCell>("me"));
    r2.push_back(make_unique<StringCell>("you"));
    c2.push_back(move(r2));
    printCell(c2);

    return 0;
}

template<typename T>
void printCell(vector<vector<unique_ptr<SpreadsheetCell<T>>>> &tVec) {
    for (int i = 0; i < tVec.size(); ++i) {
        cout << endl;
        for (int x = 0; x < tVec[i].size(); ++x) {
            tVec[i][x]->printCell(cout);
        }
    }
    cout << endl;
}


void testDoubleCell() {

    DoubleCell d1;
    DoubleCell d2(5.56);

    DoubleCell d3 = d1 + d2;
    DoubleCell d4;

    d4.setValue(4);
    d4 += d2;
    if (d4.getValue() != 9.56) {
        cout << "FAILED += test case" << endl;
    }
    d2 -= d4;
    if (d2.getValue() != 1.56) {
        cout << "FAILED -= nullopt test case" << endl;
    }
    d2 *= d4;
    if (d2.getValue() != 22.24) {
        cout << "FAILED *= test case" << endl;
    }
    d4 /= DoubleCell(10);
    if (d4.getValue() != 0.4) {
        cout << "FAILED /= test case" << endl;
    }
    DoubleCell d5;
    d5.setValue(4);
    cout << "Testing DoubleCell print" << endl;
    d2.printCell(cout);
    d4.printCell(cout);
    cout << endl;
    d2.setNumChars(5);
    d2.printCell(cout);
    cout << endl << "End testing DoubleCell print and setNumChars methods" << endl;

    cout << endl << boolalpha;
    if (d5 == d4) {
        cout << "FAILED == test case" << endl;
    }
    if (!(d4 != d2)) {
        cout << "FAILED != test case" << endl;
    }
    if (!(d4 < d2)) {
        cout << "FAILED < test case" << endl;
    }
    if (!(d4 <= d5)) {
        cout << "FAILED <= test case" << endl;
    }
    if (d2 > d4) {
        cout << "FAILED > test case" << endl;
    }
    if (d2 >= d4) {
        cout << "FAILED >= test case" << endl;
    }
    d1.setValue(7.5);
    if (!(d4 == d5)) {
        cout << "FAILED == test case 2" << endl;
    }
}

void testStringCell() {
    StringCell i1;
    StringCell i2("5.4");

    StringCell i3 = i1 + i2;
    if (i3.getValue()) {
        cout << "FAILED nullopt + test case" << endl;
    }
    if (i3.getValue()) {
        cout << "FAILED nullopt - test case" << endl;
    }
    if (i3.getValue()) {
        cout << "FAILED nullopt * test case" << endl;
    }
    i3.setValue("4");
    i3 += i2;

    cout << "Testing StringCell print and setNumChars methods" << endl;
    i1.printCell(cout);
    i2.printCell(cout);
    cout << endl;
    i1.setNumChars(5);
    i1.printCell(cout);
    cout << endl << "End testing StringCell print and setNumChars methods" << endl;

    cout << endl << boolalpha;
    if (i1 == i2) {
        cout << "FAILED == test case" << endl;
    }
    i1.setValue("test");
    i2.setValue("testa");
    if (!(i1 != i2)) {
        cout << "FAILED != test case" << endl;
    }
    if (!(i1 < i2)) {
        cout << "FAILED < test case" << endl;
    }
    if (!(i1 <= i2)) {
        cout << "FAILED <= test case" << endl;
    }
    if (i1 > i2) {
        cout << "FAILED > test case" << endl;
    }
    if (i1 >= i2) {
        cout << "FAILED >= test case" << endl;
    }
    i1.setValue("testa");
    if (!(i1 == i2)) {
        cout << "FAILED == test case 2" << endl;
    }
    if (!(i1 <= i2)) {
        cout << "FAILED <= test case 2" << endl;
    }
    if (!(i1 >= i2)) {
        cout << "FAILED >= test case 2" << endl;
    }
}

void testIntCell() {

    IntCell i1;
    IntCell i2(7.9);

    IntCell i3 = i1 + i2;
    if (i3.getValue()) {
        cout << "FAILED nullopt + test case" << endl;
    }
    i3 = i1 - i2;
    if (i3.getValue()) {
        cout << "FAILED nullopt - test case" << endl;
    }
    i3 = i2 * i1;
    if (i3.getValue()) {
        cout << "FAILED nullopt * test case" << endl;
    }
    i3.setValue(4);
    i3 += i2;
    if (i3.getValue() != 11) {
        cout << "FAILED += test case" << endl;
    }
    i3 -= i1;
    if (i3.getValue() != 11) {
        cout << "FAILED -= nullopt test case" << endl;
    }
    i3 *= i2;
    if (i3.getValue() != 77) {
        cout << "FAILED *= test case" << endl;
    }
    i3 /= IntCell(11);
    if (i3.getValue() != 7) {
        cout << "FAILED /= test case" << endl;
    }

    i1.setValue(4);
    cout << "Testing IntCell print and setNumChars methods" << endl;
    i1.printCell(cout);
    i2.printCell(cout);
    cout << endl;
    i1.setNumChars(5);
    i1.printCell(cout);
    cout << endl << "End testing IntCell print and setNumChars methods" << endl;

    cout << endl << boolalpha;
    if (i1 == i2) {
        cout << "FAILED == test case" << endl;
    }
    if (!(i1 != i2)) {
        cout << "FAILED != test case" << endl;
    }
    if (!(i1 < i2)) {
        cout << "FAILED < test case" << endl;
    }
    if (!(i1 <= i2)) {
        cout << "FAILED <= test case" << endl;
    }
    if (i1 > i2) {
        cout << "FAILED > test case" << endl;
    }
    if (i1 >= i2) {
        cout << "FAILED >= test case" << endl;
    }
    i1.setValue(7);
    if (!(i1 == i2)) {
        cout << "FAILED == test case 2" << endl;
    }
    if (!(i1 <= i2)) {
        cout << "FAILED <= test case 2" << endl;
    }
    if (!(i1 >= i2)) {
        cout << "FAILED >= test case 2" << endl;
    }
}