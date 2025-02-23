#include <iostream>
#include <atomic>
#include <thread>
#include <vector>
#include <random>

// Global shared account balance
std::atomic<int> account_balance(1000000);  // $1,000,000 initial balance

// Function to process a trade (withdraw money)
void processTrade(int trade_id, int trade_amount) {
    int expected_balance, new_balance;

    do {
        expected_balance = account_balance.load();  // Load current balance

        if (expected_balance < trade_amount) {
            std::cout << "[Trade " << trade_id << "] Insufficient funds. Balance: $"
                << expected_balance << ", Trade: $" << trade_amount << std::endl;
            std::cout << std::endl;
            return;  // Reject trade
        }

        new_balance = expected_balance - trade_amount;  // Compute new balance

    } while (!account_balance.compare_exchange_weak(expected_balance, new_balance));
    // CAS: Compare expected balance with current account balance and if its changed, then replace with new balance
    //      Once expected balance is the same as account balance, then break loop.
    // difference between .compare_exchange_weak and .compare_exchange_strong is that the former is faster but may fail
    //                    the check even if the value was true.
    //                    Often used in loops.
    //                    The latter is used for absolute correctness but causes an additional overhead reducing speed.
    std::cout << "[Trade " << trade_id << "] Executed trade of $" << trade_amount
        << ". New Balance: $" << new_balance << std::endl;
    std::cout << std::endl;
    // the CPU writes to the console as soon as the threads finish their processes
    // one way of ordering the trades is by storing each value into a map and store it as a key-value pair.
}

int main() {
    srand(time(0));
    std::cout << "Initial Portfolio value: $" << account_balance.load() << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    const int num_trades = 20;
    std::vector<std::thread> traders;

    // Simulate multiple traders making concurrent trades



    for (int i = 0; i < num_trades; i++) {
        int trade_amount = rand();
        traders.emplace_back(processTrade, i + 1, trade_amount);
        // create a new thread using .emplace_back
    }

    // For all the threads inside traders, join all threads
    for (auto& t : traders) {
        t.join();
    }

    std::cout << "Final Account Balance: $" << account_balance.load() << "\n";

    return 0;
}