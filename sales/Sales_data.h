#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>
#include <iostream>

class Sales_data
{
friend std::istream& read(std::istream &is, Sales_data &s);
friend std::ostream& print(std::ostream &os, const Sales_data &s);
friend Sales_data add(const Sales_data &s1, const Sales_data &s2);
public:
	Sales_data() = default;
	Sales_data(const std::string &s): bookNo(s) {}
	Sales_data(const std::string &s, unsigned n, double p):
		bookNo(s), units_sold(n), revenue(n * p) {}
	Sales_data(std::istream &is) { read(is, *this); }
	std::string isbn() const { return bookNo; }
	void combine(const Sales_data &other);
private:
	double avg_price() const
		{ return units_sold ? revenue / units_sold : 0; }
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
std::istream& read(std::istream &is, Sales_data &s);
std::ostream& print(std::ostream &os, const Sales_data &s);
Sales_data add(const Sales_data &s1, const Sales_data &s2);

void Sales_data::combine(const Sales_data &other)
{
	if (bookNo != other.bookNo)
		return;
	units_sold += other.units_sold;
	revenue += other.revenue;
}

Sales_data add(const Sales_data &s1, const Sales_data &s2)
{
	Sales_data result;
	result.combine(s1);
	result.combine(s2);
	return result;
}

std::istream& read(std::istream &is, Sales_data &s)
{
	is >> s.bookNo >> s.units_sold >> s.revenue;
	return is;
}

std::ostream& print(std::ostream &os, const Sales_data &s)
{
	os << "isbn: " << s.bookNo << " "
	   << "units sold: "<< s.units_sold << " "
	   << "revenue: " << s.revenue;
	return os;
}

#endif//SALES_DATA_H
