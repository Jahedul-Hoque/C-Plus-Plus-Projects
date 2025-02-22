# 📌 Dynamic Memory Allocation in C++

## 📖 Overview
Dynamic memory allocation in C++ allows programs to allocate memory at runtime, making them more flexible when dealing with user input and unknown memory requirements. This is achieved using the `new` and `delete` operators.

## 📌 Key Concepts
- **Heap Memory**: Memory allocated dynamically using the `new` operator resides in the heap.
- **Stack Memory**: Memory allocated for local variables within functions resides in the stack.
- **Pointers**: Used to store memory addresses and reference dynamically allocated variables.
- **Deleting Memory**: Always use `delete` (for single variables) or `delete[]` (for arrays) to free allocated memory and avoid memory leaks.

## 💻 Code Implementation
```cpp
using namespace std;
#include <iostream>

int main() {
    // 🔹 Dynamic Memory Allocation Example
    int* ReferenceNum = NULL; // Initializing pointer to NULL
    ReferenceNum = new int; // Allocating memory for an integer
    *ReferenceNum = 21; // Assigning value

    cout << "The Address of ReferenceNum: " << ReferenceNum << endl;
    cout << "The Value of ReferenceNum: " << *ReferenceNum << endl;

    delete ReferenceNum; // Freeing allocated memory

    // 🔹 Dynamic Memory for Arrays
    int* Trades = NULL;
    int size;
    cout << "How many trades did you want to enter?: ";
    cin >> size;

    Trades = new int[size]; // Allocating memory for array
    
    for (int i = 0; i < size; i++) {
        cout << "Enter Trade Price #" << i + 1 << ": ";
        cin >> Trades[i];
    }

    cout << "Trade Prices: ";
    for (int i = 0; i < size; i++) {
        cout << "$" << Trades[i] << " ";
    }
    cout << endl;

    delete[] Trades; // Freeing allocated memory for array

    return 0;
}
```

## 🔍 Explanation
1. **Allocating Memory for a Single Variable**
   - A pointer `ReferenceNum` is declared and initialized to `NULL`.
   - `new int` dynamically allocates memory for an integer.
   - The value `21` is assigned using the dereference operator `*`.
   - The address and value are printed before freeing memory using `delete`.

2. **Allocating Memory for an Array**
   - The user is prompted for the number of trades.
   - Memory is allocated dynamically using `new int[size]`.
   - The user enters trade prices, which are stored in the allocated memory.
   - The stored values are printed.
   - Finally, memory is freed using `delete[]`.

## 🚀 Advantages of Dynamic Memory
✅ Efficient memory usage.
✅ Allows flexible handling of user inputs.
✅ Useful for data structures like linked lists and trees.

## ⚠️ Potential Pitfalls
❌ Memory leaks if `delete` is not used.
❌ Dangling pointers if memory is accessed after deletion.
❌ Slower than stack allocation.

🎯 **Best Practice**: Always release dynamically allocated memory using `delete` or `delete[]` to prevent memory leaks.