#include "MyString.h"
MyString::MyString()
{
	char tmp[] = "";
	len = strlen(tmp);
	str = new char[len + 1];
	strcpy_s(str, len + 1, tmp);
}
MyString::MyString(const char* sptr)
{
	len = strlen(sptr);
	str = new char[len + 1];
	strcpy_s(str, len + 1, sptr);
}
MyString::MyString(const MyString& right)
{
	str = new char[right.len + 1];
	strcpy_s(str, right.len + 1, right.str);
	len = right.len;
}
MyString MyString::operator=(MyString right)
{
	if (len != 0) delete[] str;
	str = new char[right.len + 1];
	strcpy_s(str, right.len + 1, right.str);
	len = right.len;
	return *this;
}
MyString MyString::operator+=(MyString right)
{
	char* temp = str;
	str = new char[len + right.len + 1];
	strcpy_s(str, len + right.len + 1, temp);
	strcat_s(str, len + right.len + 1, right.str);
	if (len != 0) delete[] temp;
	len += right.len;
	return *this;
}
bool operator==(MyString left, MyString right)
{
	return strcmp(left.str, right.str) == 0;
}
bool operator!=(MyString left, MyString right)
{
	return strcmp(left.str, right.str) != 0;
}
bool operator>(MyString left, MyString right)
{
	return (strcmp(left.str, right.str) > 0);
}
bool operator<(MyString left, MyString right)
{
	return (strcmp(left.str, right.str) < 0);
}
bool operator>=(MyString left, MyString right)
{
	return (strcmp(left.str, right.str) >= 0);
}
bool operator<=(MyString left, MyString right)
{
	return (strcmp(left.str, right.str) <= 0);
}
ostream& operator<<(ostream& strm, MyString obj)
{
	strm << obj.str;
	return strm;
}
istream& operator>>(istream& strm, MyString& obj)
{
	// Read the MyString
	char buffer[256];
	cin.ignore();
	strm.getline(buffer, 256);
	// Invoke the convert constructor and overloaded assignment
	obj = buffer;
	return strm;
}