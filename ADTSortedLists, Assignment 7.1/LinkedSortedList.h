#pragma once

#include "SortedListInterface.h"
#include "../LinkedLists, Assignment 4.2 V2/Node.h"
#include <cassert>

template<class ItemType>
class LinkedSortedList : public SortedListInterface<ItemType>
{
private:
	Node<ItemType>* headPtr;
	int itemCount;

	Node<ItemType>* getNodeBefore(const ItemType&) const;
	Node<ItemType>* getNodeAt(const int) const;
	Node<ItemType>* copyChain(const Node<ItemType>*);

public:
	LinkedSortedList();
	LinkedSortedList(const LinkedSortedList<ItemType>&);
	virtual ~LinkedSortedList();

	void insertSorted(const ItemType&);
	const bool removeSorted(const ItemType&);
	const int getPosition(const ItemType&) const;

	const bool isEmpty() const;
	const int getLength() const;
	const bool remove(int);

	void clear();
	const ItemType getEntry(const int x) const;
};

template<class ItemType>
inline LinkedSortedList<ItemType>::LinkedSortedList() :
	headPtr(nullptr), itemCount(0) {
	cout << "\nLinkedSortedList default constructor invoked...\n";
};

template<class ItemType>
LinkedSortedList<ItemType>::LinkedSortedList(const LinkedSortedList<ItemType>& aList)
{
	headPtr = copyChain(aList.headPtr);
}

template<class ItemType>
inline LinkedSortedList<ItemType>::~LinkedSortedList() { 
	cout << "\nLinkedSortedList destructor invoked...\n";
	clear(); 
};

template<class ItemType>
Node<ItemType>* LinkedSortedList<ItemType>::getNodeBefore(const ItemType& anEntry) const
{
	Node<ItemType>* curPtr = headPtr;
	Node<ItemType>* prevPtr = nullptr;

	while ((curPtr != nullptr) && (anEntry > curPtr->getItem()))
	{
		prevPtr = curPtr;
		curPtr = curPtr->getNext();
	}
	return prevPtr;
}

template<class ItemType>
Node<ItemType>* LinkedSortedList<ItemType>::getNodeAt(const int position) const
{
	assert((position >= 1) && (position <= itemCount));

	Node<ItemType>* curPtr = headPtr;
	for (int skip = 1; skip < position; skip++) {
		curPtr = curPtr->getNext();
	}
	return curPtr;
}

template<class ItemType>
Node<ItemType>* LinkedSortedList<ItemType>::copyChain(const Node<ItemType>* origChainPtr)
{
	Node<ItemType>* copiedChainPtr;
	if (origChainPtr == nullptr)
	{
		copiedChainPtr = nullptr;
	}
	else
	{
		copiedChainPtr = new Node<ItemType>(origChainPtr->getItem());
		copiedChainPtr->setNext(copyChain(origChainPtr->getNext()));
	}
	return copiedChainPtr;
}

template<class ItemType>
void LinkedSortedList<ItemType>::insertSorted(const ItemType& newEntry)
{
	Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
	Node<ItemType>* prevPtr = getNodeBefore(newEntry);

	if (isEmpty() || (prevPtr == nullptr))
	{
		newNodePtr->setNext(headPtr);
		headPtr = newNodePtr;
	}
	else
	{
		Node<ItemType>* aftPtr = prevPtr->getNext();
		newNodePtr->setNext(aftPtr);
		prevPtr->setNext(newNodePtr);
	}
	itemCount++;
}

template< class ItemType>
const bool LinkedSortedList<ItemType>::removeSorted(const ItemType& anEntry)
{
	bool ableToRemove = false;
	if (!LinkedSortedList<ItemType>::isEmpty())
	{
		int position = getPosition(anEntry);
		ableToRemove = position > 0;
		if (ableToRemove) {
			ableToRemove = LinkedSortedList<ItemType>::remove(position);
		}
	}
	return ableToRemove;
}

template< class ItemType>
const int LinkedSortedList<ItemType>::getPosition(const ItemType& anEntry) const
{
	int position = 1;
	int length = LinkedSortedList<ItemType>::getLength();
	while ((position <= length) &&
		(anEntry > LinkedSortedList<ItemType>::getEntry(position)))
	{
		position++;
	}
	if ((position > length) ||
		(anEntry != LinkedSortedList<ItemType>::getEntry(position)))
	{
		position = -position;
	}
	return position;
}

template<class ItemType>
const bool LinkedSortedList<ItemType>::isEmpty() const
{
	return itemCount == 0;
}

template<class ItemType>
const int LinkedSortedList<ItemType>::getLength() const
{
	return itemCount;
}

template<class ItemType>
const bool LinkedSortedList<ItemType>::remove(int position)
{
	bool ableToRemove = (position >= 1) && (position <= itemCount);
	if (ableToRemove)
	{
		Node<ItemType>* curPtr = nullptr;
		if (position == 1)
		{
			curPtr = headPtr;
			headPtr = headPtr->getNext();
		}
		else
		{
			Node<ItemType>* prevPtr = getNodeAt(position - 1);
			curPtr = prevPtr->getNext();
			prevPtr->setNext(curPtr->getNext());
		}

		curPtr->setNext(nullptr);
		delete curPtr;
		curPtr = nullptr;

		itemCount--;
	}

	return ableToRemove;
}

template<class ItemType>
void LinkedSortedList<ItemType>::clear()
{
	while (!isEmpty()) {
		remove(1);
	}
}

template<class ItemType>
const ItemType LinkedSortedList<ItemType>::getEntry(const int position) const
{
	bool ableToGet = (position >= 1) && (position <= itemCount);
	if (ableToGet)
	{
		Node<ItemType>* nodePtr = getNodeAt(position);
		return nodePtr->getItem();
	}
	else
	{
		string message = "getEntry() called with an empty list or ";
		message = message + "invalid position.";
		return  ItemType();
	}
}