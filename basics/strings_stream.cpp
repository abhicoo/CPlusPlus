#include <iostream>
#include <sstream>
#include <string>

using std::cout;
using std::istringstream;
using std::string;

int main() {
  string a = "1 2 3";
  istringstream my_stream(a);

  char n;
  int count = 0;
  while (my_stream >> n) {
    count++;
    cout << "The stream was successful: " << n << "\n";
  }
  cout << "Total count of characters " << count << "\n";
  cout << "The stream has failed"
       << "\n";

  string b("1,2,3,");
  istringstream my_stream_2(b);
  char c;
  char x;
  while (my_stream_2 >> x >> c) {
    cout << "The stream was successful: " << x << " " << c << "\n";
  }
  cout << "The stream has failed"
       << "\n";
}