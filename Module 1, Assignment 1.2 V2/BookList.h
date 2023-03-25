#pragma once

#include "BookInfo.h"

template <class ItemType, const int MAX_CAPACITY = 5>
class BookList final {
private:
	int top;
	ItemType books[MAX_CAPACITY];

public:
	BookList();
	BookList(const ItemType[], const int);
	BookList(const ItemType&);
	~BookList();

	const bool isEmpty() const;
	const bool isFull() const;
	const int getCurrentSize() const;
	const bool addBook(const ItemType);
	const int containsBook(const string) const;
	const bool removeBook(const string);

	void displayBooks() const;
};

template <class ItemType, const int MAX_CAPACITY>
inline BookList<ItemType, MAX_CAPACITY>::BookList() : books{}, top{} {};

template <class ItemType, const int MAX_CAPACITY>
inline BookList<ItemType, MAX_CAPACITY>::BookList(const ItemType sourceBooks[], const int sourceTop) : top{ sourceTop } {
	if (this->getCurrentSize() > MAX_CAPACITY) {
		throw exception("Max capacity exceeded...");
	}
	else if (!this->isEmpty()) {
		for (int i{}; i < this->getCurrentSize(); i++) {
			this->books[(MAX_CAPACITY - i - 1)] = sourceBooks[i];
		}
	}
}

template <class ItemType, const int MAX_CAPACITY>
inline BookList<ItemType, MAX_CAPACITY>::BookList(const ItemType& sourceList)
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

template <class ItemType, const int MAX_CAPACITY>
inline BookList<ItemType, MAX_CAPACITY>::~BookList() {
	cout << "\nBookList Object released...";
}

template <class ItemType, const int MAX_CAPACITY>
inline const bool BookList<ItemType, MAX_CAPACITY>::isEmpty() const {
	return (this->getCurrentSize() < 1);
}

template <class ItemType, const int MAX_CAPACITY>
inline const bool BookList<ItemType, MAX_CAPACITY>::isFull() const {
	return (this->getCurrentSize() >= MAX_CAPACITY);
}

template <class ItemType, const int MAX_CAPACITY>
inline const int BookList<ItemType, MAX_CAPACITY>::getCurrentSize() const {
	return (this->top);
}

template <class ItemType, const int MAX_CAPACITY>
inline void BookList<ItemType, MAX_CAPACITY>::displayBooks() const {
	if (!this->isEmpty()) {
		cout << "\n\nThe books saved on the list are:";
		for (const auto& it : books) {
			cout << it << '\n';
		}
	}
	else {
		cout << "\nUnable to print list, is empty...";
	}
}

template <class ItemType, const int MAX_CAPACITY>
inline const bool BookList<ItemType, MAX_CAPACITY>::removeBook(const string sourceTitle) {
	int position{ this->containsBook(sourceTitle) };

	if (!this->isEmpty()) {
		if (this->getCurrentSize() == 1) {
			this->books[(MAX_CAPACITY - 1)].~BookInfo();
			this->top--;
			cout << "\nOnly book deleted...";
		}
		else if (position != -1) {
			if (MAX_CAPACITY - this->getCurrentSize() == position) {
				this->books[position].~BookInfo();
				cout << "\nBook was found at the top of the list, no need to create copies...";
				this->top--;
			}
			else {
				ItemType temporaryList[MAX_CAPACITY];

				int j{ MAX_CAPACITY };
				for (int i{ (position - 1) }; i >= 0; i--) {
					temporaryList[--j] = this->books[i];
				}

				this->top--;
				j = MAX_CAPACITY;
				for (int i{ position }; i >= 0; i--) {
					this->books[i] = temporaryList[--j];
				}
			}
		}
		else if (position == -1) {
			cout << "\nThe book was not found...";
			return false;
		}
	}

	return true;
}

template <class ItemType, const int MAX_CAPACITY>
inline const int BookList<ItemType, MAX_CAPACITY>::containsBook(const string sourceTitle) const {
	ItemType titleInfo{};
	titleInfo.setTitle(sourceTitle);

	for (int i{ (MAX_CAPACITY - this->getCurrentSize()) }; i < MAX_CAPACITY; i++) {
		if (this->books[i] == titleInfo) {
			return i;
		}
	}

	return -1;
}

template <class ItemType, const int MAX_CAPACITY>
inline const bool BookList<ItemType, MAX_CAPACITY>::addBook(const ItemType sourceBook) {
	if (!this->isFull()) {
		this->books[(MAX_CAPACITY - ++top)] = sourceBook;
		return true;
	}

	cout << "\nUnable to add book, the list is full!";
	return false;
}