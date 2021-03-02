#include <iostream>
#include <thread>

class Vehicle {
public:
  Vehicle(int id) : _id(id) {}
  void operator()() {
    std::cout << "Vehicle #" << _id << " has been created" << std::endl;
  }

private:
  int _id;
};

int main() {

  std::thread t((Vehicle(1)));

  std::cout << "Finished working in main" << std::endl;

  t.join();

  return 0;
}