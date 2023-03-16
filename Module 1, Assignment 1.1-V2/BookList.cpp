#include "BookList.h"

BookList::BookList() : books{}, top{}
{
	cout << "\nDefault constructor invoked...";
}

BookList::BookList(const string sourceBooks[], const int sourceDimension) : top{ sourceDimension }
{
	cout << "\nParametrized constructor invoked...";
	if (this->getCurrentSize() > MAX_CAPACITY)
	{
		throw exception("Max capacity reached...");
	}

	int counter{};
	for (int i{ (MAX_CAPACITY - 1) }; i >= 0; i--)
	{
		(counter != this->getCurrentSize()) ? this->books[i] = sourceBooks[counter++] : this->books[i] = "";
	}
}

BookList::BookList(const BookList& sourceBookList) : top{ sourceBookList.getCurrentSize() }
{
	cout << "\nCopy constructor invoked...";

	int j{ (this->getCurrentSize() - 1) };
	for (int i{}; i < this->getCurrentSize(); i++)
	{
		this->books[i] = sourceBookList.books[j];
		j--;
	}
}

const bool BookList::isEmpty() const
{
	return (this->getCurrentSize() == 0);
}

const bool BookList::isFull() const
{
	return (this->getCurrentSize() == MAX_CAPACITY);
}

const int BookList::getCurrentSize() const
{
	return this->top;
}

const bool BookList::addBook(const string sourceTitle)
{
	if (!this->isFull())
	{
		top++;
		this->books[(MAX_CAPACITY - this->getCurrentSize())] = sourceTitle;
		return true;
	}

	cout << "\nUnable to insert book, the list is full...";

	return false;
}

const int BookList::containsBook(const string sourceTitle) const
{
	if (this->getCurrentSize() > 1)
	{
		for (int i{ (MAX_CAPACITY - this->getCurrentSize()) }; i < MAX_CAPACITY; i++)
		{
			if (this->books[i].compare(sourceTitle) == 0)
			{
				cout << "\nThe book was found in position #" << i << " of the array...";
				return i;
			}
		}
	}
	else if (this->getCurrentSize() == 1)
	{
		cout << "\nThere is only one book..."
			<< "\n\t- Its TITLE is --> " << this->books[(MAX_CAPACITY - 1)];
		return 0;
	}

	cout << "\nThe book was not found...";
	return -1;
}

const bool BookList::removeBook(const string sourceTitle)
{
	bool removed{};
	if (this->isEmpty())
	{
		cout << "\nNo books to remove, the list is empty...";
		removed = false;
	}
	else if (this->getCurrentSize() == 1)
	{
		cout << "\nOnly book removed...";
		this->books[(MAX_CAPACITY - 1)] = "";
		top--;
		removed = true;
	}
	else
	{
		int position{ containsBook(sourceTitle) };

		if (position != -1) {
			BookList temporaryList{};

			for (int i{ MAX_CAPACITY - 1 }; i >= 0; i--) {
				if (i != position) {
					temporaryList.addBook(this->books[i]);
				}

				if (i == position) {
					cout << "\n'" << this->books[i] << "' removed...";
				}

				this->books[i].erase();
			}

			top--;

			for (int i{ MAX_CAPACITY - this->getCurrentSize() }; i < MAX_CAPACITY; i++) {
				this->books[i] = temporaryList[i];
			}

			removed = true;
		}
		else {
			removed = false;
		}
	}

	return removed;
}

void BookList::displayBooks() const
{
	if (!this->isEmpty())
	{
		cout << "\nThe books saved on the list are:";
		for (const auto& it : this->books)
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
		throw exception("Bounds exceeded...");
	}

	return this->books[index];
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