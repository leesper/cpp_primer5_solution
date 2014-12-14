#ifndef STRING_H
#define STRING_H
#include <memory>
#include <iostream>
#include <utility>
using std::allocator;
using std::ostream;
using std::pair;
class String
{
	friend ostream& operator<<(ostream &os, const String &str);
	friend bool operator==(const String &lhs, const String &rhs);
	friend bool operator!=(const String &lhs, const String &rhs);
public:
	String(): elements(nullptr), first_free(nullptr), cap(nullptr) {}
	String(const char *cstr);
	String(const String& rhs);
	String& operator=(const String& rhs);
	~String();
	String(String &&rhs) noexcept;
	String& operator=(String &&rhs) noexcept;
	void push_back(const char c);
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	char *begin() const { return elements; }
	char *end() const { return first_free; }
	char& operator[](size_t n) { return elements[n]; }
	const char& operator[](size_t n) const { return elements[n]; }
private:
	pair<char*, char*> alloc_n_copy(const char *b, const char *e);
	void free();
	void chk_n_alloc();
	void reallocate();
	static allocator<char> alloc;
	char *elements;
	char *first_free;
	char *cap;
};

ostream& operator<<(ostream &os, const String &str);
bool operator==(const String &lhs, const String &rhs);
bool operator!=(const String &lhs, const String &rhs);

#endif//STRING_H
