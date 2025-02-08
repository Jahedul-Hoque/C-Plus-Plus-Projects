<h1 align = "center"> 📈 Functions and Declarations in C++ 💹 <h1>

## Overview

This section of my C++ learning journey focuses on functions and their role in organizing reusable blocks of code. Functions are essential for structuring programs efficiently, especially in financial applications like trading systems.

## 🔑 Key Concepts

#### 🛠️ Functions allow modular and reusable code.

#### 📊 Function Parameters enable passing values to a function.

#### 🖥️ Console Output (cout) is used to display trade data.

```cpp
#include <iostream>
using namespace std;

void LoadTradingData(int TradeID, string TradeSymbol) {
    // Function initializes and prints trade data
    cout << "Trade ID: " << TradeID << "\n";
    cout << "Trade Symbol: " << TradeSymbol << "\n";
    cout << "Trade Security: Gold\n";
    cout << "Trade Date: 12:05:2024\n";
    cout << "Trade Quantity: 234\n";
    cout << "Trade Price: 31235\n";
}

int main() {
    // Function = a block of reusable code
    int TradeID = 1235;
    string TradeSymbol = "Schonfeld Securities";
    // Declares variables to be passed as parameters to the function
    LoadTradingData(TradeID, TradeSymbol);
    // Invokes the function
}
```

### 📖 Explanation

#### 1. Defining a Function

LoadTradingData() is a function that takes TradeID and TradeSymbol as parameters.

It prints trade-related information using cout.

#### 2. Calling a Function

The main() function declares TradeID and TradeSymbol.

It calls LoadTradingData() and passes the variables.

## 🎯 Key Takeaways

##### ⚡ Functions help organize code into reusable blocks.

##### 📥 Parameters allow functions to handle different inputs dynamically.

##### 📢 cout is useful for displaying structured output in C++.

##### This project demonstrates the use of functions in a trading data system, reinforcing key C++ programming concepts. 🚀
