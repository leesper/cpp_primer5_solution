#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <map>
using namespace std;

class Date
{
public:
	Date(const string &dt);
	unsigned year() const { return year_; }
	void year(unsigned yr) { year_ = yr;}
	unsigned month() const { return month_; }
	void month(unsigned m) { month_ = m; }
	unsigned day() const { return day_; }
	void day(unsigned d) { day_ = d;}
	string toString() const;
private:
	unsigned year_;
	unsigned month_;
	unsigned day_;
	unsigned parseMonth(const string &mon);
	unsigned parseDay(const string &day);
	unsigned parseYear(const string &yr);
};

Date::Date(const string &dt):
		year_(0),
		month_(0),
		day_(0)
{
	string tmp = dt;
	while (tmp.find("/") != tmp.npos)
	{
		tmp[tmp.find("/")] = ' ';
	}
	istringstream iss(tmp);
	string first, middle, last;
	iss >> first >> middle >> last;
	month_ = parseMonth(first);
	day_ = parseDay(middle);
	year_ = parseYear(last);
}

unsigned Date::parseMonth(const string &mon)
{
	unsigned month;
	if (isdigit(mon[0]))
	{
		 month = stoi(mon, nullptr, 10);
	}
	else
	{
		map<string, unsigned> month2num;
		month2num["Jan"] = 1;
		month2num["Feb"] = 2;
		month2num["Mar"] = 3;
		month2num["Apr"] = 4;
		month2num["May"] = 5;
		month2num["Jun"] = 6;
		month2num["Jul"] = 7;
		month2num["Aug"] = 8;
		month2num["Sep"] = 9;
		month2num["Oct"] = 10;
		month2num["Nov"] = 11;
		month2num["Dec"] = 12;
		month = month2num[mon.substr(0, 3)];
	}
	return month;
}

unsigned Date::parseDay(const string &day)
{
	return stoi(day, nullptr, 10);
}

unsigned Date::parseYear(const string &yr)
{
	return stoi(yr, nullptr, 10);
}

string Date::toString() const
{
	ostringstream dmp;
	dmp << " year: " << year_
		<< " month: " << month_
		<< " day: " << day_;
	return dmp.str();
}

int main()
{
	Date d1("January 1, 1900");
	Date d2("Jan 1, 1900");
	Date d3("1/1/1900");
	cout << d1.toString() << endl
		 << d2.toString() << endl
		 << d3.toString() << endl;
	return 0;
}
