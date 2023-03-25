#include "MyString.h"

MyString::MyString(const char* sourceStr)
{
	if (sourceStr == nullptr) {
		this->str = nullptr;
	}
	else {
		this->str = new char[(strlen(sourceStr) + 1)];
		strncpy_s(this->getStr(), (strlen(sourceStr) + 1), sourceStr, (strlen(sourceStr) + 1));
		sourceStr = nullptr;
	}
}

MyString::MyString(const MyString& sourceStr)
{
	if (sourceStr.getStr() == nullptr) {
		this->str = nullptr;
	}
	else {
		this->str = new char[(sourceStr.getStrSize() + 1)];
		strncpy_s(this->getStr(), (sourceStr.getStrSize() + 1), sourceStr.getStr(), (sourceStr.getStrSize() + 1));
	}
}

MyString::MyString(MyString&& sourceStr) noexcept : str(sourceStr.getStr())
{
	sourceStr.str = nullptr;
}

MyString& MyString::operator=(const MyString& sourceStr)
{
	if (this != &sourceStr) {
		if (this->getStr() != nullptr) {
			delete[] this->getStr();
		}

		if (sourceStr.getStr() == nullptr) {
			this->str = nullptr;
		}
		else {
			this->str = new char[(sourceStr.getStrSize() + 1)];
			strncpy_s(this->getStr(), (sourceStr.getStrSize() + 1), sourceStr.getStr(), (sourceStr.getStrSize() + 1));
		}
	}

	return *this;
}

MyString& MyString::operator=(MyString&& sourceStr) noexcept
{
	if (this != &sourceStr) {
		if (this->getStr() != nullptr) {
			delete[] this->getStr();
		}

		if (sourceStr.getStr() == nullptr) {
			this->str = nullptr;
		}
		else
		{
			this->str = sourceStr.getStr();
			sourceStr.str = nullptr;
		}
	}

	return *this;
}

const bool MyString::operator==(const MyString& sourceStr) const
{
	return (strcmp(this->getStr(), sourceStr.getStr()) == 0);
}

const bool MyString::operator!=(const MyString& sourceStr) const
{
	return (strcmp(this->getStr(), sourceStr.getStr()) != 0);
}

const bool MyString::operator>(const MyString& sourceStr) const
{
	return (strcmp(this->getStr(), sourceStr.getStr()) > 0);
}

const bool MyString::operator<(const MyString& sourceStr) const
{
	return (strcmp(this->getStr(), sourceStr.getStr()) < 0);
}

const size_t MyString::getStrSize() const
{
	return (strlen(this->getStr()));
}

char* MyString::getStr() const
{
	return this->str;
}

MyString::~MyString()
{
	if (this->getStr() != nullptr) {
		delete[] this->getStr();
		this->str = nullptr;
	}
}

istream& operator>>(istream& input, MyString& sourceString)
{
	char buffer[4096];
	input.getline(buffer, (sizeof(buffer)));

	if (buffer[0] == ' ' || buffer[0] == '\0') {
		cout << "\nInvalid empty entry, re-enter string --> ";
		input >> sourceString;
	}

	sourceString = MyString(buffer);

	return input;
}

ostream& operator<<(ostream& output, const MyString& sourceString)
{
	if (sourceString.getStr() == nullptr) {
		return output;
	}

	return (output << sourceString.getStr());
}