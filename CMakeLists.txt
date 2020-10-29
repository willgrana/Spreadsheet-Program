cmake_minimum_required(VERSION 3.8)
project(SpreadsheetCell)

set(CMAKE_CXX_STANDARD 14)

add_executable(SpreadsheetCell main.cpp IntCell.cpp StringCell.cpp DoubleCell.cpp)