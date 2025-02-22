<div align="center">

# 👨‍💼 Object-Oriented Programming in C++ 🏢

</div>

## Overview
This section of my C++ learning journey focuses on **Object-Oriented Programming (OOP)**, a paradigm that models real-world entities using **classes** and **objects**.

## 🔑 Key Concepts
- 📦 **Classes** define a blueprint for objects.
- 🏗️ **Objects** are instances of a class with specific attributes.
- 🔄 **Methods** define behaviors an object can perform.
- 🏗️ **Constructors** initialize object attributes upon creation.

## 💻 Code Example
```cpp
#include <iostream>
using namespace std;

class Employee {
public:
    string Name;
    string Title;
    int BaseSalary;
    // Attributes defining an Employee object

    void work() {
        cout << "This person is working right now\n";
    }
    void communicate() {
        cout << "This person is talking to their friend on the phone\n";
    }
    void OutOfOffice() {
        cout << "This person is currently not in the office\n";
    }
    // Methods defining behaviors of an Employee

    Employee(string Name, string Title, int BaseSalary) {
        this->Name = Name;
        this->Title = Title;
        this->BaseSalary = BaseSalary;
    }
    // Constructor initializing attributes
};

int main() {
    Employee Employee1("Shanawaz Bisath", "CEO of Schonfeld", 100000000000);
    cout << "Employee 1's name is " << Employee1.Name << "\n";
    cout << "Employee 1's Title is " << Employee1.Title << "\n";
    cout << "Employee 1's Base Salary is " << Employee1.BaseSalary << " GBP \n";
    Employee1.work();
    cout << endl;

    Employee Employee2("Jahedul Hoque", "End User Services Engineer", 1);
    cout << "Employee 2's name is " << Employee2.Name << "\n";
    cout << "Employee 2's Title is " << Employee2.Title << "\n";
    cout << "Employee 2's Base Salary is " << Employee2.BaseSalary << " GBP \n";
    Employee2.communicate();
    cout << endl;

    Employee Employee3("Emran Hussain", "Platforms Support Engineer", 70000);
    cout << "Employee 3's name is " << Employee3.Name << "\n";
    cout << "Employee 3's Title is " << Employee3.Title << "\n";
    cout << "Employee 3's Base Salary is " << Employee3.BaseSalary << " GBP \n";
    Employee3.OutOfOffice();
    cout << endl;
}
```

## 📖 Explanation
### 1. **Class and Object Structure**
   - `Employee` class defines attributes (`Name`, `Title`, `BaseSalary`) and methods (`work()`, `communicate()`, `OutOfOffice()`).
   - A **constructor** initializes attributes when an `Employee` object is created.

### 2. **Creating Employee Objects**
   - Three employee objects (`Employee1`, `Employee2`, `Employee3`) are instantiated with different attributes.
   - Their details are printed using `cout`, and relevant methods are called.

## 🎯 Key Takeaways
- 📌 **Classes define a blueprint** for objects, encapsulating attributes and behaviors.
- 🏗️ **Objects** instantiate classes with specific values.
- 🔄 **Methods** allow objects to perform actions.
- ⚙️ **Constructors** streamline object initialization.

This project demonstrates fundamental **Object-Oriented Programming (OOP) concepts** in C++, reinforcing real-world modeling through classes and objects. 🚀💼

