#ifndef QUERYRESULT_H
#define QUERYRESULT_H
#include <memory>
#include <vector>
#include <string>
#include <set>
#include <iostream>
#include "TextQuery.h"
using std::ostream;
using std::set;
using std::string;
using std::vector;
using std::shared_ptr;

class QueryResult
{
friend ostream &operator<<(ostream &os, const QueryResult &res);
public:
	using line_no_t = vector<string>::size_type;
	QueryResult(
			string s,
			shared_ptr<vector<string>> t,
			shared_ptr<set<line_no_t>> l):
				sought(s), texts(t), line_nos(l) { }
	set<line_no_t>::iterator begin();
	set<line_no_t>::const_iterator cbegin();
	set<line_no_t>::iterator end();
	set<line_no_t>::const_iterator cend();
	shared_ptr<vector<string>> get_file() const;
private:
	string sought;
	shared_ptr<vector<string>> texts;
	shared_ptr<set<line_no_t>> line_nos;
};
ostream &operator<<(ostream &os, const QueryResult &res);
#endif//QUERYRESULT_H
