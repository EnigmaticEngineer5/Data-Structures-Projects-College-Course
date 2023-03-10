#pragma once

#include "BookInfo.h"

template <class T, const int MAX_CAPACITY = 5>
class BookList
{
private:
	size_t top;
	T books[MAX_CAPACITY];

public:
	BookList();
	BookList(const T[], const size_t);
	BookList(const BookList&);

	const bool isEmpty() const;
	const bool isFull() const;
	const size_t getCurrentSize() const;
	const bool addBook(const T);
	const size_t containsBook(const std::string) const;
	const bool removeBook(const std::string);
	void displayBooks() const;

	T& operator [] (const int&);

	friend istream& operator >> (istream& input, BookList<T>& sourceList)
	{
		if (sourceList.isFull())
		{
			std::cout << "\nList is full...";
			return input;
		}

		BookInfo bookToAdd{};
		cin >> bookToAdd;
		sourceList.addBook(bookToAdd);

		return input;
	}

	friend ostream& operator << (ostream& output, const BookList<T>& sourceList)
	{
		std::cout << "\nThe books saved on the list are:";
		for (size_t i{}; i < sourceList.getCurrentSize(); i++)
		{
			cout << sourceList.books[i] << '\n';
		}

		return output;
	}

	~BookList();
};

template<class T, int MAX_CAPACITY>
inline BookList<T, MAX_CAPACITY>::BookList() : books{}, top{} { /*cout << "\nBookList default constructor invoked...";*/ };

template<class T, int MAX_CAPACITY>
inline BookList<T, MAX_CAPACITY>::BookList(const T sourceBooks[], const size_t sourceTop) : top{ sourceTop }
{
	//cout << "\nBookList parametrized constructor invoked...";
	if (getCurrentSize() > MAX_CAPACITY)
	{
		throw new out_of_range("Max capacity reached...");
	}

	size_t j{ (getCurrentSize() - 1) };
	for (size_t i{}; i < getCurrentSize(); i++)
	{
		this->books[i] = sourceBooks[j];
		j--;
	}
}

template<class T, int MAX_CAPACITY>
inline BookList<T, MAX_CAPACITY>::BookList(const BookList& sourceBookList) : top{ sourceBookList.getCurrentSize() }
{
	//std::cout << "\nBookList Copy constructor invoked...";

	size_t j{ (getCurrentSize() - 1) };
	for (size_t i{}; i < getCurrentSize(); i++)
	{
		this->books[i] = sourceBookList.books[j];
		j--;
	}
}

template<class T, int MAX_CAPACITY>
inline const bool BookList<T, MAX_CAPACITY>::isEmpty() const
{
	int emptyStringsFound{};
	for (const auto& book : books)
	{
		if (book.getTitle().empty() && book.getAuthor().empty() && book.getPublisher().empty())
		{
			emptyStringsFound++;
		}
	}

	if (emptyStringsFound == MAX_CAPACITY)
	{
		return true;
	}

	return false;
}

template<class T, int MAX_CAPACITY>
inline const bool BookList<T, MAX_CAPACITY>::isFull() const
{
	int fullStringsFound{};
	for (const auto& book : books)
	{
		if (!book.getTitle().empty() && !book.getAuthor().empty() && !book.getPublisher().empty())
		{
			fullStringsFound++;
		}
	}

	if (fullStringsFound == MAX_CAPACITY)
	{
		return true;
	}

	return false;
}

template<class T, int MAX_CAPACITY>
inline const size_t BookList<T, MAX_CAPACITY>::getCurrentSize() const
{
	return top;
}

template<class T, int MAX_CAPACITY>
inline const bool BookList<T, MAX_CAPACITY>::addBook(const T sourceBook)
{
	if (!isFull())
	{
		top++;

		if (getCurrentSize() > 1)
		{
			size_t i{ getCurrentSize() - 1 };
			while (i-- > 0)
			{
				std::swap(books[i], books[i + 1]);
			}
		}
		this->books[0] = sourceBook;

		return true;
	}

	std::cout << "\nUnable to insert book, the list is full...";

	return false;
}

template<class T, int MAX_CAPACITY>
inline const size_t BookList<T, MAX_CAPACITY>::containsBook(const std::string sourceTitle) const
{
	if (!isEmpty() && getCurrentSize() > 1)
	{
		for (size_t i{}; i < getCurrentSize(); i++)
		{
			if (books[i].getTitle().compare(sourceTitle) == 0)
			{
				std::cout << "\nThe book was found in position #" << i << " of the array...";
				return i;
			}
		}
	}
	else if (!isEmpty() && getCurrentSize() == 1)
	{
		std::cout << "\nThere is only one book...";
		return 0;
	}

	std::cout << "\nThe book was not found...";
	return -1;
}

template<class T, int MAX_CAPACITY>
inline const bool BookList<T, MAX_CAPACITY>::removeBook(const std::string sourceName)
{
	if (isEmpty())
	{
		std::cout << "\nNo books to remove, the list is empty...";
	}
	else if (getCurrentSize() == 1)
	{
		std::cout << "\nOnly book removed...";
		for (auto& it : this->books)
		{
			it.setBookInfo("", "", "");
		}
		return true;
	}
	else
	{
		size_t position{ containsBook(sourceName) };

		if (position != -1)
		{
			BookList temporaryList{};

			size_t i{ getCurrentSize() };
			while (i-- > 0)
			{
				if (i != position)
				{
					temporaryList.addBook(this->books[i]);
				}
				else
				{
					std::cout << "\nBook removed...";
				}
			}

			top--;
			for (auto& it : this->books)
			{
				it.setBookInfo("", "", "");
			}

			for (size_t i{}; i < getCurrentSize(); i++)
			{
				this->books[i] = temporaryList[i];
			}
		}

		return true;
	}

	return false;
}

template<class T, int MAX_CAPACITY>
inline void BookList<T, MAX_CAPACITY>::displayBooks() const
{
	std::cout << "\nThe books saved on the list are:";
	for (size_t i{}; i < getCurrentSize(); i++)
	{
		cout << books[i] << '\n';
	}
}

template<class T, int MAX_CAPACITY>
inline T& BookList<T, MAX_CAPACITY>::operator[](const int& index)
{
	if (index < 0 || index >= MAX_CAPACITY)
	{
		throw new std::out_of_range("Bounds exceeded...");
	}

	return books[index];
}

template<class T, int MAX_CAPACITY>
inline BookList<T, MAX_CAPACITY>::~BookList()
{
	//std::cout << "\n\tObject released...";
}