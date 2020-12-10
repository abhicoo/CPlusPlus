#include "car.h"
#include <iostream>
#include <string>

using std::cout;

void Car::PrintCarData() {
  cout << "The distance that the " << color << " car " << number
       << " has travelled is: " << distance << "\n";
}

void Car::IncrementDistance() { distance++; }