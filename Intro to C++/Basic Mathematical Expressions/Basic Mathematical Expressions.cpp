#include <iostream>

int main()
{
	int x = 10;
	int y = x++; // x will be assigned to y - and then will be incremented by 1
	int c = x;

	
	std::cout << c; //c will be given the value of 11 and y will be given the value of 10

	int z = ++c; //z will be given the value of 12 as the value of c was incrememented before being assigned to z

	double j = 1 + 2 * 3; // following bidmas, j will be given the value of 7
	std::cout << j;
	
}
