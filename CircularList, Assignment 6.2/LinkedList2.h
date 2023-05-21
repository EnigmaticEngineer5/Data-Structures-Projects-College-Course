//#pragma once
//#include "../LinkedLists, Assignment 4.2 V2/Node.h"
//
//#include <cassert>
//#include <iostream>
//
//using namespace std;
//
//template<class ItemType>
//class LinkedList
//{
//private:
//	Node<ItemType>* headPtr;
//	Node<ItemType>* tailPtr;
//	Node<ItemType>* dummyNode;
//	int itemCount;
//
//	Node<ItemType>* getNodeAt(int position) const;
//	Node<ItemType>* insertNode(int newPosition, Node<ItemType>* newNodePtr, Node<ItemType>* subChainPtr);
//
//public:
//	LinkedList();
//	LinkedList(const LinkedList<ItemType>& aList);
//	virtual ~LinkedList();
//
//	bool isEmpty() const;
//	int getLength() const;
//	bool insert(int newPosition, const ItemType& newEntry);
//	bool remove(int position);
//	void clear();
//
//	const ItemType getEntry(int position) const;
//	void setEntry(int position, const ItemType& newEntry);
//
//	void reverse();
//};
//
//template<class ItemType>
//LinkedList<ItemType>::LinkedList() :
//	itemCount(0) {
//	dummyNode = new Node<ItemType>();
//	headPtr = tailPtr = dummyNode;
//	dummyNode->setNext(headPtr);
//	dummyNode->setPrev(tailPtr);
//	tailPtr->setNext(headPtr);
//};
//
//
//template<class ItemType>
//LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList) : itemCount(aList.itemCount)
//{
//	if (aList.headPtr == nullptr) {
//		headPtr = tailPtr = dummyNode = new Node<ItemType>();
//		dummyNode->setNext(headPtr);
//		dummyNode->setPrev(tailPtr);
//		tailPtr->setNext(headPtr);
//	}
//	else {
//		Node<ItemType>* origChainPtr = aList.headPtr;
//		headPtr = new Node<ItemType>();
//		headPtr->setItem(origChainPtr->getItem());
//		Node<ItemType>* newChainPtr = headPtr;
//		origChainPtr = origChainPtr->getNext();
//
//		while (origChainPtr != aList.headPtr)
//		{
//			ItemType nextItem = origChainPtr->getItem();
//			Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
//			newChainPtr->setNext(newNodePtr);
//			newNodePtr->setPrev(newChainPtr);
//			newChainPtr = newChainPtr->getNext();
//			origChainPtr = origChainPtr->getNext();
//		}
//
//		tailPtr = newChainPtr->getPrev();
//		dummyNode = new Node<ItemType>();
//		dummyNode->setNext(headPtr);
//		dummyNode->setPrev(tailPtr);
//		tailPtr->setNext(headPtr);
//	}
//}
//
//template<class ItemType>
//LinkedList<ItemType>::~LinkedList() { clear(); };
//
//template<class ItemType>
//bool LinkedList<ItemType>::isEmpty() const { return itemCount == 0; };
//
//template<class ItemType>
//int LinkedList<ItemType>::getLength() const { return itemCount; };
//
//template<class ItemType>
//bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry)
//{
//	bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
//	if (ableToInsert)
//	{
//		Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
//		headPtr = insertNode(newPosition, newNodePtr, headPtr);
//		itemCount++;
//
//		if (newPosition == 1)
//			dummyNode->setNext(headPtr);
//	}
//
//	return ableToInsert;
//}

