/* C++ has several container types for storing data.
 * Vectors are one of these which can store sequence of elements fo a single
 * types. It has useful methods for getting the size, testing if vector is empty
 * and adding elements to vector
 */
#include <iostream>
#include <vector>

using std::cout;
using std::vector;

int main() {
  vector<int> v_1 = {0, 1, 2};
  vector<int> v_2 = {3, 4, 5};
  vector<int> v_3;
  v_3 = {6};

  cout << "Size of v_1 is " << v_1.size() << "\n";

  cout << v_1[0] << "\n";
  cout << v_1[1] << "\n";

  // Fails silently for out-of-bound index
  cout << v_1[10] << "\n";

  for (int e : v_2) {
    cout << "Current element of v_2 is " << e << "\n";
  }

  vector<vector<int>> v_2D = {{1, 2}, {3, 4}};

  cout << "Size of v_2D is " << v_2D.size() << "\n";

  for (int e : v_3) {
    cout << "Current element of v_3 is " << e << "\n";
  }

  cout << "Pushing new element to v_3\n";

  v_3.push_back(7);

  for (int e : v_3) {
    cout << "Current element of v_3 is " << e << "\n";
  }

  cout << "Everything Worked"
       << "\n";
}
