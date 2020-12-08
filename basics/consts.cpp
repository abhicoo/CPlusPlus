#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

// A common usage of const is to guard against accidentally changing a variable,
// especially when it is passed-by-reference as function argument
int sum(const vector<int> &v) {
  int sum = 0;
  for (int e : v) {
    sum += e;
  }
  // Below code will throw error since we are trying to modify constant variable
  // v.push_back(5);
  return sum;
}

int main() {
  int i;
  cout << "Enter a integer value for i: ";
  cin >> i;
  const int j = 2 * i; // j can only be evaluated at run time.
  // But I promise not to change it after it is initialized
  constexpr int k = 3; // k, in contrast can be evaluated at compile time
  cout << "j = " << j << "\n";
  cout << "k = " << k << "\n";

  // l can only be evaluated at run time.
  // constexpr must be evaluated at compile time
  // So the code below will throw error
  // constexpr int l = 2 * i;

  vector<int> v{0, 1, 2, 3, 4, 5};
  cout << sum(v) << "\n";
}