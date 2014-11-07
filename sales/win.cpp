#include <iostream>
#include "window.h"
using namespace std;
int main()
{
	Screen myScreen(5, 5);
	myScreen.move(4, 0).set('#').display(cout);
	cout << "\n";
	myScreen.display(cout);
	cout << "\n";
	return 0;
}
