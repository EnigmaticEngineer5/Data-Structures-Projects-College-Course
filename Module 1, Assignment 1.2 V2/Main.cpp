#include "BookList.h"

void searchBookInfo(const BookList<BookInfo>&);
void removeBookInfo(BookList<BookInfo>&);
void displayMenu(int&);
void addBookInfo(BookList<BookInfo>&);

int main() {
	const BookInfo books[] = {
		BookInfo{"Legacies", "Julie Plec", "TVD"},
		BookInfo{"The Originals", "Julie Plec", "TVD"},
		BookInfo{"Vampire Diaries", "Julie Plec", "TVD"},
		BookInfo{"The Flash", "Sam Reimi", "DC"},
		BookInfo{"Spiderman", "Sam Reimi", "Marvel"}
	};

	BookList<BookInfo> allBooks{ books, 5 };
	cout << "Welcome to the book list program!";

	enum MyEnum {
		addBook = 1,
		searchBook = 2,
		removeBook = 3,
		checkIfFull = 4,
		checkIfEmpty = 5,
		printList = 6
	};

	int selection{};
	do {
		displayMenu(selection);

		switch (selection) {
		case addBook:
			addBookInfo(allBooks);
			break;

		case searchBook:
			searchBookInfo(allBooks);
			break;

		case removeBook:
			allBooks.displayBooks();
			removeBookInfo(allBooks);
			allBooks.displayBooks();
			break;

		case checkIfFull:
			(allBooks.isFull()) ? cout << "\nList is full..." : cout << "\nThe list is not full...";
			break;

		case checkIfEmpty:
			(allBooks.isEmpty()) ? cout << "\nThe list is empty..." : cout << "\nThe list is not empty...";
			break;

		case printList:
			allBooks.displayBooks();
			break;

		default:
			cout << "\nEnding program...";
		}
	} while (selection != 7);

	cout << "\n\n";
	return 0;
}

void addBookInfo(BookList<BookInfo>& allBooks)
{
	if (allBooks.isFull()) {
		cout << "\nList is full...";
	}
	else {
		BookInfo temporaryBook{};
		cin >> temporaryBook;
		allBooks.addBook(temporaryBook);
		allBooks.displayBooks();
	}
}

void displayMenu(int& selection) {
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

	while (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\nOnly integer input accepted! Re-enter --> ";
		cin >> selection;
	}

	while (selection < 1 || selection > 7) {
		cout << "\nInvalid range, please re-enter a valid option --> ";
		cin >> selection;
	}
}

void removeBookInfo(BookList<BookInfo>& allBooks) {
	if (allBooks.getCurrentSize() > 1) {
		cout << "\n\n\t- Enter the TITLE of the book you want to REMOVE --> ";
		string title{};
		getline(cin >> ws, title);
		allBooks.removeBook(title);
	}
	else if (allBooks.getCurrentSize() == 1) {
		allBooks.removeBook("Deleting only book...");
	}
	else {
		cout << "\nThe list is empty...";
	}
}

void searchBookInfo(const BookList<BookInfo>& allBooks) {
	if (allBooks.getCurrentSize() > 1) {
		cout << "\n\t- Enter the title of the book you want to SEARCH --> ";
		string title{};
		getline(cin >> ws, title);

		const int position{ allBooks.containsBook(title) };
		if (position != -1) {
			cout << '\n' << title << " was found in position #" << position << " of the list!";
		}
		else if (position == -1) {
			cout << "\nThe book was not found...";
		}
	}
	else if (allBooks.getCurrentSize() == 1) {
		cout << "\nThere is only one book...";
		allBooks.displayBooks();
	}
	else {
		cout << "\nThe list is empty...";
	}
}