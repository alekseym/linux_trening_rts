#include "sender.h"
#include <iostream>


void Sender::connect(void) {

  std::cout << "connect" << std::endl; 

}

void Sender::send(const std::string& msg) {
  std::cout << msg << std::endl; 
}