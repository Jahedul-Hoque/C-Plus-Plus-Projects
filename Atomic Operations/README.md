<div align="center">

# 💹 Multi-Threaded Portfolio Value Tracker in C++ 🚀

</div>

## 📖 Overview
This project demonstrates **multi-threading in C++** using **`std::thread`** and **`std::atomic`** to ensure **safe concurrent access** to a shared portfolio value. The program runs two threads that **increment the portfolio value simultaneously**, showcasing how atomic operations prevent race conditions.

## 🔑 Key Features
- **Uses `std::thread`** for parallel execution.
- **Implements `std::atomic<int>`** to avoid data corruption.
- **Ensures thread safety** without explicit locks.
- **Simulates portfolio growth through concurrent trading activity.**

## 💻 Code Breakdown
```cpp
#include <iostream>
#include <thread>
#include <atomic>

int main() {
    std::atomic<int> PortfolioValue = 0; // Atomic portfolio value to prevent race conditions
    
    auto trade = [&PortfolioValue] {
        for (int i = 0; i < 1000000; i++)
            PortfolioValue++; // Safe atomic increment
    };

    std::thread t1(trade); // First thread
    std::thread t2(trade); // Second thread
    
    t1.join(); // Wait for t1 to finish
    t2.join(); // Wait for t2 to finish
    
    std::cout << "Your Portfolio value is " << PortfolioValue << " GBP.\n";
    return 0;
}
```

## 🔍 Explanation
1. **Atomic Portfolio Value (`std::atomic<int>`)**
   - Ensures safe concurrent updates by both threads.
   - Prevents race conditions without requiring explicit locks.

2. **Lambda Function (`trade`)**
   - Defines a task that increments `PortfolioValue` **1,000,000 times**.
   - Uses **lambda capture by reference** (`&PortfolioValue`) to modify the shared counter.

3. **Thread Execution (`std::thread`)**
   - Creates **two separate threads**, both running `trade` simultaneously.
   - Each thread increments `PortfolioValue` concurrently.

4. **Thread Synchronization (`join()`)**
   - Ensures both threads **complete execution** before printing the result.
   - Prevents **premature program termination**.

## 🚀 Why Use `std::atomic`?
✅ **Avoids data races** – Ensures correct portfolio updates.  
✅ **Faster than using mutexes** – No need for explicit locks.  
✅ **Simple syntax** – Just use `std::atomic<int>` instead of `int`.  

## 🔥 Future Enhancements
- ✅ Extend to **multi-threaded decrement operations (loss simulation)**.
- ✅ Experiment with **different atomic types (`std::atomic<float>`, etc.)**.
- ✅ Implement performance benchmarks comparing **atomic vs. mutex-based threading**.

## 🎯 Summary
This **multi-threading example** showcases how **atomic operations** can efficiently **prevent race conditions** while allowing concurrent execution of tasks. By leveraging `std::atomic`, we eliminate the need for complex locking mechanisms, making the program **efficient and safe**.

Happy Coding! 🎉

