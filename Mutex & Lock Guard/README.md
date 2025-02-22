<div align="center">

# 🔒 Multi-Threaded Trading System Using Mutex in C++ 🚀

</div>

## 📖 Overview
This project demonstrates **multi-threading in C++** using **`std::thread`** and **`std::mutex`** to ensure that multiple traders can access shared resources **safely** while preventing race conditions. The program simulates two traders setting up **systematic trading applications** using thread synchronization.

## 🔑 Key Features
- **Uses `std::thread`** for parallel execution.
- **Implements `std::mutex`** to prevent data corruption.
- **Employs `std::lock_guard`** to handle automatic unlocking.
- **Simulates real-world trading setup processes.**

## 💻 Code Breakdown
```cpp
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex Lock; // Mutex to synchronize thread access

void Trade(std::string TraderName) {
    std::lock_guard<mutex> TradeLock(Lock); // Lock_guard manages lock automatically
    
    std::cout << TraderName << " is setting up the systematic trading applications\n";
    std::this_thread::sleep_for(chrono::seconds(1));
    std::cout << TraderName << " is done setting up the algorithms. \n";
    std::this_thread::sleep_for(chrono::seconds(2));
    // Lock is automatically released when TradeLock goes out of scope
}

int main() {
    thread t1(Trade, "Jad the quant trader");
    thread t2(Trade, "Shan the quant trader");
    
    t1.join(); // Ensures t1 completes execution before proceeding
    t2.join(); // Ensures t2 completes execution before program exit
};
```

## 🔍 Explanation
1. **Mutex (`std::mutex Lock`)**
   - Prevents simultaneous access to the critical section.
   - Ensures thread safety when modifying shared resources.

2. **Lock Guard (`std::lock_guard<mutex>`)**
   - Automatically acquires and releases the lock.
   - Eliminates the need for manual unlocking, reducing potential deadlocks.

3. **Thread Execution (`std::thread`)**
   - Creates **two separate traders** running `Trade` concurrently.
   - Each trader must **acquire the mutex** before executing the critical section.

4. **Thread Synchronization (`join()`)**
   - Ensures both traders finish before the program exits.
   - Prevents premature termination.

## 🚀 Why Use `std::mutex`?
✅ **Prevents data races** – Ensures safe access to shared resources.  
✅ **Thread-safe execution** – Only one thread can execute the critical section at a time.  
✅ **Simplifies debugging** – Avoids unpredictable behavior due to race conditions.  

## 🔥 Future Enhancements 
- ✅ Extend to **multi-threaded trade execution** and portfolio management.  
- ✅ Add **real-time market data processing** using multi-threading.  

## 🎯 Summary
This **multi-threading example** showcases how **mutex locks** can efficiently **prevent race conditions** while allowing concurrent execution of tasks. By leveraging `std::mutex`, we ensure safe and synchronized access to shared resources, making the program **efficient and robust**.

Happy Coding! 🎉

