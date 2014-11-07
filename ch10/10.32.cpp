#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>
#include "Sales_item.h"
using namespace std;
using namespace std::placeholders;

int main()
{
	istream_iterator<Sales_item> in(cin), eof;
	vector<Sales_item> trans;
	while (in != eof)
	{
		trans.push_back(*in++);
	}

	sort(trans.begin(), trans.end(),
			[](const Sales_item &item1, const Sales_item &item2) -> bool
			{ return item1.isbn() <= item2.isbn(); });

	auto begin_iter = trans.begin();
	while(begin_iter != trans.end())
	{
		auto not_equal = [](const Sales_item &item1, const Sales_item &item2) -> bool
				{ return item1.isbn() != item2.isbn(); };
		// find the first position in remaining that's not equal to *begin_iter
		auto end_iter = find_if(begin_iter, trans.end(),
				bind(not_equal, _1, *begin_iter));

		Sales_item total(begin_iter->isbn());
		total = accumulate(begin_iter, end_iter, total);
		cout << total << endl;
		begin_iter = end_iter;
	}
	return 0;
}
