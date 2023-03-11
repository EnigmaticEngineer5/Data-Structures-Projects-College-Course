#pragma once

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::istream;
using std::ostream;
using std::ws;
using std::numeric_limits;
using std::streamsize;
using std::swap;

class BookInfo
{
private:
	string title, author, publisher;

public:
	BookInfo();
	BookInfo(const string, const string, const string);
	BookInfo(const BookInfo&);
	~BookInfo();

	BookInfo& setTitle(const string);
	BookInfo& setAuthor(const string);
	BookInfo& setPublisher(const string);
	void setBookInfo(const string, const string, const string);

	const string getTitle() const;
	const string getAuthor() const;
	const string getPublisher() const;

	friend istream& operator >> (istream&, BookInfo&);
	friend ostream& operator << (ostream&, const BookInfo&);
};