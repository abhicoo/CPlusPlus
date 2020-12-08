#include <iostream>

using std::cout;

int main() {
  bool a = true;
  if (a) {
    cout << "Hooray! You made it into if statement!"
         << "\n";
  }

  int i = 0;
  while (i < 5) {
    cout << i << "\n";
    i++;
  }

  int n = 1;
  while (n <= 10) {
    if ((n % 2) == 0) {
      cout << n << "\n";
    }
    n++;
  }
}
