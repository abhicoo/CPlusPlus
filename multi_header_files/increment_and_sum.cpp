#include "increment_and_sum.h"
#include "vect_add_one.h"

int IncrementAndComputeVectorSum(vector<int> v) {
  int total = 0;
  AddOneToEach(v);
  for (int i : v) {
    total += i;
  }
  return total;
}
