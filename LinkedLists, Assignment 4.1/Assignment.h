#pragma once

#include "Date.h"
#include <string>

class Assignment
{
private:
	string description;
	Date dueDate;

public:
	Assignment(const string = "", const Date = NULL);
	Assignment(const Assignment&);
	~Assignment();
	Assignment& operator = (const Assignment&);

	Assignment& setDescription(const string);
	Assignment& setDate(const Date);

	const string getDescription() const;
	const Date getDate() const;

	const bool operator == (const Assignment&) const;
	const bool operator == (const Date&);

	const bool operator != (const Assignment&) const;
	const bool operator > (const Assignment&) const;
	const bool operator < (const Assignment&) const;
	const bool operator <= (const Assignment&) const;

	friend istream& operator >> (istream&, Assignment&);
	friend ostream& operator << (ostream&, const Assignment&);
};