
#include <iostream>
using namespace std;

class Employee {
public:
    string Name;
    string Title;
    int BaseSalary;
    //These are attribues that can be given to Employee objects
    void work() {
        cout << "This person is working right now\n";
    }
    void communicate() {
        cout << "This person is talking to their friend on the phone\n";
    }
    void OutOfOffice() {
        cout << "This person is currently not in the office\n";
    }
    //Methods are being initialised here for class Employee


    Employee(string Name, string Title, int BaseSalary) {
        this->Name = Name;
        this->Title = Title;
        this->BaseSalary = BaseSalary;
    }
    // this is a function that acts as a constructor
    // takes in parameters that it uses to assign to objects in the main function
};

int main()
{
    // object = A collection of attributes and methods
    //          They have characteristics that can perform actions
    //          Can be used to mimic real world items (eg. Phone, book)
    //          Created from a class which acts as a template or "blue-print"

    Employee Employee1("Shanawaz Bisath", "CEO of Schonfeld", 100000000000);
    //These set the values of the objects we initialised in constructor "Employee"
    cout << "Employee 1's name is " << Employee1.Name << "\n";
    cout << "Employee 1's Title is " << Employee1.Title << "\n";
    cout << "Employee 1's Base Salary is " << Employee1.BaseSalary << " GBP \n";
    Employee1.work();
    cout << endl;
    //these invoke the methods we initialised in the class "Employee"



    Employee Employee2("Jahedul Hoque", "End User Services Engineer", 1);
    //These set the values of the objects we initialised in class "Employee"
    cout << "Employee 2's name is " << Employee2.Name << "\n";
    cout << "Employee 2's Title is " << Employee2.Title << "\n";
    cout << "Employee 2's Base Salary is " << Employee2.BaseSalary << " GBP \n";
    Employee2.communicate();
    cout << endl;
    //these invoke the methods we initialised in the class "Employee"


  
    Employee Employee3("Emran Hussain", "Platforms Support Engineer", 70000);

    cout << "Employee 3's name is " << Employee3.Name << "\n";
    cout << "Employee 3's Title is " << Employee3.Title << "\n";
    cout << "Employee 3's Base Salary is " << Employee3.BaseSalary << " GBP \n";
    Employee3.OutOfOffice();
    cout << endl;
    //these invoke the methods we initialised in the class "Employee"
}


