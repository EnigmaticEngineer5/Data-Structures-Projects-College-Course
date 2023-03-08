#include "BookList.h"

BookList::BookList() : top{}
{
	for (auto& title : books)
	{
		title = "";
	}
}

BookList::BookList(const std::string sourceBooks[], const int sourceDimension) : top{ sourceDimension }
{
	if (getCurrentSize() > MAX_CAPACITY)
	{
		throw new std::out_of_range("Max capacity reached...");
	}

	int j{};
	for (int i{ (MAX_CAPACITY - getCurrentSize()) }; i < MAX_CAPACITY; i++)
	{
		this->books[i] = sourceBooks[j];
		j++;
	}
}

BookList::BookList(const BookList& sourceBookList) : top{ sourceBookList.getCurrentSize() }
{
	std::cout << "\nCopy constructor invoked...";

	int j{};
	for (int i{ (MAX_CAPACITY - getCurrentSize()) }; i < MAX_CAPACITY; i++)
	{
		this->books[i] = sourceBookList.books[j];
		j++;
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

const int BookList::getCurrentSize() const
{
	return top;
}

const bool BookList::addBook(const std::string sourceTitle)
{
	if (!isFull())
	{
		top++;
		int i{ (MAX_CAPACITY - getCurrentSize()) };
		while (i < MAX_CAPACITY)
		{
			if (i < MAX_CAPACITY - 1)
			{
				this->books[i] = books[(i + 1)];
			}
			else if (i == MAX_CAPACITY - 1)
			{
				this->books[i] = sourceTitle;
			}

			i++;
		}
		return true;
	}

	std::cout << "\nUnable to insert book, the list is full...";

	return false;
}

const int BookList::containsBook(const std::string sourceTitle) const
{
	for (int i{ (MAX_CAPACITY - getCurrentSize()) }; i < MAX_CAPACITY; i++)
	{
		if (books[i].compare(sourceTitle) == 0)
		{
			std::cout << "\n\tBook found in cell #" << i;
			return i;
		}
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
	else
	{
		int position{ containsBook(sourceName) };
		BookList temporaryList{};

		if (position != 1)
		{
			for (int i{ (MAX_CAPACITY - getCurrentSize()) }; i < MAX_CAPACITY; i++)
			{
				if (i == position)
				{
					std::cout << "\n\tBook removed...";
				}
				else
				{
					temporaryList.addBook(books[i]);
				}
			}

			books->erase();
			top--;
			for (int i{ (MAX_CAPACITY - getCurrentSize() - 1) }; i < MAX_CAPACITY; i++)
			{
				this->books[i] = temporaryList[i];
			}

			return true;
		}
	}

	return false;
}

void BookList::displayBooks() const
{
	std::cout << "The books saved on the list are:";
	for (const auto& it : books)
	{
		std::cout << "\n\t- " << it;
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

std::istream& operator>>(std::istream& input, BookList& sourceList)
{
	return input;
}

std::ostream& operator<<(std::ostream& output, const BookList& sourceList)
{
	return output;
}

BookList::~BookList() 
{ 
	books->erase();
};