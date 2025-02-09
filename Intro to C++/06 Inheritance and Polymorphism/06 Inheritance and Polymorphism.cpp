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

class TechEmployee:public Employee {
    //this makes a class called TechEmployee that can access all the attributes and methods of parent class "Employee"
public:
   
    string FavouriteGame;


    TechEmployee(string name, string FavouriteGame, string ApplicationUsed, int salary) {
        this->name = name;
        this->FavouriteGame = FavouriteGame;
        this->ApplicationUsed = ApplicationUsed;
        this->salary = salary;
    }
    //made a constructor for the parameters "name, Favourite Game, Application used often and Salary"
    void Developing(){
        cout << "The employee is currently working on some code\n";
    }


};

class InvestmentEmployee :public Employee {
    //this makes a class called InvestmentEmployee that can access all the attributes and methods of parent class "Employee"
public:
    string FavouriteSecurity;

    InvestmentEmployee(string name, string FavouriteSecurity, string ApplicationUsed, int salary) {
        this->name = name;
        this->FavouriteSecurity = FavouriteSecurity;
        this->ApplicationUsed = ApplicationUsed;
        this->salary = salary;
    }
    //made a constructor for the parameters "name, Favourite Security, Application used often and Salary"


    void Trading() {
        cout << "This Employee is currently trading using Bloomberg\n";
    }

};



int main()
{
    InvestmentEmployee InvestmentEmployee1("Vikesh", "Gold", "Bloomberg", 82379283);
    // We invoke constructors off the child class to gain properties of the parent class
    cout << "Name of Employee: " << InvestmentEmployee1.name << "\n";
    cout << "Name of Favourite Security: " << InvestmentEmployee1.FavouriteSecurity << "\n";
    cout << "Name of Application they use often: " << InvestmentEmployee1.ApplicationUsed << "\n";
    cout << "Salary: " << InvestmentEmployee1.salary << " GBP \n";
    InvestmentEmployee1.Trading();

    
    TechEmployee TechEmployee1("Jad", "League of Legends", "C++" , 10);
    // We invoke constructors off the child class to gain properties of the parent class
    cout << "Name of Employee: " << TechEmployee1.name << "\n";
    cout << "Name of Favourite Game: " << TechEmployee1.FavouriteGame << "\n";
    cout << "Name of Application they use often: " << TechEmployee1.ApplicationUsed << "\n";
    cout << "Salary: " << TechEmployee1.salary << " GBP \n";
    TechEmployee1.Developing();

    // This is how Vikesh and Jad can both access the public methods in Parent class
    // They both also have exlcusive attributes/methods like "Favourite Game" attribute or "Trading" method built in their own child class

}

