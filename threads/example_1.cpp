#include <iostream>
#include <thread>

void threadFunction() {
  std::this_thread::sleep_for(std::chrono::microseconds(100));
  std::cout << "Finished work in thread " << std::endl;
}

int main() {
  // Fetch the current thread id
  std::cout << "Hello concurrent world from main! Thread id = "
            << std::this_thread::get_id() << std::endl;

  // Fetch number of available hardware concurrency
  unsigned int nCores = std::thread::hardware_concurrency();
  std::cout << "This machine supports concurrency with " << nCores
            << " cores available" << std::endl;

  // Create new thread
  std::thread t(threadFunction);

  // do something in main thread
  std::this_thread::sleep_for(std::chrono::microseconds(50));
  std::cout << "Finished work in main" << std::endl;

  // wait for thread to finish
  t.join();

  return 0;
}