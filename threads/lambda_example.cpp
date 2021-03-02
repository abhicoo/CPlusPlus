#include <iostream>
#include <thread>

int main() {

  int id = 0;

  auto f0 = [&id]() {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "a) ID in Thread (call-by-reference) = " << id << std::endl;
  };

  std::thread t1(f0);

  std::thread t2([id]() {
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "a) ID in Thread (call-by-value) = " << id << std::endl;
  });

  ++id;
  std::cout << "c) ID in main " << id << std::endl;

  t1.join();
  t2.join();

  return 0;
}