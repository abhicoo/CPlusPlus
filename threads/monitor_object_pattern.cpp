#include <future>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

std::mutex _mtx;

class Vehicle {
public:
  Vehicle(int id) : _id(id) {}
  int getID() { return _id; }

private:
  int _id;
};

class WaitingVehicles {
public:
  WaitingVehicles() {}

  Vehicle popBack() {
    std::unique_lock<std::mutex> lck(_mtx);
    while (_vehicles.empty()) {
      _cond.wait(lck);
    }
    Vehicle v = std::move(_vehicles.back());
    _vehicles.pop_back();
    return v;
  }

  void pushBack(Vehicle &&v) {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::lock_guard<std::mutex> lck(_mtx);
    std::cout << "  Vehicle #" << v.getID() << " will be added to queue"
              << std::endl;
    _vehicles.emplace_back(std::move(v));
    _cond.notify_one();
  };

private:
  std::vector<Vehicle> _vehicles;
  std::condition_variable _cond;
};

int main() {
  std::shared_ptr<WaitingVehicles> queue(new WaitingVehicles);

  std::cout << "Spawning threads..." << std::endl;
  std::vector<std::future<void>> futures;

  for (int i = 0; i < 10; i++) {
    Vehicle v(i);
    futures.emplace_back(std::async(
        std::launch::async, &WaitingVehicles::pushBack, queue, std::move(v)));
  }

  std::cout << "Collecting results..." << std::endl;

  while (true) {
    Vehicle v = queue->popBack();
    _mtx.lock();
    std::cout << "  Vehicle #" << v.getID()
              << " has been removed from the queue" << std::endl;
    _mtx.unlock();
  }

  std::for_each(futures.begin(), futures.end(),
                [](std::future<void> &ftr) { ftr.wait(); });

  std::cout << "Finished processing queue..." << std::endl;
  return 0;
}