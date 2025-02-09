#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	int x = 10;
	int y = x++; // x will be assigned to y - and then will be incremented by 1
	int c = x;


	cout << "C is equal to " << c << endl; //c will be given the value of 11 and y will be given the value of 10

	int z = ++c; //z will be given the value of 12 as the value of c was incrememented before being assigned to z

	double j = 1 + 2 * 3; // following bidmas, j will be given the value of 7
	cout << "j is equal to " << j << endl;
	cout << endl;
	
	
	//Excerise 1: Imagine you have a business that generates $95,000 worth of revenue. You need to pay 4% state tax and 2% county tax. Make a program that calculuates your net sales

	double sales = 95000;
	cout << "Sales is generating $" << sales << endl;

	double const StateTaxRate = 0.04; //it is best practice to use a constant variable when the value will never change after initialising
	double StateTax = sales * StateTaxRate; //we may use the StateTaxRate in multiple areas so it is best to have a single place to declare the value and then change the variable here
	cout << "State Tax: $" << StateTax << endl;

	double const CountyTaxRate = 0.02; //it is best practice to use a constant variable when the value will never change after initialising
	double CountyTax = sales * CountyTaxRate; //we may use the StateTaxRate in multiple areas so it is best to have a single place to declare the value and then change the variable here
	cout << "County Tax: $" << CountyTax << endl;

	double TotalTax = StateTax + CountyTax; //make the program like a story and seperate it with a line for best practice
	cout << "Total tax is $" << TotalTax<< endl; 

	sales = sales - TotalTax;
	cout << "Therefore the net sales will be $" << sales << endl;
	cout << endl;

	//Excercise 2: Make a basic calculator that takes in a temperature in Fahrenheit and converts it into celcius

	cout << "Fahrenheit: ";
	int fahrenheit;
	cin >> fahrenheit;
	double celsius = (fahrenheit - 32) / 1.8;
	cout << "Temperature is: " << celsius << endl;
	cout << endl;

	double result = floor(1.2); 
	//uses the cmath library to call upon the function floor which rounds down to the nearest number making 1.2 become 1
	cout << result << endl;
	cout << endl;

	srand(time(0));
	int randomNum = rand() % 5;
	/* time function gives us the current seconds since january 1st 1970
	if we feed that into srand, we can use the modulus function to reduce the size of the random number to the remainer of the divison of 5
	this allows us to create a random number from 0-5 inclusive
	*/
	cout << randomNum << endl;
}

