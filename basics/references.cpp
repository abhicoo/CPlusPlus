// References is another name given to an existing variable.
// On left hand side of any variable declaration the & operator can be used to
// declare a reference

#include <iostream>

using std::cout;

int main() {
  int i = 1;
  int &j = i;

  cout << "The value of integer j is: " << j << "\n";

  i = 10;
  cout << "The value of i is changed to: " << i << "\n";
  cout << "The value of j is now: " << j << "\n";

  j = 7;
  cout << "The value of j is changed to: " << j << "\n";
  cout << "The value of i is now: " << i << "\n";
}