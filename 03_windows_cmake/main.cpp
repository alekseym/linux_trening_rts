#include <iostream>

float speed(float s, float t) {
  float val = 0;
  if(t!=0)
    val = s/t;
  return val;
}


int main() {
    std::cout << "Speed " << speed(4.,2.) << std::endl;
}