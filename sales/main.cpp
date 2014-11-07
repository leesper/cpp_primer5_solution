#include <iostream>
#include <fstream>
#include "Sales_data.h"
using namespace std;

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		cerr << "must specify input and output files" << endl;
		return -1;
	}

	ifstream fin(argv[1]);
	ofstream fout(argv[2], ofstream::out | ofstream::app);

	Sales_data total;
	if (read(fin, total))
	{
		Sales_data trans;
		while (read(fin, trans))
		{
			if (total.isbn() == trans.isbn())
			{
				total.combine(trans);
			}
			else
			{
				print(fout, total) << endl;
				total = trans;
			}
		}
		print(fout, total) << endl;
	}
	else
	{
		cerr << "no data?!" << endl;
		return -1;
	}
	fin.close();
	fout.close();
	return 0;
}
