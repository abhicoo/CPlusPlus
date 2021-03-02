#include <deque>
#include <future>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

template <class T> class MessageQueue {
public:
  MessageQueue() {}

  T receive() {
    std::unique_lock<std::mutex> lck(_mtx);
    while (_messages.empty()) {
      _cond.wait(lck);
    }
    T msg = std::move(_messages.back());
    _messages.pop_back();
    return msg;
  }

  void send(T &&msg) {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::lock_guard<std::mutex> lck(_mtx);
    std::cout << "  Msg" << msg << " will be added to queue" << std::endl;
    _messages.emplace_back(std::move(msg));
    _cond.notify_one();
  };

private:
  std::mutex _mtx;
  std::deque<T> _messages;
  std::condition_variable _cond;
};

int main() {
  std::shared_ptr<MessageQueue<int>> queue(new MessageQueue<int>);

  std::cout << "Spawning threads..." << std::endl;
  std::vector<std::future<void>> futures;

  for (int i = 0; i < 10; i++) {
    int message = i;
    futures.emplace_back(std::async(std::launch::async,
                                    &MessageQueue<int>::send, queue,
                                    std::move(message)));
  }

  std::cout << "Collecting results..." << std::endl;

  while (true) {
    int message = queue->receive();
    std::cout << "   Message #" << message << " has been removed from the queue"
              << std::endl;
  }

  std::for_each(futures.begin(), futures.end(),
                [](std::future<void> &ftr) { ftr.wait(); });

  std::cout << "Finished!" << std::endl;

  return 0;
}