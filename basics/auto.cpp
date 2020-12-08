// For automatic type inference we can use auto keyword
#include <iostream>
#include <vector>

using std::cout;

int main() {
  auto i = 5;
  auto v = {3, 4, 5};
  cout << "Variable declared and initialized without explicilty stating type!"
       << "\n";
}