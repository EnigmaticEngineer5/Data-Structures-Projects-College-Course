#include "BookList2.h"

void searchTitle(BookList<BookInfo>& allBooks);
void removeTitle(BookList<BookInfo>& allBooks);
void addBookData(BookList<BookInfo>& allBooks);

const int main()
{
	cout << "Welcome to the book list program!";

	enum MyEnum
	{
		addBook = 1,
		searchBook = 2,
		removeBook = 3,
		checkIfFull = 4,
		checkIfEmpty = 5,
		printList = 6
	};

	int selection{};
	BookList<BookInfo> allBooks{};

	do
	{
		cout << "\n\nChoose your desired operation:"
			<< "\n\t1) Add Book"
			<< "\n\t2) Search Book"
			<< "\n\t3) Remove Book"
			<< "\n\t4) Check if the list is full"
			<< "\n\t5) Check if the list is empty"
			<< "\n\t6) Print books"
			<< "\n\t7) Exit program"
			<< "\nEnter answer here --> ";
		cin >> selection;

		while (cin.fail() || selection < 1 || selection > 7)
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "\nOnly integer input accepted! Re-enter --> ";
				cin >> selection;
			}
			else
			{
				cout << "\nInvalid range, please re-enter a valid option --> ";
				cin >> selection;
			}
		}

		switch (selection)
		{
		case addBook:
			cin >> allBooks;
			break;

		case searchBook:
			searchTitle(allBooks);
			break;

		case removeBook:
			removeTitle(allBooks);
			break;

		case checkIfFull:
			(allBooks.isFull()) ? cout << "\nList is full..." : cout << "\nThe list is not full...";
			break;

		case checkIfEmpty:
			(allBooks.isEmpty()) ? cout << "\nThe list is empty..." : cout << "\nThe list is not empty...";
			break;

		case printList:
			cout << allBooks;
			break;

		default:
			cout << "\nEnding program...";
		}
	} while (selection != 7);

	cout << "\n\n";
	return 0;
}

void addBookData(BookList<BookInfo>& allBooks)
{
	BookInfo bookToAdd{};
	cin >> bookToAdd;
	allBooks.addBook(bookToAdd);
}

void removeTitle(BookList<BookInfo>& allBooks)
{
	if (!allBooks.isEmpty() && allBooks.getCurrentSize() > 1)
	{
		cout << "\n\t- Enter the title of the book you want to REMOVE --> ";
		string title{};
		getline(cin >> ws, title);
		allBooks.removeBook(title);
	}
	else if (!allBooks.isEmpty() && allBooks.getCurrentSize() == 1)
	{
		allBooks.removeBook("");
	}
	else
	{
		cout << "\nThe list is empty...";
	}
}

void searchTitle(BookList<BookInfo>& allBooks)
{
	if (!allBooks.isEmpty() && allBooks.getCurrentSize() > 1)
	{
		cout << "\n\t- Enter the title of the book you want to SEARCH --> ";
		string title{};
		getline(cin >> ws, title);
		allBooks.containsBook(title);
	}
	else if (!allBooks.isEmpty() && allBooks.getCurrentSize() == 1)
	{
		allBooks.containsBook("");
	}
	else
	{
		cout << "\nThe list is empty...";
	}
}