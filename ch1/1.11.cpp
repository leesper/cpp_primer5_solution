#include <iostream>

int main()
{
	std::cout << "Enter two numbers: " << std::endl;
	int v1, v2;
	std::cin >> v1 >> v2;
	while (v1 <= v2) 
	{
		std::cout << v1 << std::endl;
		++v1;
	}
}