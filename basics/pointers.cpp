#include <iostream>

using std::cout;

int main() {
  // Each program stores it contents in computer memory
  // and each chunk of memory has memory address
  // For a given variable, the memory address can be accessed using & sign in
  // front of variable name

  int i = 5;
  int j = 6;

  cout << "The address of i is: " << &i << "\n";
  cout << "The address of j is: " << &j << "\n";

  // At this you might be wondering why the same symbol & can be used
  // to both access memory addresses and also as references.
  // For the & symbol, if it appears on the left side of and equation(when
  // declaring a variable) it means that the variable is declared as reference.
  // If the & appears on right side of an equation or before a previously
  // declared variable, it is used to return memory address.
  // Once a memory address is accessed we can store it using a pointer

  int *pointer_to_i = &i;
  cout << "The variable pointer_to_i is: " << pointer_to_i << "\n";

  // Once we have pointer, we may want to retrieve the object it is pointing to.
  // In this case, * symbol can be used again.
  // This time however it will be used on right hand side of equation or of an
  // already-defined variable This is callled "dereferencing operator"

  cout << "The address of i is: " << &i << "\n";
  cout << "The variable pointer_to_i is: " << pointer_to_i << "\n";
  cout << "The value of the variable pointed to by pointer_to_i is: "
       << *pointer_to_i << "\n";

  i = 7;
  cout << "The new value of variable i is: " << i << "\n";
  cout << "The value of variable pointed to by pointer_to_i is: "
       << *pointer_to_i << "\n";
  cout << "The variable pointer_to_i is: " << pointer_to_i << "\n";
}