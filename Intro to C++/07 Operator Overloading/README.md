<h1 align="center"> 📌 Operator Overloading in C++ </h1>

## 📖 Overview

This project demonstrates **operator overloading** in C++. Operator overloading allows us to define custom behavior for built-in operators when applied to user-defined data types.

---

## 🛠️ Concepts Covered

- **Operator Overloading:** Customizing the behavior of `+`, `-`, and `==` operators.
- **Encapsulation:** Using classes to define behavior and attributes.
- **Object-Oriented Programming:** Working with objects and member functions.

---

## 📜 Code Explanation

### 🔹 Class Definition: `number`
```cpp
#include <iostream>
using namespace std;

class number {
public:
    int n;

    number(int set_n) {
        n = set_n;
    }
```
- The `number` class has a public integer attribute `n`.
- A constructor initializes `n` with a given value.

### ➕ Overloading the `+` Operator
```cpp
    number operator+(const number& numA) {
        return number(this->n + numA.n);
    }
```
- Defines how two `number` objects can be added.
- `this->n` refers to the left operand, `numA.n` refers to the right operand.

### ➖ Overloading the `-` Operator
```cpp
    number operator-(const number& numA) {
        return number(this->n - numA.n);
    }
```
- Defines how subtraction works between two `number` objects.

### 🔁 Overloading the `==` Operator
```cpp
    bool operator== (const number& numA) {
        return this->n == numA.n;
    }
```
- Compares two `number` objects and returns `true` if their values are equal.

---

## 🏃 Execution

### 🖥️ `main` Function
```cpp
int main() {
    number a(5);
    number b(10);
    number c = a + b;
    cout << "c.n: " << c.n << endl;
```
- `a + b` calls the overloaded `+` operator and stores the result in `c`.
- `c.n` outputs **15**.

```cpp
    number d(15);
    number e(10);
    number f = d - e;
    cout << "d.n: " << f.n << endl;
```
- `d - e` calls the overloaded `-` operator and stores the result in `f`.
- `f.n` outputs **5**.

```cpp
    if (a == f)
        cout << "a does equal c" << endl;
    else cout << "a does not equal c" << endl;
```
- Checks if `a` (5) is equal to `f` (5), prints **"a does equal c"**.

```cpp
    if (a == b)
        cout << "a does equal b" << endl;
    else cout << "a does not equal b" << endl;
```
- Checks if `a` (5) is equal to `b` (10), prints **"a does not equal b"**.

---

## 🎯 Expected Output
```plaintext
c.n: 15
d.n: 5
a does equal c
a does not equal b
```

---

## 📌 Summary
- Overloaded `+` and `-` operators to perform arithmetic operations on `number` objects.
- Overloaded `==` operator to compare two `number` objects.
- Demonstrated operator overloading in an example program.
