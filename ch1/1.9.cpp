#include <iostream>

int main() 
{
	int val = 50, sum = 0;
	while (val <= 100)
	{
		sum += val;
		++val;
	}
	std::cout << "50 + ... + 100 = " << sum << std::endl;
}