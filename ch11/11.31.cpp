#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

int main()
{
	multimap<string, string> authors;
	authors.insert({"Sun Haohui", "The Great Qin Empire"});
	authors.insert({"Sun Haohui", "The Noble On Horse"});
	authors.insert({"Robert Sedgewick", "Algorithms"});
	authors.insert({"Robert Sedgewick", "Algorithms in C"});
	authors.insert({"Mark Summerfield", "The Go Programming Language"});
	authors.insert({"Mark Summerfield", "Rapid GUI Programming with PyQt"});
	authors.insert({"Mark Summerfield", "Qt4 Programming"});
	authors.insert({"Donald Knuth", "The Art of Computer Programming I"});
	authors.insert({"Donald Knuth", "The Art of Computer Programming II"});

	string delK = "Donald Knuth";
	if (authors.find(delK) != authors.end())
	{
		auto removed = authors.erase(delK);
		cout << removed << " removed" << endl;
	}

	set<string> keys;
	for (auto iter = authors.begin(); iter != authors.end(); ++iter)
	{
		keys.insert(iter->first);
	}

	for (auto key_iter = keys.begin(); key_iter != keys.end(); ++key_iter)
	{
		cout << *key_iter << ": ";
		for (auto pos = authors.equal_range(*key_iter);
				pos.first != pos.second; ++pos.first)
			cout << pos.first->second << " ";
		cout << endl;
	}

	return 0;
}
