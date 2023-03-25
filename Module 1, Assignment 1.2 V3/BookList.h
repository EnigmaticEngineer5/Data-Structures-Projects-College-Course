#pragma once

#include <iostream>
#include <string>
using namespace std;

static constexpr const int MAX_CAPACITY{ 5 };
class BookList final {
private:
	int top;
	string books[MAX_CAPACITY];

public:
	BookList();
	BookList(const string[], const int);
	BookList(const BookList&);
	~BookList();

	const bool isEmpty() const;
	const bool isFull() const;
	const int getCurrentSize() const;
	const bool addBook(const string);
	const int containsBook(const string) const;
	const bool removeBook(const string);

	void displayBooks() const;
	string& operator [] (const int&);
	friend istream& operator >> (istream&, BookList&);
	friend ostream& operator << (ostream&, const BookList&);
};