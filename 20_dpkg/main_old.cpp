#include "detector.h"
#include "sender.h"
#include <memory>

int main() {
  Detector* detector = new Detector();
  Sender* sender   = new Sender();

  while(1) {
    std::vector<Position> points = detector->detect();

    std::string msg;

    for (int i=0;i<points.size();i++) {
      msg = msg + points[i].toString();      
    }

    sender->send(msg);
  }

  delete detector;
  delete sender;
}