#include <iostream>
#include "Sales_item.h"

int main() 
{
	Sales_item item, curr_item;
	int cnt;
	if (std::cin >> curr_item)
	{
		cnt = 1;
		while (std::cin >> item)
		{
			if (item.isbn() == curr_item.isbn())
			{
				++cnt;
			}
			else
			{
				std::cout << "Book " << curr_item.isbn() << " occurs " << cnt << std::endl;
				curr_item = item;
				cnt = 1;
			}
		}
	}
	else
	{
		std::cout << "No transactions" << std::endl;
		return -1;
	}
	std::cout << "Book " << curr_item.isbn() << " occurs " << cnt << std::endl;
	return 0;
}