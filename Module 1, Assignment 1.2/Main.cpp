#include "BookList2.h"

void searchTitle(BookList<BookInfo>& allBooks);
void removeTitle(BookList<BookInfo>& allBooks);
void addBookData(BookList<BookInfo>& allBooks);

const int main()
{
	std::cout << "Welcome to the book list program!";

	enum MyEnum
	{
		addBook = 1,
		searchBook = 2,
		removeBook = 3,
		checkIfFull = 4,
		checkIfEmpty = 5,
		printList = 6
	};

	//BookInfo bookRecord[] =
	//		{
	//			{"The Originals", "Julie Plec", "TVD"},
	//			{"Legacies", "Julie Plec", "TVD"},
	//			{"Doctor Strange", "Sam Reimi", "Marvel"}
	//		};

	int selection{};
	BookList<BookInfo> allBooks{/*bookRecord, 3*/};

	do
	{
		std::cout << "\n\nChoose your desired operation:"
			<< "\n\t1) Add Book"
			<< "\n\t2) Search Book"
			<< "\n\t3) Remove Book"
			<< "\n\t4) Check if the list is full"
			<< "\n\t5) Check if the list is empty"
			<< "\n\t6) Print books"
			<< "\n\t7) Exit program"
			<< "\nEnter answer here --> ";
		std::cin >> selection;

		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\nOnly integer input accepted! Re-enter --> ";
			std::cin >> selection;
		}

		while (selection < 0 || selection > 7)
		{
			std::cout << "\nInvalid range, please re-enter a valid option --> ";
			std::cin >> selection;
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
			(allBooks.isFull()) ? std::cout << "\nList is full..." : std::cout << "\nThe list is not full...";
			break;

		case checkIfEmpty:
			(allBooks.isEmpty()) ? std::cout << "\nThe list is empty..." : std::cout << "\nThe list is not empty...";
			break;

		case printList:
			std::cout << allBooks;
			break;

		default:
			std::cout << "\nEnding program...";
		}
	} while (selection != 7);

	std::cout << "\n\n";
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
		std::cout << "\n\t- Enter the title of the book you want to REMOVE --> ";
		std::string title{};
		getline(std::cin >> std::ws, title);
		allBooks.removeBook(title);
	}
	else if (!allBooks.isEmpty() && allBooks.getCurrentSize() == 1)
	{
		allBooks.removeBook("");
	}
	else
	{
		std::cout << "\nThe list is empty...";
	}
}

void searchTitle(BookList<BookInfo>& allBooks)
{
	if (!allBooks.isEmpty() && allBooks.getCurrentSize() > 1)
	{
		std::cout << "\n\t- Enter the title of the book you want to SEARCH --> ";
		std::string title{};
		getline(std::cin >> std::ws, title);
		allBooks.containsBook(title);
	}
	else if (!allBooks.isEmpty() && allBooks.getCurrentSize() == 1)
	{
		allBooks.containsBook("");
	}
	else
	{
		std::cout << "\nThe list is empty...";
	}
}