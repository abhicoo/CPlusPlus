#include <iostream>
#include <thread>
#include <vector>

void printHello(int i) {
  std::this_thread::sleep_for(std::chrono::milliseconds(10 * i));
  std::cout << "Hello from Worker thread #" << i << std::endl;
}

int main() {
  std::vector<std::thread> threads;

  for (int i = 0; i < 10; i++) {
    threads.emplace_back(std::thread(printHello, i + 1));
  }

  std::cout << "Hello from Main thread" << std::endl;

  for (auto &t : threads) {
    t.join();
  }

  return 0;
}