//template<class ItemType>
//bool LinkedList<ItemType>::remove(int position)
//{
//	bool ableToRemove = (position >= 1) && (position <= itemCount);
//	if (ableToRemove)
//	{
//		Node<ItemType>* curPtr = nullptr;
//		if (position == 1)
//		{
//			curPtr = headPtr;
//			headPtr = headPtr->getNext();
//			dummyNode->setNext(headPtr);
//
//			if (itemCount == 1) {
//				tailPtr = dummyNode;
//			}
//		}
//		else if (position == itemCount)
//		{
//			curPtr = tailPtr;
//			tailPtr = tailPtr->getPrev();
//			tailPtr->setNext(headPtr);
//
//			if (itemCount == 1) {
//				headPtr = dummyNode;
//			}
//		}
//		else
//		{
//			Node<ItemType>* prevPtr = getNodeAt(position - 1);
//			curPtr = prevPtr->getNext();
//			prevPtr->setNext(curPtr->getNext());
//		}
//
//		curPtr->setNext(nullptr);
//		delete curPtr;
//		curPtr = nullptr;
//
//		itemCount--;
//	}
//
//	return ableToRemove;
//}
//
//template<class ItemType>
//void LinkedList<ItemType>::clear()
//{
//	while (!isEmpty()) {
//		remove(1);
//	}
//}
//
//template<class ItemType>
//const ItemType LinkedList<ItemType>::getEntry(int position) const
//{
//	bool ableToGet = (position >= 1) && (position <= itemCount);
//	if (ableToGet)
//	{
//		Node<ItemType>* nodePtr = getNodeAt(position);
//		return nodePtr->getItem();
//	}
//	else
//	{
//		cout << "\nUnable to get requested item, invalid index...";
//	}
//
//	return ItemType();
//}
//
//template<class ItemType>
//void LinkedList<ItemType>::setEntry(int position, const ItemType& newEntry)
//{
//	bool ableToSet = (position >= 1) && (position <= itemCount);
//	if (ableToSet)
//	{
//		Node<ItemType>* nodePtr = getNodeAt(position);
//		nodePtr->setItem(newEntry);
//	}
//	else
//	{
//		cout << "\nUnable to get requested item, invalid index...";
//	}
//
//}
//
//template<class ItemType>
//Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const
//{
//	if (position < 1 || position > itemCount) {
//		return nullptr;
//	}
//
//	Node<ItemType>* curPtr = headPtr;
//	for (int i = 1; i < position; i++) {
//		curPtr = curPtr->getNext();
//	}
//
//	return curPtr;
//}
//
//
//template<class ItemType>
//Node<ItemType>* LinkedList<ItemType>::insertNode(int newPosition, Node<ItemType>* newNodePtr, Node<ItemType>* subChainPtr)
//{
//	if (newPosition == 1)
//	{
//		newNodePtr->setNext(subChainPtr);
//		subChainPtr->setPrev(newNodePtr);
//		subChainPtr = newNodePtr;
//	}
//	else
//	{
//		Node<ItemType>* afterPtr = insertNode(newPosition - 1, newNodePtr, subChainPtr->getNext());
//		subChainPtr->setNext(afterPtr);
//		afterPtr->setPrev(subChainPtr);
//	}
//	return subChainPtr;
//}
//
//template<class ItemType>
//void LinkedList<ItemType>::reverse()
//{
//	if (headPtr == nullptr) {
//		return;
//	}
//
//	Node<ItemType>* prevPtr = tailPtr;
//	Node<ItemType>* curPtr = headPtr;
//	Node<ItemType>* nextPtr = curPtr->getNext();
//
//	while (curPtr != dummyNode) {
//		curPtr->setNext(prevPtr);
//		prevPtr->setPrev(curPtr);
//		prevPtr = curPtr;
//		curPtr = nextPtr;
//		if (nextPtr != dummyNode) {
//			nextPtr = nextPtr->getNext();
//		}
//	}
//
//	tailPtr = headPtr;
//	headPtr = prevPtr;
//}

#pragma once

#include "../LinkedLists, Assignment 4.2 V2/Node.h"

#include <cassert>
#include <iostream>

using namespace std;

template<class ItemType>
class LinkedList {
public:
	LinkedList();
	LinkedList(const LinkedList<ItemType>& other);
	~LinkedList();

	bool isEmpty() const;
	int getLength() const;

	bool insert(int position, const ItemType& item);
	bool remove(int position);

	const ItemType getEntry(int position) const;
	void setEntry(int position, const ItemType& item);

	void reverse();

private:
	Node<ItemType>* headPtr = nullptr;
	Node<ItemType>* tailPtr = nullptr;
	Node<ItemType>* dummyNode = nullptr;
	int itemCount = 0;

	Node<ItemType>* getNodeAt(int position) const;
	Node<ItemType>* insertNode(int newPosition, Node<ItemType>* newNodePtr, Node<ItemType>* subChainPtr);
	void clear();
};

template<class ItemType>
LinkedList<ItemType>::LinkedList() {
	dummyNode = new Node<ItemType>();
	headPtr = tailPtr = dummyNode;
	dummyNode->setNext(headPtr);
	dummyNode->setPrev(tailPtr);
	tailPtr->setNext(headPtr);
}

