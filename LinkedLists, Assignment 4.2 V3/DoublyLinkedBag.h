#pragma once

#include "BagInterface.h"

template<class ItemType>
class DoublyLinkedBag : public BagInterface<ItemType>
{
private:
	Node <ItemType>* headPtr;
	Node <ItemType>* tailPtr;
	int itemCount;

public:
	DoublyLinkedBag();
	DoublyLinkedBag(const DoublyLinkedBag<ItemType>&);
	virtual ~DoublyLinkedBag();

	//Requested methods...
	const bool addToBeginning(const ItemType&) override;
	const bool removeFirstNode(const ItemType&) override;
	void displayForward() const;
	void displayBackwards() const;

	Node<ItemType>* rotateNodes(const ItemType&) const;
	Node<ItemType>* rightRotate(const ItemType&, Node<ItemType>* = nullptr) const override;
	Node<ItemType>* leftRotate(const ItemType&, Node<ItemType>* = nullptr) const override;

	//Default methods...
	const int getCurrentSize() const override;
	const bool isEmpty() const override;
	const bool add(const ItemType&) override;
	void clear() override;
	const int getFrequencyOf(const ItemType&) const override;
	const bool contains(const ItemType&) const override;
};

template<class ItemType>
inline DoublyLinkedBag<ItemType>::DoublyLinkedBag()
	: headPtr(nullptr), tailPtr(nullptr), itemCount{}
{
	cout << "\nDoublyLinkedBag constructor invoked...";
};

template<class ItemType>
inline DoublyLinkedBag<ItemType>::DoublyLinkedBag(const DoublyLinkedBag<ItemType>& sourceBag)
	: itemCount{}, headPtr(sourceBag.headPtr), tailPtr(sourceBag.tailPtr)
{
	cout << "\nDoublyLinkedBag copy constructor invoked...";

	Node<ItemType>* origChainPtr{ sourceBag.headPtr };  // Points to nodes in original chain
	while (origChainPtr != nullptr)
	{
		add(origChainPtr->getItem());
		origChainPtr = origChainPtr->getNext();
	}
}

template<class ItemType>
inline DoublyLinkedBag<ItemType>::~DoublyLinkedBag()
{
	clear();
	cout << "\nDoublyLinkedBag released...";
}

template<class ItemType>
inline const bool DoublyLinkedBag<ItemType>::addToBeginning(const ItemType& newEntry)
{
	if (isEmpty())
	{
		return add(newEntry);
	}
	else
	{
		Node<ItemType>* newNodePtr{ new Node<ItemType>{newEntry} }, * origTail{ tailPtr };
		headPtr->setPrev(newNodePtr);
		newNodePtr->setNext(headPtr).setPrev(nullptr);
		headPtr = newNodePtr;

		while (origTail != nullptr) {
			origTail = origTail->getPrev();
		}
		origTail = newNodePtr;

		itemCount++;
		cout << "\nNode added...\n";

		return true;
	}
}

template<class ItemType>
inline const bool DoublyLinkedBag<ItemType>::removeFirstNode(const ItemType& target)
{
	if (isEmpty()) {
		cout << "\nNo more nodes available to remove!";
	}
	else {
		if (getCurrentSize() == 1) {
			delete headPtr;
		}
		else {
			if (headPtr->getItem() == target) {
				Node<ItemType>* nodeToDelete{ headPtr };
				headPtr = headPtr->getNext();
				delete nodeToDelete;
			}
			else {
				Node<ItemType>* currentHead = headPtr, *currentTail = tailPtr;

				// Traverse the doubly linked list and search for the target node
				while (currentHead != nullptr && currentHead->getItem() != target) {
					currentHead = currentHead->getNext();
					currentTail = currentTail->getPrev();
				}

				// If the target node is found
				if (currentHead != nullptr) {
					// Update the previous node and next node pointers to point to each other
					Node<ItemType>* prev1 = currentHead->getPrev();
					Node<ItemType>* next1 = currentHead->getNext();
					Node<ItemType>* prev2 = currentTail->getPrev();
					if (prev1 != nullptr) {
						prev1->setNext(next1);
					}

					if (next1 != nullptr) {
						next1->setPrev(prev1);
					}

					if (prev2 != nullptr) {
						currentTail->setPrev(prev2);
					}

					// Move the target node to the beginning of the doubly linked list
				/*	if (currentHead == tailPtr) {
						tailPtr = prev;
					}*/
					currentHead->setPrev(nullptr);
					currentHead->setNext(headPtr);
					headPtr->setPrev(currentHead);
					headPtr = currentHead;
					// Delete the target node from the memory
					delete prev1;
					itemCount--;

				}
				else {
					return false;
				}
			}
		}

		itemCount--;
		cout << "\nNode removed...";

		return true;
	}
	return false;
}

