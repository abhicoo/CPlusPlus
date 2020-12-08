#include <iostream>
#include <vector>

using std::cout;
using std::vector;

int main() {
  for (int i = 0; i < 5; i++) {
    cout << i << "\n";
  }

  // Looping through vector
  vector<int> a = {1, 2, 3, 4, 5};
  for (int i : a) {
    cout << i << "\n";
  }

  // Looping over 2D vector
  vector<vector<int>> b = {{1, 2}, {3, 4}, {5, 6}};

  for (vector<int> row : b) {
    for (int e : row) {
      cout << e << "\n";
    }
  }
}