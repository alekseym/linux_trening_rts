#pragma once

#include <vector>
#include <string>
//#include <format>

struct Position {
  int x;
  int y;
  std::string toString() {
    return std::to_string(x) + "," + std::to_string(y) +";";
//    return std::format("%d,%d;",x,y);
  }
};

class Detector {
public:
  virtual std::vector<Position> detect();

};

