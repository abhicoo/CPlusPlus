#include <fstream>
#include <iostream>
#include <string>

using std::cout;
using std::ifstream;
using std::string;

int main() {
  ifstream my_file;
  my_file.open("1.board");

  if (my_file) {
    cout << "The file stream has been created"
         << "\n";
    string line;
    while (getline(my_file, line)) {
      cout << line << "\n";
    }
  }
}