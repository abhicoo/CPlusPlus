#include <iostream>
#include <string>
#include <thread>

class Vehicle {
public:
  Vehicle() : _id(0) {}
  void addID(int id) { _id = id; }
  void setName(std::string name) { _name = name; }
  void printID() { std::cout << "Vehicle ID=" << _id << std::endl; }
  void printName() { std::cout << "Vehicle name=" << _name << std::endl; }

private:
  int _id;
  std::string _name;
};

int main() {
  Vehicle v1, v2;

  std::thread t1 = std::thread(&Vehicle::addID, v1, 1);
  std::thread t2 = std::thread(&Vehicle::addID, &v2, 2);

  t1.join();
  t2.join();

  v1.printID();
  v2.printID();

  std::shared_ptr<Vehicle> v(new Vehicle);
  std::thread t3 = std::thread(&Vehicle::addID, v, 1);
  std::thread t4 = std::thread(&Vehicle::setName, v, "MyVehicle");

  t3.join();
  t4.join();

  v->printID();
  v->printName();

  return 0;
}