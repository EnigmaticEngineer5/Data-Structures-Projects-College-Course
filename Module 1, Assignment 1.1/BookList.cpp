#include "BookList.h"

BookList::BookList() : books{}, top{}
{
	std::cout << "\nDefault constructor invoked...";
}

BookList::BookList(const std::string sourceBooks[], const size_t sourceDimension) : top{ sourceDimension }
{
	if (getCurrentSize() > MAX_CAPACITY)
	{
		throw new std::out_of_range("Max capacity reached...");
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
	std::cout << "\nCopy constructor invoked...";

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

const bool BookList::addBook(const std::string sourceTitle)
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
		this->books[0] = sourceTitle;

		return true;
	}

	std::cout << "\nUnable to insert book, the list is full...";

	return false;
}

const size_t BookList::containsBook(const std::string sourceTitle) const
{
	if (!isEmpty() && getCurrentSize() > 1)
	{
		for (size_t i{}; i < getCurrentSize(); i++)
		{
			if (books[i].compare(sourceTitle) == 0)
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

const bool BookList::removeBook(const std::string sourceName)
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
					std::cout << "\nBook removed...";
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
		std::cout << "\nThe books saved on the list are:";
		for (const auto& it : books)
		{
			std::cout << "\n\t- " << it;
		}
	}
	else
	{
		std::cout << "\nThe list is empty...";
	}
}

std::string& BookList::operator [] (const int& index)
{
	if (index < 0 || index >= MAX_CAPACITY)
	{
		throw new std::out_of_range("Bounds exceeded...");
	}

	return books[index];
}

std::istream& operator >> (std::istream& input, BookList& sourceList)
{
	if (sourceList.isFull())
	{
		std::cout << "\nList is full...";
		return input;
	}

	std::cout << "\n\t- Enter the TITLE of the book you want to add --> ";
	std::string title{};
	getline(std::cin >> std::ws, title);
	sourceList.addBook(title);

	return input;
}

std::ostream& operator << (std::ostream& output, const BookList& sourceList)
{
	sourceList.displayBooks();
	return output;
}

BookList::~BookList()
{
	std::cout << "\nObject released...";
	books->erase();
};