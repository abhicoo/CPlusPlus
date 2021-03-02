#include <iostream>

int main() {

  int id = 0;

  // auto f0 = []() { std::cout << "ID = " << id << std::endl; }; // Error: 'id'
  // cannot be accessed

  id++;

  auto f1 = [id]() {
    std::cout << "ID1 = " << id << std::endl;
  }; // Ok: 'id' captured as value

  id++;
  auto f2 = [&id]() {
    std::cout << "ID2 = " << id << std::endl;
  }; // Ok: 'id' captured as reference

  auto f3 = [&id]() {
    id = 10;
    std::cout << "ID3 = " << id << std::endl;
  }; // Ok: 'id' captured as reference and modified

  f1();
  f2();
  f3();

  std::cout << "ID4 = " << id << std::endl;

  auto f4 = [id]() mutable {
    std::cout << "ID5 = " << ++id << std::endl;
  }; // Ok: 'id' may be modified since its mutable

  f4();

  std::cout << "ID6 = " << id << std::endl;

  return 0;
}