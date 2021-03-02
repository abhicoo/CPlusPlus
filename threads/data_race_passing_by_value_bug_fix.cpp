#include <future>
#include <iostream>
#include <string>
#include <thread>

class Vehicle {
public:
  Vehicle() : _id(0), _name(new std::string("Default Name")) {
    std::cout << "Vehicle # " << _id << " Default Constructor called"
              << std::endl;
  }

  Vehicle(int id, std::string name) : _id(id), _name(new std::string(name)) {
    std::cout << "Vehicle # " << _id << " Initializing constructor called"
              << std::endl;
  }

  Vehicle(Vehicle const &src) {
    _id = src._id;
    std::cout << "old " << src._name << std::endl;
    if (src._name != nullptr) {
      _name = new std::string;
      *_name = *src._name;
    }
    std::cout << "new " << _name << std::endl;
    std::cout << "Vehicle # " << _id << " copy constructor called" << std::endl;
  }

  Vehicle(Vehicle &&src) {
    _id = src.getID();
    std::cout << "old " << src._name << std::endl;
    _name = src._name;
    std::cout << "new " << _name << std::endl;
    src.setID(0);
    src._name = nullptr;
    std::cout << "Vehicle # " << _id << " move constructor called" << std::endl;
  }

  void setID(int id) { _id = id; }
  int getID() { return _id; }

  void setName(std::string name) { *_name = name; }
  std::string getName() { return *_name; }

private:
  int _id;
  std::string *_name;
};

int main() {

  Vehicle v0(1, "Accord");

  std::future<void> ftr = std::async(
      [](Vehicle v) {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        v.setName("Vehicle 2");
      },
      std::move(v0));

  // v0.setName("Vehicle 3");

  ftr.wait();
  // std::cout << v0.getName() << std::endl;

  return 0;
}