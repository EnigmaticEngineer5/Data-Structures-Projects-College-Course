#pragma once

#include <iostream>
#include <string>

class BookList
{
private:
	static constexpr const int MAX_CAPACITY{ 5 };
	int top;
	std::string books[MAX_CAPACITY];

public:
	BookList();
	BookList(const std::string[], const int);
	BookList(const BookList&);

	const bool isEmpty() const;
	const bool isFull() const;
	const int getCurrentSize() const;
	const bool addBook(const std::string);
	const int containsBook(const std::string) const;
	const bool removeBook(const std::string);
	void displayBooks() const;

	std::string& operator [] (const int&);
	friend std::istream& operator >> (std::istream&, BookList&);
	friend std::ostream& operator << (std::ostream&, const BookList&);

	~BookList();
};