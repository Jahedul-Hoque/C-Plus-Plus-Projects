#include <iostream>
using namespace std;

double GetTotal(double prices[], int size) {
	double total = 0;
	for (int i = 0; i < size ;i ++) {
		total += prices[i];
	}
	return total;
	
}

void LoadTradingData(int TradeID, string TradeSymbol) {
	//function initialised
	cout << "Trade ID: " << TradeID << "\n";
	cout << "Trade Symbol: " << TradeSymbol << "\n";
	//passes in a variable called TradeID and Trade Symbol as parameters that are declared in "main" function.
	cout << "Trade Security: Gold\n";
	cout << "Trade Date: 12:05:2024\n";
	cout << "Trade Quantity: 234\n";
	cout << "Trade Price: 31235\n";
}

int main(){

	//function = a block of reusable code
	int TradeID = 1235;
	string TradeSymbol = "Schonfeld Securities";
	//declares variables that will be used to pass in as a parameter in the "LoadTradingData" function
	LoadTradingData(TradeID, TradeSymbol);
	
	
	//invokes the function
	double prices[] = { 235.34, 214.32, 543.34, 34.99 };
	int size = sizeof(prices) / sizeof(prices[0]);
	double total = GetTotal(prices, size);
	
	cout << "$" << total;
}


