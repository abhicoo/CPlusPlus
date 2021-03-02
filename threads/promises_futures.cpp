#include <cmath>
#include <future>
#include <iostream>
#include <string>
#include <thread>

void modifyMessage(std::promise<std::string> &&prms, std::string message) {
  std::this_thread::sleep_for(std::chrono::milliseconds(200));
  std::string modifiedMessage = message + " has been modified";
  prms.set_value(modifiedMessage);
}

void divideByNumber(std::promise<double> &&prms, double num, double denom) {
  std::this_thread::sleep_for(std::chrono::milliseconds(500));
  try {
    if (denom == 0)
      throw std::runtime_error("Execption from thread: Division by zero");
    else
      prms.set_value(num / denom);
  } catch (...) {
    prms.set_exception(std::current_exception());
  }
}

void computeSqrt(std::promise<double> &&prms, int input) {
  std::this_thread::sleep_for(std::chrono::milliseconds(2000));
  double output = sqrt(input);
  prms.set_value(output);
}

int main() {
  std::string messageToThread = "My Message";

  std::promise<std::string> prms;
  std::future<std::string> ftr = prms.get_future();

  std::thread t(modifyMessage, std::move(prms), messageToThread);

  std::cout << "Original message from main(): " << messageToThread << std::endl;

  std::string messageFromThread = ftr.get();

  std::cout << "Original message from thread(): " << messageFromThread
            << std::endl;

  std::cout << "Original message from main(): " << messageToThread << std::endl;

  t.join();

  std::promise<double> prms1;
  std::future<double> ftr1 = prms1.get_future();
  double num = 42, denom = 0.0;

  std::thread t1(divideByNumber, std::move(prms1), num, denom);

  try {
    double result = ftr1.get();
    std::cout << "Result = " << result << std::endl;
  } catch (std::runtime_error e) {
    std::cout << e.what() << std::endl;
  }

  t1.join();

  std::promise<double> prms2;
  std::future<double> ftr2 = prms2.get_future();
  double input = 4.0;

  std::thread t2(computeSqrt, std::move(prms2), input);

  auto status = ftr2.wait_for(std::chrono::milliseconds(1000));

  if (status == std::future_status::ready) {
    std::cout << "Result = " << ftr2.get() << std::endl;
  } else if (status == std::future_status::timeout ||
             status == std::future_status::deferred) {
    std::cout << "Result unavailable" << std::endl;
  }

  t2.join();

  return 0;
}