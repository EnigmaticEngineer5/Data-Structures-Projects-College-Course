#pragma once

#include "../ADTSortedLists, Assignment 7.1/SortedListInterface.h"
#include "../LinkedLists, Assignment 4.1/Node.h"

#include <assert.h>

template<class ItemType>
class LinkedSortedList final : public SortedListInterface<ItemType>
{
private:
	Node<ItemType>* headPtr;
	int itemCount;

	Node<ItemType>* getNodeBefore(const ItemType&) const;
	Node<ItemType>* getNodeAt(int position) const;
	Node<ItemType>* copyChain(const Node<ItemType>*);
	Node<ItemType>* getPointerTo(const ItemType&) const;

public:
	LinkedSortedList();
	LinkedSortedList(const LinkedSortedList<ItemType>&);
	virtual ~LinkedSortedList();

	void insertSorted(const ItemType&) override;
	const bool removeSorted(const ItemType&) override;
	const int getPosition(const ItemType&) const override;

	const bool isEmpty() const override;
	const int getLength() const override;
	const bool remove1(const int position) override;
	const bool remove(const ItemType& anEntry) override;

	void clear() override;
	const ItemType getEntry(const int position) const throw(PrecondViolatedExcep)override;
	void display() const override;
};

template<class ItemType>
void LinkedSortedList<ItemType>::display() const
{
	Node<ItemType>* currentPtr = headPtr;
	while (currentPtr != nullptr) {
		cout << currentPtr->getItem() << endl;
		currentPtr = currentPtr->getNext();
	}
}

template<class ItemType>
LinkedSortedList<ItemType>::LinkedSortedList() : itemCount(0), headPtr(nullptr) {};

template<class ItemType>
LinkedSortedList<ItemType>::LinkedSortedList(const LinkedSortedList<ItemType>& aList)
{
	headPtr = copyChain(aList.headPtr);
}

template<class ItemType>
void LinkedSortedList<ItemType>::insertSorted(const ItemType& newEntry)
{
	Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
	Node<ItemType>* prevPtr = getNodeBefore(newEntry);
	if (isEmpty() || (prevPtr == nullptr)) {
		newNodePtr->setNext(headPtr);
		headPtr = newNodePtr;
	}
	else {
		Node<ItemType>* aftPtr = prevPtr->getNext();
		newNodePtr->setNext(aftPtr);
		prevPtr->setNext(newNodePtr);
	}
	itemCount++;
}

template<class ItemType>
LinkedSortedList<ItemType>::~LinkedSortedList()
{
	clear();
}

template<class ItemType>
Node<ItemType>* LinkedSortedList<ItemType>::copyChain(const Node<ItemType>* origChainPtr)
{
	Node<ItemType>* copiedChainPtr;
	if (origChainPtr == nullptr) {
		copiedChainPtr = nullptr;
	}
	else {
		copiedChainPtr = new Node<ItemType>(origChainPtr->getItem());
		copiedChainPtr->setNext(copyChain(origChainPtr->getNext()));
	}
	return copiedChainPtr;
}

template<class ItemType>
Node<ItemType>* LinkedSortedList<ItemType>::getNodeBefore(const ItemType& anEntry) const
{
	Node<ItemType>* curPtr = headPtr;
	Node<ItemType>* prevPtr = nullptr;
	while ((curPtr != nullptr) && (static_cast<ItemType>(anEntry) > curPtr->getItem())) {
		prevPtr = curPtr;
		curPtr = curPtr->getNext();
	}
	return prevPtr;
}

template<class ItemType>
const bool LinkedSortedList<ItemType> ::isEmpty() const
{
	return (itemCount == 0);
}

template<class ItemType>
const int LinkedSortedList<ItemType> ::getLength() const
{
	return itemCount;
}

template<class ItemType>
const bool LinkedSortedList<ItemType>::remove(const ItemType& anEntry)
{
	Node<ItemType>* entryNodePtr = getPointerTo(anEntry);
	bool canRemoveItem = !isEmpty() && (entryNodePtr != nullptr);
	if (canRemoveItem) {
		entryNodePtr->setItem(headPtr->getItem());

		Node<ItemType>* nodeToDeletePtr = headPtr;
		headPtr = headPtr->getNext();

		nodeToDeletePtr->setNext(nullptr);
		delete nodeToDeletePtr;
		nodeToDeletePtr = nullptr;

		itemCount--;
	}
	return canRemoveItem;
}

template<class ItemType>
const bool LinkedSortedList<ItemType> ::remove1(int position) {
	bool ableToRemove = (position >= 1) && (position <= itemCount);
	if (ableToRemove) {
		Node<ItemType>* curPtr = nullptr;
		if (position == 1) {
			curPtr = headPtr;
			headPtr = headPtr->getNext();
		}
		else {
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
void LinkedSortedList<ItemType> ::clear()
{
	while (!isEmpty()) {
		remove1(1);
	}
}

template<class ItemType>
const ItemType LinkedSortedList<ItemType> ::getEntry(const int position) const throw(PrecondViolatedExcep)
{
	bool ableToGet = (position >= 1) && (position <= itemCount);
	if (ableToGet) {
		Node<ItemType>* nodePtr = getNodeAt(position);
		return nodePtr->getItem();
	}
	else {
		string message = "getEntry() called with an empty list or ";
		message = message + "invalid position.";
		throw(PrecondViolatedExcep(message));
	}
}

template<class ItemType>
Node<ItemType>* LinkedSortedList<ItemType> ::getNodeAt(int position) const {
	assert((position >= 1) && (position <= itemCount));

	Node<ItemType>* curPtr = headPtr;
	for (int skip = 1; skip < position; skip++) {
		curPtr = curPtr->getNext();
	}
	return curPtr;
}
template<class ItemType>
Node<ItemType>* LinkedSortedList<ItemType>::getPointerTo(const ItemType& anEntry) const
{
	bool found = false;
	Node<ItemType>* curPtr = headPtr;
	while (!found && (curPtr != nullptr)) {
		if (static_cast<ItemType>(anEntry) == curPtr->getItem()) {
			found = true;
		}
		else {
			curPtr = curPtr->getNext();
		}
	}
	return curPtr;
}

template<class ItemType>
const bool LinkedSortedList<ItemType>::removeSorted(const ItemType& anEntry)
{
	bool ableToRemove = false;
	if (!isEmpty()) {
		int position = getPosition(anEntry);
		ableToRemove = position > 0;
		if (ableToRemove) {
			ableToRemove = remove1(position);
		}
	}
	return ableToRemove;
}

template<class ItemType>
const int LinkedSortedList<ItemType>::getPosition(const ItemType& anEntry) const
{
	int position = 1;
	int length = LinkedSortedList<ItemType>::getLength();
	while ((position <= length) &&
		(static_cast<ItemType>(anEntry) > LinkedSortedList<ItemType>::getEntry(position))) {
		position++;
	}
	if ((position > length) ||
		(static_cast<ItemType>(anEntry) != LinkedSortedList<ItemType>::getEntry(position))) {
		position = -position;
	}
	return position;
}
