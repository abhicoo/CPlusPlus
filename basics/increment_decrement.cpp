#include <iostream>

using std::cout;

int main() {
  // Post Increment example
  auto i = 5;
  auto c = i++;

  cout << "Post-Increment results"
       << "\n";

  cout << "Value of i " << i << "\n";
  cout << "Value of c " << c << "\n";

  // Pre Increment Example
  i = 1;
  c = ++i;

  cout << "Value of i " << i << "\n";
  cout << "Value of c " << c << "\n";

  // Decrement Example
  i--;
  cout << "Value of i " << i << "\n";
}