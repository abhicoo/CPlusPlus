#include <iostream>
#include <string>

using std::cout;
using std::string;

int MultiplyByTwoPassByValue(int i) {
  i = 2 * i;
  return i;
}

int MultiplyByTwoPassByReference(int &i) {
  i = 2 * i;
  return i;
}

void DoubleString(string &reference) {
  reference = reference + " " + reference;
}

int main() {
  int a = 5;
  cout << "The int a equals: " << a << "\n";
  int b = MultiplyByTwoPassByValue(a);
  cout << "The int b equals: " << b << "\n";
  cout << "The int a still equals: " << a << "\n";

  int c = 10;
  cout << "The int c equals: " << c << "\n";
  int d = MultiplyByTwoPassByReference(c);
  cout << "The int d equals: " << d << "\n";
  cout << "The int c now equals: " << c << "\n";

  string s = "Hello";
  cout << "The string s is: " << s << "\n";
  DoubleString(s);
  cout << "The string s is now: " << s << "\n";
}