// Header files allow related function, method and class declarations to be
// collected in one place. The corresponding defintions can be placed in .cpp
// files. This allows functions to be defined(and declared) in arbitrary order

#include "header_example.h"
#include <iostream>

using std::cout;

void OuterFunction(int x) { InnerFunction(x); }

void InnerFunction(int x) { cout << "The value of integer is: " << x << "\n"; }

int main() { OuterFunction(1); }