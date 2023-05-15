#pragma once

#include <string>

class Sender {
public:
    virtual void connect(void);
    virtual void send(const std::string& msg);
};