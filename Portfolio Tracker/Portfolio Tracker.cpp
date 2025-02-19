#include <iostream>
#include <vector> // allows creating dynamic arrays
#include <cstdlib> // generating random numbers
#include <ctime> // seeding random numbers with the current time and using modulus to make a random small number
#include <iomanip> // formatting output and aligning table collumns
//NOT using STD namespace as i've started using lots of new keywords that may be used in other namespaces

struct Stock {
    std::string ticker;
    double quantity;
    double price;
};

// Function to simulate real-time stock price changes
double getRandomPrice(double basePrice) {
    double change = ((rand() % 2001) - 1000) / 10000.0; // Random change between -10% and +10%
    return basePrice * (1 + change);
}

void displayPortfolio(const std::vector<Stock>& portfolio) {
    double totalValue = 0.0;
    std::cout << "\n Portfolio Overview\n";
    std::cout << "-----------------------------------------\n";
    std::cout << std::left << std::setw(10) << " Stock" << std::setw(10) << "Qty" << std::setw(10) << "Price" << std::setw(15) << "Total Value" << "\n";
    std::cout << "--------------------------------------\n";

    for (const auto& StockObject : portfolio) { //creates a temporary variable that stores 1 object from portfolios list of objects
        double updatedPrice = getRandomPrice(StockObject.price);
        // Variable updatedPrice is equal to 
        double totalStockValue = updatedPrice * StockObject.quantity;
        totalValue += totalStockValue;

        std::cout << std::left << std::setw(10) << StockObject.ticker  << std::setw(10) << StockObject.quantity << std::setw(10) << std::fixed << std::setprecision(2) << updatedPrice  << std::setw(15) << totalStockValue << "\n";
    }

    std::cout << "--------------------------------------\n";
    std::cout << " Total Portfolio Value: $" << totalValue << "\n";
}

int main() {
    srand(time(0)); 
    // time(0) will tell you the current time - srand(time(0)) will give you a new random number based on a formula using the current time in seconds
    
    std::vector<Stock> portfolio = {
        {" AAPL", 10, 175.0},{" MSFT", 5, 320.0}, {" GOOGL", 8, 2800.0}, {" TSLA", 12, 720.0}
    };
    // creates a vector of stock objects and puts it inside portfolio
    char choice;
    do {
        displayPortfolio(portfolio);

        std::cout << "\n Refresh prices? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');
   
        std::cout << " Exiting portfolio tracker. Happy investing!\n";
        return 0;
    
} 
