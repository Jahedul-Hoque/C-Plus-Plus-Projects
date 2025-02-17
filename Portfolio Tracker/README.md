# 📌 Live Stock Portfolio Tracker in C++  

## 📖 Overview  
The **Live Stock Portfolio Tracker** is a C++ program that simulates real-time stock price updates. It tracks a user's stock holdings, calculates portfolio value, and allows for price refreshes to mimic a dynamic trading environment.  

This project demonstrates essential **C++ programming skills**, including **structs, vectors, functions, and randomization**—ideal for finance-focused software development.  

---

## 📌 Key Concepts  
- **Stock Struct** → Stores each stock’s ticker symbol, quantity, and price.  
- **Dynamic Pricing** → Uses randomization to simulate real-time stock price fluctuations.  
- **Portfolio Calculation** → Computes total stock value based on updated prices.  
- **User Interaction** → Allows users to refresh stock prices and track changes dynamically.  

---

## 💻 Code Implementation  
```cpp
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>

struct Stock {
    std::string ticker;
    double quantity;
    double price;
};

// Function to simulate real-time stock price changes
double getRandomPrice(double basePrice) {
    double change = ((rand() % 2001) - 1000) / 10000.0; // Random change between -10% and +10%
    return basePrice * (1 + change);
}

void displayPortfolio(const std::vector<Stock>& portfolio) {
    double totalValue = 0.0;
    std::cout << "\n📊 Portfolio Overview\n";
    std::cout << "--------------------------------------\n";
    std::cout << std::left << std::setw(10) << "Stock" << std::setw(10) << "Qty"
              << std::setw(10) << "Price" << std::setw(15) << "Total Value" << "\n";
    std::cout << "--------------------------------------\n";

    for (const auto& stock : portfolio) {
        double updatedPrice = getRandomPrice(stock.price);
        double totalStockValue = updatedPrice * stock.quantity;
        totalValue += totalStockValue;

        std::cout << std::left << std::setw(10) << stock.ticker
                  << std::setw(10) << stock.quantity
                  << std::setw(10) << std::fixed << std::setprecision(2) << updatedPrice
                  << std::setw(15) << totalStockValue << "\n";
    }

    std::cout << "--------------------------------------\n";
    std::cout << "💰 Total Portfolio Value: $" << totalValue << "\n";
}

int main() {
    srand(time(0)); // Seed for random price changes

    // Portfolio setup (tickers, quantities, base prices)
    std::vector<Stock> portfolio = {
        {"AAPL", 10, 175.0},
        {"MSFT", 5, 320.0},
        {"GOOGL", 8, 2800.0},
        {"TSLA", 12, 720.0}
    };

    char choice;
    do {
        displayPortfolio(portfolio);

        std::cout << "\n🔄 Refresh prices? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    std::cout << "📈 Exiting portfolio tracker. Happy investing!\n";
    return 0;
}
```

---

## 🔍 Explanation  
### **1. Stock Data Representation**  
- The `Stock` struct stores **ticker symbol, quantity, and price**.  
- A **vector of stocks** (`std::vector<Stock> portfolio`) represents a user’s holdings.  

### **2. Simulating Stock Price Changes**  
- The `getRandomPrice()` function randomly adjusts a stock’s price by **±10%**.  

### **3. Displaying the Portfolio**  
- The `displayPortfolio()` function:  
  - Iterates through the portfolio.  
  - Updates prices dynamically.  
  - Displays **ticker, quantity, new price, and total value** in a formatted table.  

### **4. User Interaction**  
- The program **loops until the user exits**, allowing for continuous price refreshes.  

---

## 🚀 Features & Benefits  
✅ **Simulates a real hedge fund trading environment** 📈  
✅ **Self-contained** → No external files or APIs required 🔥  
✅ **Real-time stock price updates** with **randomized fluctuations** 🔄  
✅ **Beginner-friendly C++ concepts** including `struct`, `vector`, and `iomanip` 📚  

---

## ⚠️ Potential Enhancements  
🔹 **Integrate an API** (Yahoo Finance) for real stock prices.  
🔹 **Add trade functionality** → Buy/Sell stocks interactively.  
🔹 **Track historical price changes** over multiple refresh cycles.  

---

## 🎯 How to Run  
1️⃣ **Compile the program:**  
```sh
g++ stock_tracker.cpp -o stock_tracker
```
2️⃣ **Run the program:**  
```sh
./stock_tracker
```
3️⃣ **Press `y`** to refresh stock prices or `n` to exit.  

---

🛠️ Happy Coding! 🚀