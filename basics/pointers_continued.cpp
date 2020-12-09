#include <iostream>
#include <vector>

using std::cout;
using std::vector;

void AddOne(int *j) {
  cout << "The value of j is now: " << j << "\n";
  int k = 6;
  j = &k;
  cout << "The value of j is now: " << j << "\n";
  (*j)++;
  cout << "The value of k is now: " << k << "\n";
}

// We can also return a pointer from function.
// We must be careful that the object being pointed to doesnot go out of scope
// when the function finished executing. If the object goes out of scope, the
// memory address being pointed to might then be used for something else.
int *ReturnPointer(int &j) {
  j++;
  cout << &j << "\n";
  return &j;
}

int main() {
  // Although the type of object being pointed to must be included in pointer
  // declaration pointers hold same kind of value for every object just a memory
  // address to where object is stored;
  vector<int> v = {1, 2, 3, 4, 5};

  // Declare and initialize a pointer to address of v here:
  vector<int> *pv = &v;

  for (int a : v) {
    cout << a << "\n";
  }

  // Deference your pointer to v and print the int at index 0;
  vector<int> dpv = *pv;
  cout << dpv[0] << "\n";

  cout << "******************************"
       << "\n";

  int i = 1;
  cout << "The value of i is: " << i << "\n";

  int *pi = &i;
  cout << "The value of pi is now: " << pi << "\n";
  AddOne(pi);
  cout << "The value of i is now: " << i << "\n";
  cout << "The value of pi is now: " << pi << "\n";

  cout << "********************************"
       << "\n";

  int k = 2;
  cout << "The value of k is: " << k << "\n";
  int *my_pointer = ReturnPointer(k);
  cout << "The value of k is now: " << k << "\n";
  cout << "The address of k is: " << &k << "\n";
  cout << "The value of my_pointer is: " << my_pointer << "\n";
}