#include <iostream>
#include <stdexcept>
using namespace std;
int main()
{
	int num1, num2;
	cin >> num1;
	while (cin >> num2)
	{
		try
		{
			if (num2 == 0)
				throw runtime_error("divide by zero");
			cout << num1 << " / " << num2 << " == " << num1 / num2 << endl;
			break;
		}
		catch (runtime_error err)
		{
			cout << err.what()
				 << "\nPlease input again" << endl;
		}
	}
	return 0;
}