#ifndef BLOBPTR_H
#define BLOBPTR_H
#include <string>
#include <memory>
#include <vector>
#include <stdexcept>
#include "blob.h"
using std::string;
using std::weak_ptr;
using std::vector;
using std::shared_ptr;
using std::runtime_error;
class StrBlobPtr
{
friend StrBlobPtr operator+(StrBlobPtr &lhs, const size_t offset);
friend ptrdiff_t operator-(StrBlobPtr &lhs, StrBlobPtr &rhs);
public:
	StrBlobPtr(): curr(0) {}
	StrBlobPtr(StrBlob &a, std::size_t sz = 0):
		wptr(a.data), curr(sz) {}
	string &deref() const;
	StrBlobPtr& operator++();
	StrBlobPtr& operator--();
	StrBlobPtr operator++(int);
	StrBlobPtr operator--(int);
	string operator*() const;
	string *operator->() const;
private:
	shared_ptr<vector<string>>
		check(size_t i, const string& msg) const;
	weak_ptr<vector<string>> wptr;
	size_t curr;
};
StrBlobPtr operator+(StrBlobPtr &lhs, const size_t offset);
ptrdiff_t operator-(StrBlobPtr &lhs, StrBlobPtr &rhs);
#endif//BLOBPTR_H
