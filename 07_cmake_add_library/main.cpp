#include "detector.h"
#include "sender.h"
#include <memory>

int main() {
  auto detector = std::make_unique<Detector> ();
  auto sender   = std::make_unique<Sender> ();

  while(1) {
    auto points = detector->detect();

    std::string msg;

    for (auto point: points) {
      msg = msg + point.toString();      
    }

    sender->send(msg);
  }
}