#pragma once

#include <iostream>
#include <cstring>

using std::istream;
using std::ostream;
using std::numeric_limits;
using std::streamsize;
using std::cout;

class MyString
{
private:
	char* str;

public:
	MyString(const char* sourceStr = nullptr);
	MyString(const MyString&);
	MyString(MyString&&) noexcept;

	MyString& operator = (const MyString&);
	MyString& operator = (MyString&&) noexcept;

	const bool operator == (const MyString&) const;
	const bool operator != (const MyString&) const;
	const bool operator > (const MyString&) const;
	const bool operator < (const MyString&) const;

	friend istream& operator >> (istream&, MyString&);
	friend ostream& operator << (ostream&, const MyString&);

	const size_t getStrSize() const;
	char* getStr() const;

	~MyString();
};