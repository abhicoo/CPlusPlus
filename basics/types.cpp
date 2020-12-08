/* C++ has primitive variable types like int, string, float and otherws
 * In C++ once a variable has been declared it cannot be redeclared in the same
 * scope
 */

#include <iostream>
#include <string>

using std::cout;
using std::string;

int main() {
  int a = 6;
  string s;

  s = "Here is a string";

  cout << a << "\n";
  cout << s << "\n";
}
