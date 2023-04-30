#pragma once

#include <iostream>
using namespace std;

template<class ItemType>
class SortedListInterface
{
protected:
	inline SortedListInterface() {
		cout << "\nSortedListInterface default constructor invoked...\n";
	}

	inline ~SortedListInterface() {
		cout << "SortedListInterface destructor invoked...\n";
	}

public:
	virtual void insertSorted(const ItemType&) = 0;
	virtual const bool removeSorted(const ItemType&) = 0;
	virtual const int getPosition(const ItemType&) const = 0;

	virtual const bool isEmpty() const = 0;
	virtual const int getLength() const = 0;
	virtual const bool remove(int) = 0;

	virtual void clear() = 0;
	virtual const ItemType getEntry(const int) const = 0;
};