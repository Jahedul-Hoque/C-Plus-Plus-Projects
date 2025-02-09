<div align="center">

# 🏢 Object-Oriented Programming with Inheritance in C++ 👨‍💻💼

</div>

## Overview
This section of my C++ learning journey explores **inheritance**, an essential **Object-Oriented Programming (OOP)** concept that allows child classes to derive attributes and behaviors from a parent class.

## 🔑 Key Concepts
- 📦 **Classes & Objects** define real-world entities with attributes and methods.
- 📂 **Inheritance** allows child classes to inherit parent class properties.
- ⚙️ **Constructors** initialize object attributes upon creation.
- 🔄 **Method Overriding** lets child classes define their unique behaviors.

## 💻 Code Example
```cpp
#include <iostream>
using namespace std;

class Employee {
public:
    int salary;
    string name;
    string ApplicationUsed;

    void working() {
        cout << "This employee is currently working at Schonfeld.\n";
    }

    void CoffeeBreak() {
        cout << "This employee is currently on his coffee break\n";
    }
};

class TechEmployee : public Employee {
public:
    string FavouriteGame;

    TechEmployee(string name, string FavouriteGame, string ApplicationUsed, int salary) {
        this->name = name;
        this->FavouriteGame = FavouriteGame;
        this->ApplicationUsed = ApplicationUsed;
        this->salary = salary;
    }
    // Constructor initializing TechEmployee attributes

    void Developing() {
        cout << "The employee is currently working on some code\n";
    }
};

class InvestmentEmployee : public Employee {
public:
    string FavouriteSecurity;

    InvestmentEmployee(string name, string FavouriteSecurity, string ApplicationUsed, int salary) {
        this->name = name;
        this->FavouriteSecurity = FavouriteSecurity;
        this->ApplicationUsed = ApplicationUsed;
        this->salary = salary;
    }
    // Constructor initializing InvestmentEmployee attributes

    void Trading() {
        cout << "This Employee is currently trading using Bloomberg\n";
    }
};

int main() {
    InvestmentEmployee InvestmentEmployee1("Vikesh", "Gold", "Bloomberg", 82379283);
    cout << "Name of Employee: " << InvestmentEmployee1.name << "\n";
    cout << "Favourite Security: " << InvestmentEmployee1.FavouriteSecurity << "\n";
    cout << "Application Used: " << InvestmentEmployee1.ApplicationUsed << "\n";
    cout << "Salary: " << InvestmentEmployee1.salary << " GBP \n";
    InvestmentEmployee1.Trading();

    cout << endl;

    TechEmployee TechEmployee1("Jad", "League of Legends", "C++", 10);
    cout << "Name of Employee: " << TechEmployee1.name << "\n";
    cout << "Favourite Game: " << TechEmployee1.FavouriteGame << "\n";
    cout << "Application Used: " << TechEmployee1.ApplicationUsed << "\n";
    cout << "Salary: " << TechEmployee1.salary << " GBP \n";
    TechEmployee1.Developing();
}
```

## 📖 Explanation
### 1. **Parent Class (Employee)**
   - Defines common attributes (`name`, `salary`, `ApplicationUsed`) and methods (`working()`, `CoffeeBreak()`).

### 2. **Child Classes (TechEmployee & InvestmentEmployee)**
   - `TechEmployee` inherits from `Employee` and adds `FavouriteGame` and `Developing()`.
   - `InvestmentEmployee` inherits from `Employee` and adds `FavouriteSecurity` and `Trading()`.

### 3. **Creating Employee Objects**
   - Objects for `InvestmentEmployee` and `TechEmployee` are instantiated with relevant attributes.
   - Methods from the **parent class** (`Employee`) and **child classes** are invoked.

## 🎯 Key Takeaways
- 📌 **Inheritance enables code reusability** by allowing child classes to derive properties from a parent class.
- 🏗️ **Objects** can access both inherited and exclusive attributes/methods.
- 🔄 **Encapsulation & abstraction** help model real-world business structures efficiently.
- ⚙️ **Constructors** simplify object initialization with predefined attributes.

This project demonstrates fundamental **Object-Oriented Programming (OOP) inheritance concepts** in C++, reinforcing modular and reusable coding practices. 🚀💡