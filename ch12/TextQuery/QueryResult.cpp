#include <iostream>
#include "QueryResult.h"
using namespace std;

ostream &operator<<(ostream &os, const QueryResult &res)
{
	os << res.sought << " occurs " << res.line_nos->size() << " "
	   << (res.line_nos->size() > 1 ? "times" : "time") << endl;

	for (auto line_no : *res.line_nos)
		os << "\t(line " << line_no + 1 << ") " << *(res.texts->begin() + line_no) << endl;
	return os;
}

set<QueryResult::line_no_t>::iterator QueryResult::begin()
{
	return line_nos->begin();
}

set<QueryResult::line_no_t>::const_iterator QueryResult::cbegin()
{
	return line_nos->cbegin();
}

set<QueryResult::line_no_t>::iterator QueryResult::end()
{
	return line_nos->end();
}

set<QueryResult::line_no_t>::const_iterator QueryResult::cend()
{
	return line_nos->cend();
}

shared_ptr<vector<string>> QueryResult::get_file() const
{
	return texts;
}
