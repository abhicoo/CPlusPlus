#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::vector;

void PrintString(string a, string b) { cout << a << " " << b << "\n"; }

int sum(vector<int> v) {
  int result = 0;
  for (int e : v) {
    result += e;
  }
  return result;
}

int AddTwoNumbers(int a, int b) { return a + b; }

int main() {
  auto a = 1;
  auto b = 2;
  auto c = AddTwoNumbers(a, b);
  cout << c << "\n";

  vector<int> v = {1, 2, 3};

  auto d = sum(v);
  cout << d << "\n";

  string s1 = "C++ is ";
  string s2 = "super awesome";

  PrintString(s1, s2);
}