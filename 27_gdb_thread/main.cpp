#include <iostream>
#include <thread>
#include <chrono>


void thread_function()
{
    while(1) {
    	std::cout << "thread function\n";
    	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    }
}

int main()
{
    std::thread t(&thread_function);   // t starts running
    std::cout << "main thread\n";
    t.join();   // main thread waits for the thread t to finish
    return 0;
}
