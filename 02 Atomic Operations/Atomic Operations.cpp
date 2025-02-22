#include <iostream>
#include <thread>
#include <atomic>



int main()
{
	std::atomic <int> PortfolioValue = 0;
	auto trade = [&PortfolioValue] {
	// work will be a random data type and will use the reference counter
		for (int i = 0;i < 1000000; i++)
			PortfolioValue++;
		};


	std::thread t1(trade);
	std::thread t2(trade);
	// using 2 threads to increment counter at the same time


	t1.join();
	t2.join();
	// joining both threads together so that it doesnt exit code prematurely


	std::cout << "Your Portfolio value is " << PortfolioValue << " GBP.\n";
	return 0;
	
}

