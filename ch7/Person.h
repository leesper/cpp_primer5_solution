#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>
#include <string>
class Person
{
friend std::istream &read(std::istream &is, Person &person);
friend std::ostream &print(std::ostream &os, const Person &person);
public:
	Person() = default;
	Person(const std::string name, const std::string addr) : name_(name), addr_(addr) {}
	Person(const std::string name) : name_(name) {}
	Person(const std::string addr) : addr_(addr) {}
	std::string name() const { return name_; }
	std::string addr() const { return addr_; }
private:
	std::string name_;
	std::string addr_;
};
std::istream &read(std::istream &is, Person &person)
{
	is >> person.name_ >> person.addr_;
	return is;
}

std::ostream &print(std::ostream &os, const Person &person)
{
	os << person.name() << " " << person.addr();
	return os;
}
#endif//PERSON_H
