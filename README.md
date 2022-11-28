### Formatter

Header-only class for filling strings with formatted arguments (C++11).   
The format specifier is '%?'. Arguments are output into string in the same way as into 'std::cout'.  
It is possible to manipulate with format flags and settings for output via following methods:
Flags, Precision, Imbue, SetF, UnSetF (analogues of flags, precision, imbue, setf, and unsetf for ios_base)  

#### Example:

```cpp
#include <iostream>
#include <list>
#include <map>
#include "format_util.h"

struct X {}; // does not have operator<<

struct Y {}; // has operator<<
std::ostream& operator<<(std::ostream& os, const Y&)
{
    os << "Type Y";
    return os;
}

int main()
{
    Formatter formatter;

    std::cout << formatter.Format("Number: %?, string: %?", 100.1, "abc") << std::endl;

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

    return 0;
}
```

##### Output result:
```console
Number: 100.1, string: abc
Integer value: 10, double value: 20.5, wrong odd arguments: ?, ?, ?
List of 3 elements: [apple, pear, banana]
Map of 3 elements: [{2 : true}, {4.5 : false}, {8 : true}]
Unknown type is shown as '?', known type example: 'Type Y'
```

