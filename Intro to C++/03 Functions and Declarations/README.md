<div align="center">

# 📈 Trading Data & Price Calculation in C++ 💹

</div>

## Overview
This section of my C++ learning journey focuses on **functions, arrays, and calculations**. Functions enable modular and reusable code, and arrays help store multiple values efficiently.

## 🔑 Key Concepts
- 🛠️ **Functions** organize code into reusable blocks.
- 📊 **Function Parameters** allow passing data dynamically.
- 🔢 **Arrays** store multiple related values in a structured manner.
- ➕ **Looping Through Arrays** enables calculations over datasets.

## 💻 Code Example
```cpp
#include <iostream>
using namespace std;

void LoadTradingData(int TradeID, string TradeSymbol) {
    // Function initializes and prints trade data
    cout << "Trade ID: " << TradeID << "\n";
    cout << "Trade Symbol: " << TradeSymbol << "\n";
    // Passes in variables TradeID and TradeSymbol as parameters
    cout << "Trade Security: Gold\n";
    cout << "Trade Date: 12:05:2024\n";
    cout << "Trade Quantity: 234\n";
    cout << "Trade Price: 31235\n";
}

double GetTotal(double prices[], int size) {
    double total = 0;
    for (int i = 0; i < size; i++) {
        total += prices[i];
        // Loops through array, summing up all prices
    }
    return total;
}

int main() {
    // Function = a block of reusable code
    int TradeID = 1235;
    string TradeSymbol = "Schonfeld Securities";
    // Declares variables to be passed as parameters to the function
    LoadTradingData(TradeID, TradeSymbol);

    // Invokes the function
    double prices[] = { 235.34, 214.32, 543.34, 34.99 };
    int size = sizeof(prices) / sizeof(prices[0]);
    // Number of elements = total array size / size of one element
    double total = GetTotal(prices, size);
    // Calls GetTotal to sum the prices
    cout << "$" << total;
}
```

## 📖 Explanation
### 1. **Loading Trade Data**
   - `LoadTradingData()` takes `TradeID` and `TradeSymbol` as parameters.
   - It outputs trade details including security, date, quantity, and price.

### 2. **Calculating Total Prices**
   - `GetTotal()` loops through the `prices` array.
   - It sums all prices and returns the total.
   - The `main()` function then prints the total amount.

## 🎯 Key Takeaways
- ⚡ Functions help modularize code for better organization.
- 📥 Arrays store multiple values efficiently.
- 🔄 Loops iterate through arrays for calculations.
- 📢 `cout` is used for structured output in C++.

This project demonstrates handling trade data and performing price calculations in C++, reinforcing key programming concepts. 🚀

