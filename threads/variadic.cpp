#include <iostream>
#include <string>
#include <thread>

void printName(std::string &name, int waitTime) {
  std::this_thread::sleep_for(std::chrono::milliseconds(waitTime));
  name += " (from Thread)";
  std::cout << name << std::endl;
}

void printID(int id) {
  std::this_thread::sleep_for(std::chrono::milliseconds(50));
  std::cout << "ID = " << id << std::endl;
}

void printIDAndName(int id, std::string name) {
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  std::cout << "ID = " << id << ", name = " << name << std::endl;
}

int main() {
  int id = 0;

  std::thread t1(printID, id);

  std::thread t2(printIDAndName, ++id, "MyString");

  t1.join();
  t2.join();

  std::string name("MyThread");

  std::thread t(printName, std::ref(name), 50);

  t.join();

  name += " (from Main)";

  std::cout << name << std::endl;

  return 0;
}