template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& other) : itemCount(other.itemCount) {
	if (other.headPtr == nullptr) {
		headPtr = tailPtr = dummyNode = new Node<ItemType>();
		dummyNode->setNext(headPtr);
		dummyNode->setPrev(tailPtr);
		tailPtr->setNext(headPtr);
	}
	else {
		Node<ItemType>* origChainPtr = other.headPtr;
		headPtr = new Node<ItemType>();
		headPtr->setItem(origChainPtr->getItem());
		Node<ItemType>* newChainPtr = headPtr;
		origChainPtr = origChainPtr->getNext();

		while (origChainPtr != other.headPtr) {
			ItemType nextItem = origChainPtr->getItem();
			Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
			newChainPtr->setNext(newNodePtr);
			newNodePtr->setPrev(newChainPtr);
			newChainPtr = newChainPtr->getNext();
			origChainPtr = origChainPtr->getNext();
		}

		tailPtr = newChainPtr->getPrev();
		dummyNode = new Node<ItemType>();
		dummyNode->setNext(headPtr);
		dummyNode->setPrev(tailPtr);
		tailPtr->setNext(headPtr);
	}
}

template<class ItemType>
LinkedList<ItemType>::~LinkedList() {
	clear();
}

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const {
	return itemCount == 0;
}

template<class ItemType>
int LinkedList<ItemType>::getLength() const {
	return itemCount;
}

template<class ItemType>
bool LinkedList<ItemType>::insert(int position, const ItemType& item) {
	bool ableToInsert = (position >= 1) && (position <= itemCount + 1);
	if (ableToInsert) {
		Node<ItemType>* newNodePtr = new Node<ItemType>(item);
		headPtr = insertNode(position, newNodePtr, headPtr);
		itemCount++;

		if (position == 1)
			dummyNode->setNext(headPtr);
	}

	return ableToInsert;
}

template<class ItemType>
bool LinkedList<ItemType>::remove(int position)
{
	if (position < 1 || position > itemCount) {
		return false;
	}

	Node<ItemType>* nodeToDelete = nullptr;
	if (position == 1) {
		nodeToDelete = headPtr;
		headPtr = headPtr->getNext();
		dummyNode->setNext(headPtr);

		if (itemCount == 1) {
			tailPtr = dummyNode;
		}
	}
	else if (position == itemCount) {
		nodeToDelete = tailPtr;
		tailPtr = tailPtr->getPrev();
		tailPtr->setNext(headPtr);

		if (itemCount == 1) {
			headPtr = dummyNode;
		}
	}
	else {
		Node<ItemType>* prevPtr = getNodeAt(position - 1);
		nodeToDelete = prevPtr->getNext();
		prevPtr->setNext(nodeToDelete->getNext());
	}

	nodeToDelete->setNext(nullptr);
	delete nodeToDelete;
	nodeToDelete = nullptr;

	itemCount--;
	return true;
}

template<class ItemType>
void LinkedList<ItemType>::clear()
{
	while (!isEmpty()) {
		remove(1);
	}
}

template<class ItemType>
const ItemType LinkedList<ItemType>::getEntry(int position) const
{
	if (position < 1 || position > itemCount) {
		throw std::out_of_range("Invalid index");
	}

	Node<ItemType>* nodePtr = getNodeAt(position);
	return nodePtr->getItem();
}

template<class ItemType>
void LinkedList<ItemType>::setEntry(int position, const ItemType& newEntry)
{
	if (position < 1 || position > itemCount) {
		throw std::out_of_range("Invalid index");
	}

	Node<ItemType>* nodePtr = getNodeAt(position);
	nodePtr->setItem(newEntry);
}

template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const
{
	if (position < 1 || position > itemCount) {
		return nullptr;
	}

	Node<ItemType>* curPtr = headPtr;
	for (int i = 1; i < position; i++) {
		curPtr = curPtr->getNext();
	}

	return curPtr;
}

template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::insertNode(int newPosition, Node<ItemType>* newNodePtr, Node<ItemType>* subChainPtr)
{
	if (newPosition == 1)
	{
		newNodePtr->setNext(subChainPtr);
		subChainPtr->setPrev(newNodePtr);
		subChainPtr = newNodePtr;
	}
	else
	{
		Node<ItemType>* afterPtr = insertNode(newPosition - 1, newNodePtr, subChainPtr->getNext());
		subChainPtr->setNext(afterPtr);
		afterPtr->setPrev(subChainPtr);
	}
	return subChainPtr;
}

template<class ItemType>
void LinkedList<ItemType>::reverse()
{
	if (headPtr == nullptr) {
		return;
	}

	Node<ItemType>* prevPtr = tailPtr;
	Node<ItemType>* curPtr = headPtr;
	Node<ItemType>* nextPtr = curPtr->getNext();

	while (curPtr != dummyNode) {
		curPtr->setNext(prevPtr);
		prevPtr->setPrev(curPtr);
		prevPtr = curPtr;
		curPtr = nextPtr;
		if (nextPtr != dummyNode) {
			nextPtr = nextPtr->getNext();
		}
	}

	tailPtr = headPtr;
	headPtr = prevPtr;
}