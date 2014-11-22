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
public:
	StrBlobPtr(): curr(0) {}
	StrBlobPtr(StrBlob &a, std::size_t sz = 0):
		wptr(a.data), curr(sz) {}
	string &deref() const;
	StrBlobPtr &incr(); // prefix version
private:
	shared_ptr<vector<string>>
		check(size_t i, const string& msg) const;
	weak_ptr<vector<string>> wptr;
	size_t curr;
};
#endif//BLOBPTR_H
