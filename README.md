# Spreadsheet-Cell

Templates and abstract classes and inheritance, oh my!

This is an individual lab. You know the drill: create your own branch with your initials.

## Starter Code

You are given SpreadsheetCell, an abstract template base class that holds an optional template-type field and a number of characters (to print). Look over this class in SpreadsheetCell.h.

You are also given an IntCell class that inherits from SpreadsheetCell\<int\>. Look over the header and .cpp files for IntCell to see the class's functionality.  

## Part I: Inheritance

Write two more subclasses of SpreadsheetCell, each in their own header and .cpp files:
* DoubleCell inherits from SpreadsheetCell\<double\> and has similar functionality as IntCell. It should overload the / operator as well as the others included in IntCell.
    * Note that you also should implement the / operator in the IntCell class, which returns an optional DoubleCell.
    * Note that doubles should print right-aligned to two decimal places (hint: use fixed and setprecision).
* StringCell inherits from SpreadsheetCell\<string\>. It should overload the +, +=, * with unsigned int (think Python), *=, and the comparison (bool) operators.
    * Note that strings should print left-aligned and should be restricted to fit inside the numChars width.

Test your classes in main.cpp by creating a testing function for each, like the one provided for IntCell.

## Part II: Point to Child Objects

* Declare multiple 2-D vectors of unique pointers, one for each subclass. Push back make_unique pointers to the vectors. Make sure you have multiple rows and columns, as this will highlight the formatted printing!

## Part III: Polymorphism

* Declare a template function that takes a two-dimensional vector of Parent unique pointers by reference.
* Implement the function by calling the print method on the objects passed in. Print an endline after each vector/row.
* Call the function in main multiple times, passing it each vector declared in Part II.
* Observe in awe as the polymorphism allows the different types of cells to print in their custom format!

## Grading

This lab is due on Monday, March 2nd, at 3:30pm.

- [ ] (1 pt) GitHub branch setup. Commit regularly and push to branch.
- [ ] (1 pt) Coding style.
- [ ] (4 pts) Part I.
- [ ] (2 pts) Part II.
- [ ] (2 pts) Part III.

## Extra Credit

For two extra credit points, create a BoolCell class (with overloaded ==, !=, !, &&, and || operators), demonstrate its functionality in a testing function, and include it in the polymorphism demonstration.
