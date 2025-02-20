#include <iostream>
#include <thread>



int main()
{
	int counter = 0;
	auto work = [&counter] {
		for (int i = 0;i < 100; i++)
			counter++;
		};

	std::thread t1(work);

	std::thread t2(work);

	t1.join();
	t2.join();


	std::cout << counter << "\n";
	return 0;
}

