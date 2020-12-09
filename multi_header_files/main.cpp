#include "increment_and_sum.h"
#include <iostream>

using std::cout;

int main() {
  vector<int> v{1, 2, 3, 4};
  int total = IncrementAndComputeVectorSum(v);
  cout << "The total is: " << total << "\n";
}