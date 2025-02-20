#include <iostream>
#include <thread>



int main()
{
	int counter = 0;
	auto work = [&counter] {
	// work will be a random data type and will use the reference counter
		for (int i = 0;i < 100; i++)
			counter++;
		};


	std::thread t1(work);
	std::thread t2(work);
	// using 2 threads to increment counter at the same time


	t1.join();
	t2.join();
	// joining both threads together


	std::cout << counter << "\n";
	return 0;
	///
}

