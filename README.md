# Array ADT

- The goal of this programming assignment is to provide a refresher for programming abstract data types (ADTs) in C++. The class provides functionality for creating, manipulating, and managing arrays of characters. It includes features such as resizing, finding elements, equality testing, filling, reversing, and slicing.

## Files Included

- Array.h: Header file defining the Array class and its methods.
- Array.cpp: Implementation file for the Array class methods.
- driver.cpp: Driver program to test the functionality of the Array class.
- Array.inl: Inline file containing the implementation of additional helper methods for the Array class.

### Build Configuration Files:
- Array.mpc : MPC (Makefile Project Creator) configuration file for the project.
- Makefile.Array : Makefile for building the project.

## Build Instructions
- To build the project, use the provided build configuration files:
  make all

## How to Use

1. Include the Array header file in your C++ code.
2. Instantiate the class with the desired data type.
3. Use the provided methods to manipulate and work with the data structure.

Example:

```cpp
#include "Array.h"

int main() {
    // Create an array with a length of 5 and fill with 'A'
    Array myArray(5, 'A');

    // Print the size of the array
    std::cout << "Array size: " << myArray.size() << std::endl;

    // Access and modify elements using indexing
    myArray[2] = 'B';

    // Resize the array
    myArray.resize(8);

    // Print the modified array
    std::cout << "Modified Array: " << myArray << std::endl;

    return 0;
}
