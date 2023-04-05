#pragma once

#include <iostream>
using namespace std;

class Date
{
private:
	int month, day, year;

public:
	Date(int = 0, int = 0, int = 0);
	Date(const Date&);
	~Date();
	Date& operator = (const Date&);

	Date& setMonth(const int);
	Date& setDay(const int);
	Date& setYear(const int);
	const int getMonth() const;
	const int getDay() const;
	const int getYear() const;

	const bool operator == (const Date&) const;
	const bool operator != (const Date&) const;
	const bool operator > (const Date&) const;
	const bool operator < (const Date&) const;
	const bool operator <= (const Date&) const;

	friend istream& operator >> (istream&, Date&);
	friend ostream& operator << (ostream&, const Date&);
};