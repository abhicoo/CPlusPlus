#include <iostream>
#include <thread>

void threadFunction() {
  std::this_thread::sleep_for(std::chrono::microseconds(1000));
  std::cout << "Finished work 1 in thread" << std::endl;

  std::this_thread::sleep_for(std::chrono::microseconds(1000));
  std::cout << "Finished work 2 in thread" << std::endl;
}

int main() {

  std::thread t(threadFunction);

  std::this_thread::sleep_for(std::chrono::microseconds(1000));
  std::cout << "Finished work 1 in main" << std::endl;

  std::this_thread::sleep_for(std::chrono::microseconds(1000));
  std::cout << "Finished work 2 in main" << std::endl;

  t.join();

  return 0;
}