template<class ItemType>
inline void DoublyLinkedBag<ItemType>::displayForward() const
{
	if (isEmpty()) {
		cout << "\nThere are no elements to display...";
	}
	else {
		cout << '\n';
		Node <ItemType>* curPtr{ headPtr };
		while (curPtr != nullptr) {
			cout << curPtr->getItem() << '\n';
			curPtr = curPtr->getNext();
		}
	}
}

template<class ItemType>
inline void DoublyLinkedBag<ItemType>::displayBackwards() const
{
	if (isEmpty()) {
		cout << "\nThere are no elements to display...";
	}
	else {
		cout << '\n';
		Node <ItemType>* curPtr{ tailPtr };
		while (curPtr != nullptr) {
			cout << curPtr->getItem() << '\n';
			curPtr = curPtr->getPrev();
		}
	}
}

template<class ItemType>
inline Node<ItemType>* DoublyLinkedBag<ItemType>::rotateNodes(const ItemType& targetItem) const
{
	cout << "\n\t1) Right rotate"
		<< "\n\t2) Left rotate"
		<< "\nAnswer --> ";
	int direction{};
	cin >> direction;

	if (direction == 1) {
	}
	return leftRotate(targetItem, tailPtr);
}

template<class ItemType>
inline  Node<ItemType>* DoublyLinkedBag<ItemType>::rightRotate(const ItemType& target, Node<ItemType>* curPtr) const
{
	Node<ItemType>* result{ nullptr };
	if (curPtr != nullptr)
	{
		if (target == curPtr->getItem())
		{
			result = curPtr;
		}
		else
		{
			result = rightRotate(target, curPtr->getNext());
		}
	}

	return result;
}

template<class ItemType>
inline  Node<ItemType>* DoublyLinkedBag<ItemType>::leftRotate(const ItemType& target, Node<ItemType>* curPtr) const
{
	Node<ItemType>* result{ nullptr };
	if (curPtr != nullptr)
	{
		if (target == curPtr->getItem())
		{
			result = curPtr;
		}
		else
		{
			result = leftRotate(target, curPtr->getPrev());
		}
	}

	return result;
}

template<class ItemType>
inline const int DoublyLinkedBag<ItemType>::getCurrentSize() const
{
	return itemCount;
}

template<class ItemType>
inline const bool DoublyLinkedBag<ItemType>::isEmpty() const
{
	return (itemCount == 0);
}

template<class ItemType>
inline const bool DoublyLinkedBag<ItemType>::add(const ItemType& newEntry)
{
	Node<ItemType>* newNodePtr{ new Node<ItemType>{newEntry} };
	if (itemCount == 0)
	{
		newNodePtr->setNext(nullptr).setPrev(nullptr);
		headPtr = newNodePtr;
		tailPtr = newNodePtr;
	}
	else
	{
		newNodePtr->setNext(nullptr).setPrev(tailPtr);
		tailPtr->setNext(newNodePtr);
	}

	tailPtr = newNodePtr;
	itemCount++;

	return true;
}

template< class ItemType>
inline void DoublyLinkedBag<ItemType>::clear() {
	while (headPtr != nullptr)
	{
		Node<ItemType>* nodeToDeletePtr{ headPtr };
		headPtr = headPtr->getNext();

		nodeToDeletePtr->setNext(nullptr);
		delete nodeToDeletePtr;
		nodeToDeletePtr = nullptr;
	}

	while (tailPtr != nullptr)
	{
		Node<ItemType>* nodeToDeletePtr{ tailPtr };
		tailPtr = tailPtr->getPrev();

		if (tailPtr != nullptr)
		{
			tailPtr->setNext(nullptr);
		}

		nodeToDeletePtr->setPrev(nullptr);
		nodeToDeletePtr = nullptr;
	}

	itemCount = 0;
}

template< class ItemType>
inline const int DoublyLinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
	int frequency{}, counter{};
	Node<ItemType>* curPtr{ headPtr };

	while ((curPtr != nullptr) && (counter < itemCount))
	{
		if (anEntry == curPtr->getItem())
		{
			frequency++;
		}
		counter++;
		curPtr = curPtr->getNext();
	}

	curPtr = nullptr;

	return frequency;
}

template< class ItemType>
inline const bool DoublyLinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
	return (leftRotate(anEntry, headPtr) != nullptr);
}