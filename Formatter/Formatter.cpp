// Formatter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <map>
#include "../format_util.h"

struct X {}; // dos not have operator<<

struct Y {}; // has operator<<
std::ostream& operator<<(std::ostream& os, const Y&)
{
    os << "Type Y";
    return os;
}

int main()
{
    Formatter formatter;

    std::cout << formatter.Format(u8"Number: %?, string: %?", 100.1, u8"abc") << std::endl;

    int num_i = 10;
    double num_d = 20.5;
    std::string example_num = "Integer value: %?, double value: %?, wrong odd arguments: %?, %?, %?";
    std::cout << formatter.Format(example_num, num_i, num_d) << std::endl;

    std::list<std::string> fruits = { "apple", "pear", "banana" };
    std::cout << formatter.Format("List of %? elements: %?", fruits.size(), fruits) << std::endl;

    std::map<double, bool> map_example = { {2.0, true}, {4.5, false}, {8, true} };
    std::cout << formatter.Format("Map of %? elements: %?", map_example.size(), map_example) << std::endl;

    X x;
    Y y;
    std::cout << formatter.Format("Unknown type is shown as '%?', known type example: '%?'", x, y) << std::endl;
    std::cout << formatter.Format("No args") << std::endl << std::endl;

    return 0;
}
