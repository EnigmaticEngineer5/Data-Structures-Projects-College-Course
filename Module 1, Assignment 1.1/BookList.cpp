#include "BookList.h"

BookList::BookList() : books{}, top{}
{
	cout << "\nDefault constructor invoked...";
}

BookList::BookList(const string sourceBooks[], const size_t sourceDimension) : top{ sourceDimension }
{
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

BookList::BookList(const BookList& sourceBookList) : top{ sourceBookList.getCurrentSize() }
{
	cout << "\nCopy constructor invoked...";

	size_t j{ (getCurrentSize() - 1) };
	for (size_t i{}; i < getCurrentSize(); i++)
	{
		this->books[i] = sourceBookList.books[j];
		j--;
	}
}

const bool BookList::isEmpty() const
{
	int emptyStringsFound{};
	for (const auto& title : books)
	{
		if (title.empty())
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

const bool BookList::isFull() const
{
	int fullStringsFound{};
	for (const auto& title : books)
	{
		if (!title.empty())
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

const size_t BookList::getCurrentSize() const
{
	return top;
}

const bool BookList::addBook(const string sourceTitle)
{
	if (!isFull())
	{
		top++;

		if (getCurrentSize() > 1)
		{
			size_t i{ getCurrentSize() - 1 };
			while (i-- > 0)
			{
				swap(books[i], books[i + 1]);
			}
		}
		this->books[0] = sourceTitle;

		return true;
	}

	cout << "\nUnable to insert book, the list is full...";

	return false;
}

const size_t BookList::containsBook(const string sourceTitle) const
{
	if (!isEmpty() && getCurrentSize() > 1)
	{
		for (size_t i{}; i < getCurrentSize(); i++)
		{
			if (books[i].compare(sourceTitle) == 0)
			{
				cout << "\nThe book was found in position #" << i << " of the array...";
				return i;
			}
		}
	}
	else if (!isEmpty() && getCurrentSize() == 1)
	{
		cout << "\nThere is only one book...";
		return 0;
	}

	cout << "\nThe book was not found...";
	return -1;
}

const bool BookList::removeBook(const string sourceName)
{
	if (isEmpty())
	{
		cout << "\nNo books to remove, the list is empty...";
	}
	else if (getCurrentSize() == 1)
	{
		cout << "\nOnly book removed...";
		for (auto& it : this->books)
		{
			it = "";
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
					cout << "\nBook removed...";
				}
			}

			top--;
			for (auto& it : this->books)
			{
				it = "";
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

void BookList::displayBooks() const
{
	if (!isEmpty())
	{
		cout << "\nThe books saved on the list are:";
		for (const auto& it : books)
		{
			cout << "\n\t- " << it;
		}
	}
	else
	{
		cout << "\nThe list is empty...";
	}
}

string& BookList::operator [] (const int& index)
{
	if (index < 0 || index >= MAX_CAPACITY)
	{
		throw new out_of_range("Bounds exceeded...");
	}

	return books[index];
}

istream& operator >> (istream& input, BookList& sourceList)
{
	if (sourceList.isFull())
	{
		cout << "\nList is full...";
		return input;
	}

	cout << "\n\t- Enter the TITLE of the book you want to add --> ";
	string title{};
	getline(cin >> ws, title);
	sourceList.addBook(title);

	return input;
}

ostream& operator << (ostream& output, const BookList& sourceList)
{
	sourceList.displayBooks();
	return output;
}

BookList::~BookList()
{
	cout << "\nObject released...";
	books->erase();
};