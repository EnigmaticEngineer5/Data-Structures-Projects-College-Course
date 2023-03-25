#include "BookList.h"

BookList::BookList() : books{}, top{} {};

BookList::BookList(const string sourceTitles[], const int sourceTop)
	: top{ sourceTop } {
	if (this->getCurrentSize() > MAX_CAPACITY) {
		throw exception("Max capacity exceeded...");
	}
	else if (!this->isEmpty()) {
		for (int i{}; i < this->getCurrentSize(); i++) {
			this->books[(MAX_CAPACITY - i - 1)] = sourceTitles[i];
		}
	}
}

BookList::BookList(const BookList& sourceList)
	: top{ sourceList.getCurrentSize() } {
	if (this->getCurrentSize() > MAX_CAPACITY) {
		throw exception("Max capacity exceeded...");
	}
	else if (!this->isEmpty()) {
		for (int i{ (MAX_CAPACITY - this->getCurrentSize()) }; i < MAX_CAPACITY; i++) {
			this->books[i] = sourceList.books[i];
		}
	}
}

BookList::~BookList() { cout << "\nObject released..."; };

const bool BookList::isEmpty() const {
	return (this->getCurrentSize() < 1);
}

const bool BookList::isFull() const {
	return (this->getCurrentSize() >= MAX_CAPACITY);
}

const int BookList::getCurrentSize() const {
	return (this->top);
}

void BookList::displayBooks() const {
	if (!this->isEmpty()) {
		cout << "\nThe books saved on the list are:";
		for (const auto& it : books) {
			cout << "\n\t- " << it;
		}
	}
	else {
		cout << "\nUnable to print list, is empty...";
	}
}

string& BookList::operator[](const int& index) {
	if (this->getCurrentSize() > MAX_CAPACITY) {
		throw exception("Max capacity exceeded...");
	}

	return this->books[index];
}

const bool BookList::removeBook(const string sourceTitle) {
	if (!this->isEmpty()) {
		if (this->getCurrentSize() == 1) {
			this->books[(MAX_CAPACITY - 1)].erase();
			this->top--;
			cout << "\nOnly book deleted...";
		}
		else {
			int position{ this->containsBook(sourceTitle) };

			if (position != -1) {
				if (MAX_CAPACITY - this->getCurrentSize() == position) {
					this->books[position].erase();
					cout << "\nBook was found at the end of the list, no need to create copies...";
					this->top--;
				}
				else {
					BookList temporaryList{};

					for (int i{ (position - 1) }; i >= 0; i--) {
						temporaryList.addBook(this->books[i]);
					}

					this->top--;
					int j{ MAX_CAPACITY - 1 };
					for (int i{ position }; i >= 0; i--) {
						this->books[i] = temporaryList[j--];
					}
				}
			}
		}
		return true;
	}
	return false;
}

const int BookList::containsBook(const string sourceTitle) const {
	for (int i{ (MAX_CAPACITY - this->getCurrentSize()) }; i < MAX_CAPACITY; i++) {
		if (this->books[i].compare(sourceTitle) == 0) {
			return i;
		}
	}

	cout << "\nThe book was not found in the list...";
	return -1;
}

const bool BookList::addBook(const string sourceTitle) {
	if (!this->isFull()) {
		this->books[(MAX_CAPACITY - ++top)] = sourceTitle;
		return true;
	}

	cout << "\nUnable to add book, the list is full!";
	return false;
}

istream& operator>>(istream& input, BookList& sourceList) {
	if (!sourceList.isFull()) {
		cout << "\n\t- Enter the BOOK TITLE --> ";
		string bookTitle{};
		getline(input >> ws, bookTitle);
		sourceList.addBook(bookTitle);
	}
	else {
		cout << "\nUnable to add book, the list is full!";
	}

	return input;
}

ostream& operator<<(ostream& output, const BookList& sourceList) {
	sourceList.displayBooks();
	return output;
}