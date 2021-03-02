#include <future>
#include <iostream>
#include <thread>

double divideByNumber(double num, double denom) {

  std::this_thread::sleep_for(std::chrono::milliseconds(500));
  std::cout << "Thread # " << std::this_thread::get_id() << std::endl;
  if (denom == 0)
    throw std::runtime_error("Exception from thread: Division by zero");

  return num / denom;
}

int main() {
  std::cout << "Main # " << std::this_thread::get_id() << std::endl;
  double num = 42.0, denom = 2.0;

  std::future<double> ftr = std::async(divideByNumber, num, denom);

  try {
    double result = ftr.get();
    std::cout << result << std::endl;
  } catch (std::runtime_error e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}