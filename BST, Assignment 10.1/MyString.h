#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>
#include <cstdlib> // For exit() function
#include<string>
using namespace::std;
class MyString {
private:
	char* str;
	int len;
public:
	// Constructors
	MyString(); // { str = ""; len = 0; }
	MyString(const char*);
	MyString(const MyString&);
	// Destructor
	~MyString() { if (len != 0) delete[] str; }
	// Various member functions and operators
	int length() { return len; }
	char* data() { return str; };
	MyString operator+=(MyString);
	MyString operator=(MyString);
	// Various overloaded operators
	friend bool operator==(MyString, MyString);
	friend bool operator!=(MyString, MyString);
	friend bool operator>(MyString, MyString);
	friend bool operator<(MyString, MyString);
	friend bool operator>=(MyString, MyString);
	friend bool operator<=(MyString, MyString);
	friend ostream& operator<<(ostream&, MyString);
	friend istream& operator>>(istream&, MyString&);
};
#endif
