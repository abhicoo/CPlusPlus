/* Suppose we are writing a program to model several cars. In your program, you
want to keep track of each car's color and the distance car has travelled and
you want to increment this distance and print out car properites. One way to
accomplish this is
*/
#include <iostream>
#include <string>

using std::cout;
using std::string;

int main() {
  string car_1_color = "green";
  string car_2_color = "red";
  string car_3_color = "blue";

  int car_1_distance = 0;
  int car_2_distance = 0;
  int car_3_distance = 0;

  car_1_distance++;

  cout << "The distance that the " << car_1_color
       << " car 1 has traveled is: " << car_1_distance << "\n";
  cout << "The distance that the " << car_2_color
       << " car 2 has traveled is: " << car_2_distance << "\n";
  cout << "The distance that the " << car_3_color
       << " car 3 has traveled is: " << car_3_distance << "\n";
}
/* This works for few cars that are defined in the program, but if you wanted
the program to keep track of many cars this would be cumbersome. One way to fix
this would be to define a Car class with those variables as attributes, along
with few class methods to increment distance and print out car data
*/