#include <iostream>
using namespace std;


void LoadTradingData(int TradeID, string TradeSymbol) {
	//function initialised
	cout << "Trade ID: " << TradeID << "\n";
	cout << "Trade Symbol: " << TradeSymbol << "\n";
	//passes in a variable called TradeID as a parameter thats declared in "main" function.
	cout << "Trade Security: Gold\n";
	cout << "Trade Date: 12:05:2024\n";
	cout << "Trade Quantity: 234\n";
	cout << "Trade Price: 31235\n";
}
int main(){

	//function = a block of reusable code
	int TradeID = 1235;
	string TradeSymbol = "Schonfeld Securities";
	//declares a variable that will be used to pass in as a parameter in the "LoadTradingData" function
	LoadTradingData(TradeID, TradeSymbol);
	//invokes the function


}


