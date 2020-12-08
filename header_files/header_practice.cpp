#include "header_practice.h"
#include <iostream>
#include <vector>

using std::cout;
using std::vector;

int IncrementAndComputeVectorSum(vector<int> &v) {
  int total = 0;
  AddOneToEach(v);
  for (int i : v) {
    total += i;
  }
  return total;
}

void AddOneToEach(vector<int> &v) {
  for (int &i : v) {
    i++;
  }
}

int main() {
  vector<int> v{1, 2, 3, 4};
  int total = IncrementAndComputeVectorSum(v);
  cout << "The total is: " << total << "\n";
}