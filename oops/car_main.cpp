#include "car.h"
#include <iostream>
#include <vector>

using std::vector;

int main() {
  Car car_1 = Car("green", 1);
  Car car_2 = Car("red", 2);
  Car car_3 = Car("blue", 3);

  car_1.IncrementDistance();

  car_1.PrintCarData();
  car_2.PrintCarData();
  car_3.PrintCarData();

  vector<Car *> car_vect;
  Car *cp = nullptr;

  const string colors[3] = {"green", "blue", "red"};

  for (int i = 0; i < 100; i++) {
    cp = new Car(colors[i % 3], i + 1);
    car_vect.push_back(cp);
  }

  for (Car *cp : car_vect) {
    cp->IncrementDistance();
  }

  for (Car *cp : car_vect) {
    cp->PrintCarData();
  }
}