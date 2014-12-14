#ifndef BLOB_H
#define BLOB_H
#include <vector>
#include <initializer_list>
#include <memory>
#include <stdexcept>
#include <string>
using std::vector;
using std::string;
using std::initializer_list;
using std::shared_ptr;
using std::make_shared;
using std::out_of_range;
using std::weak_ptr;
using std::runtime_error;

class StrBlobPtr;
class StrBlob
{
	friend class StrBlobPtr;
public:
	using size_type = vector<string>::size_type;
	StrBlob();
	StrBlob(initializer_list<string> il);
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(const string &t) { data->push_back(t); }
	void pop_back();
	string& front();
	const string& front() const;
	const string& back() const;
	string& back();
	StrBlobPtr begin();
	StrBlobPtr end();
private:
	shared_ptr<vector<string>> data;
	void check(size_type i, const string &msg) const;
};

#endif//BLOB_H
