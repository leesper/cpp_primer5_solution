#include <iostream>
#include <vector>
#include "String.h"
using namespace std;

int main()
{
	String empty;
	String computer("computer");
	cout << computer << endl;
	empty.push_back('a');
	empty.push_back('c');
	empty.push_back('e');
	cout << empty << endl;
	vector<String> Svec;
	Svec.push_back(computer);
	Svec.push_back(empty);
	Svec.push_back("king");
	Svec.push_back("kong");
	return 0;
}
