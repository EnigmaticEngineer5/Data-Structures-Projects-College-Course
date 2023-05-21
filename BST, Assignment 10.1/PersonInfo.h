#pragma once

#include "MyString.h"
#include "Date.h"

class PersonInfo
{
private:
	MyString name;
	Date birhday;

public:
	PersonInfo();
	PersonInfo(MyString, Date);
	PersonInfo(const PersonInfo&);
	~PersonInfo();
	PersonInfo& operator = (const PersonInfo&);

	PersonInfo& setName(const MyString);
	PersonInfo& setBirthday(const Date);
	const MyString getName() const;
	const Date getBirthday() const;

	const bool operator == (const PersonInfo&) const;
	const bool operator != (const PersonInfo&) const;
	const bool operator > (const PersonInfo&) const;
	const bool operator < (const PersonInfo&) const;

	friend istream& operator >> (istream&, PersonInfo&);
	friend ostream& operator << (ostream&, const PersonInfo&);
};

