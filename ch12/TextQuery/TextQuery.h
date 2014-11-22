#ifndef TEXTQUERY_H
#define TEXTQUERY_H
#include <vector>
#include <string>
#include <fstream>
#include <memory>
#include <map>
#include <set>
#include "QueryResult.h"
using std::vector;
using std::string;
using std::ifstream;
using std::shared_ptr;
using std::map;
using std::set;

class QueryResult;
class TextQuery
{
public:
	using line_no_t = vector<string>::size_type;
	TextQuery(ifstream &infile);
	QueryResult query(const string &s);
private:
	shared_ptr<vector<string>> texts;
	map<string, shared_ptr<set<line_no_t>>> wd2no;
};
#endif//TEXTQUERY_H
