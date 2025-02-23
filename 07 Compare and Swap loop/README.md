<div align="center">

# 💹 Atomic Trading System Using Multi-Threading in C++ 🚀

</div>

## 📖 Overview
This project demonstrates **multi-threaded trade execution** using **`std::atomic`** for safe concurrent access to a shared portfolio balance. It ensures **thread-safe withdrawals**, preventing race conditions using **Compare-And-Swap (CAS) operations**.

## 🔑 Key Features
- **Uses `std::atomic<int>`** to manage account balance without race conditions.
- **Employs `compare_exchange_weak()`** for efficient balance updates.
- **Executes multiple trades concurrently** using `std::thread`.
- **Handles insufficient funds safely**, rejecting trades when needed.

## 💻 Code Breakdown
```cpp
#include <iostream>
#include <atomic>
#include <thread>
#include <vector>
#include <random>

std::atomic<int> account_balance(1000000); // $1,000,000 initial balance

void processTrade(int trade_id, int trade_amount) {
    int expected_balance, new_balance;
    do {
        expected_balance = account_balance.load();
        if (expected_balance < trade_amount) {
            std::cout << "[Trade " << trade_id << "] Insufficient funds. Balance: $"
                      << expected_balance << ", Trade: $" << trade_amount << "\n\n";
            return;
        }
        new_balance = expected_balance - trade_amount;
    } while (!account_balance.compare_exchange_weak(expected_balance, new_balance));
    
    std::cout << "[Trade " << trade_id << "] Executed trade of $" << trade_amount
              << ". New Balance: $" << new_balance << "\n\n";
}

int main() {
    srand(time(0));
    std::cout << "Initial Portfolio value: $" << account_balance.load() << "\n\n";

    const int num_trades = 20;
    std::vector<std::thread> traders;

    for (int i = 0; i < num_trades; i++) {
        int trade_amount = rand(); // Generate random trade amounts
        traders.emplace_back(processTrade, i + 1, trade_amount);
    }

    for (auto& t : traders) {
        t.join(); // Ensure all trades complete
    }

    std::cout << "Final Account Balance: $" << account_balance.load() << "\n";
    return 0;
}
```

## 🔍 Explanation
1. **Atomic Account Balance (`std::atomic<int>`)**
   - Ensures safe concurrent updates by multiple threads.
   - Prevents data corruption from race conditions.

2. **Trade Execution (`processTrade`)**
   - Uses **Compare-And-Swap (CAS)** to update balance safely.
   - Rejects trades when insufficient funds are available.
   - Ensures atomic updates for multiple simultaneous trades.

3. **Multi-Threading (`std::thread`)**
   - Creates 20 traders making **simultaneous trades**.
   - Uses `emplace_back()` for efficient thread creation.
   - **Threads execute in parallel**, ensuring high performance.

4. **Thread Synchronization (`join()`)**
   - Ensures all traders finish execution before displaying the final balance.
   - Prevents premature program termination.

## 🚀 Why Use `std::atomic` and CAS?
✅ **Avoids race conditions** – Ensures safe concurrent withdrawals.  
✅ **Faster than using mutex locks** – No blocking operations required.  
✅ **Efficient trade execution** – Uses `compare_exchange_weak()` for high-speed transactions.  

## 🔥 Future Enhancements
- ✅ Include **Sequential outputting for the trades using a map that stores key-value pairs**.
- ✅ Add **historical trade logging**.

## 🎯 Summary
This **multi-threaded atomic trading system** ensures **safe and efficient** portfolio management by leveraging **atomic operations** and **Compare-And-Swap (CAS)**. By eliminating race conditions and improving transaction safety, this approach is highly efficient for real-world **financial applications**.

Happy Trading! 💰🚀

