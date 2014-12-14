#ifndef STRVEC_H
#define STRVEC_H
#include <string>
#include <memory>
#include <utility>
#include <initializer_list>
using std::string;
using std::allocator;
using std::pair;
using std::initializer_list;
class StrVec
{
public:
	StrVec():
		elements(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(const initializer_list<string> &ilst);
	// copy-control members
	StrVec(const StrVec&);
	StrVec &operator=(const StrVec&);
	~StrVec();
	StrVec(StrVec &&) noexcept;
	StrVec &operator=(StrVec &&) noexcept;
	StrVec &operator=(const initializer_list<string> &ilst);
	void push_back(const string&);
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	string *begin() const { return elements; }
	string *end() const { return first_free; }
	void reserve(const size_t);
	void resize(const size_t);
	void resize(const size_t, const string&);
	string& operator[](size_t n) { return elements[n]; }
	const string& operator[](size_t n) const { return elements[n]; }
private:
	static allocator<string> alloc;
	void chk_n_alloc()
		{ if (size() == capacity()) reallocate(); }
	pair<string*, string*> alloc_n_copy(const string*, const string*);
	void free();
	void reallocate();
	string *elements;
	string *first_free;
	string *cap;
};
#endif//STRVEC_H
