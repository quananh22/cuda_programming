#include <iostream>
#include <thread>
#include <chrono>
#include <random>   
#include <algorithm>
#include "thread_example.hpp"

void do_work(int thread_id) {
    // setting array size 5 with random values
    const int size = 5;
    std::array<int, size> arr;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    
    std::generate(arr.begin(), arr.end(), [&]() { return dis(gen); });
    std::cout << "Thread " << thread_id << " - Original array: ";
    for (const auto& val : arr) {
        std::cout << val << " ", "\n";
        
    }
}

void threads_execution() {
    std::cout << "Starting threads execution...\n";

    // Create multiple threads
    std::thread t1(do_work, 1);
    std::thread t2(do_work, 2);
    std::thread t3(do_work, 3);

    // Check thread joinable status
    std::cout << "Thread 1 joinable: " << (t1.joinable() ? "Yes" : "No") << "\n";
    std::cout << "Thread 2 joinable: " << (t2.joinable() ? "Yes" : "No") << "\n";
    std::cout << "Thread 3 joinable: " << (t3.joinable() ? "Yes" : "No") << "\n";

    std::cout << "Joining threads...\n";
    t3.join();
    t2.join();
    t1.join();

    // Check thread joinable status
    std::cout << "Thread 1 joinable: " << (t1.joinable() ? "Yes" : "No") << "\n";
    std::cout << "Thread 2 joinable: " << (t2.joinable() ? "Yes" : "No") << "\n";
    std::cout << "Thread 3 joinable: " << (t3.joinable() ? "Yes" : "No") << "\n";

    std::cout << "All threads have completed execution.\n";
    }

int main() {
    threads_execution();
    return 0;
}