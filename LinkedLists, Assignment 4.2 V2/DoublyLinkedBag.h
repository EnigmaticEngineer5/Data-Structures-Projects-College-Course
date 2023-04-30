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
	Node<ItemType>* rotateNodes(const ItemType&) const;
	Node<ItemType>* rightRotate(const ItemType&, Node<ItemType>* = nullptr) const override;
	Node<ItemType>* leftRotate(const ItemType&, Node<ItemType>* = nullptr) const override;

	void displayForward() const;
	void displayBackwards() const;

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
			itemCount--;
			cout << "\nNode removed...";
			return true;
		}
		else {
			if (headPtr->getItem() == target) {//Found in first node of list
				Node<ItemType>* nodeToDelete{ headPtr };
				headPtr = headPtr->getNext();

				nodeToDelete->setNext(nullptr);
				delete nodeToDelete;
				nodeToDelete = nullptr;

				headPtr->setPrev(nullptr);

				itemCount--;
				return true;
			}

			//Search target
			Node<ItemType>* targetPtr{ headPtr };
			while ((targetPtr != nullptr) && (targetPtr->getItem() != target)) {
				targetPtr = targetPtr->getNext();
			}

			//Stop if not found
			if (targetPtr == nullptr) {
				return false;
			}

			//Unlink that node and connect the surrounding two
			Node<ItemType>* prev{ targetPtr->getPrev() }, * next{ targetPtr->getNext() };

			if (prev != nullptr) {
				prev->setNext(next);
			}
			if (next != nullptr) {
				next->setPrev(prev);
			}

			prev = nullptr;
			next = nullptr;

			//Prepare target node and move it to beginning of list.
			Node<ItemType>* toMove{ targetPtr };
			targetPtr = nullptr;

			toMove->setPrev(nullptr).setNext(headPtr);
			headPtr->setPrev(toMove);
			headPtr = toMove;

			toMove = nullptr;

			//Get node to delete and disconnect it from the chain.
			Node<ItemType>* nodeToDelete{ headPtr };
			headPtr = headPtr->getNext();
			nodeToDelete->setNext(nullptr);

			//Delete first node...
			delete nodeToDelete;
			nodeToDelete = nullptr;

			//Adjust head again...
			headPtr->setPrev(nullptr).setNext(headPtr->getNext());
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
			cout << curPtr->getItem() << ' ';
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
			cout << curPtr->getItem() << ' ';
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
		return rightRotate(targetItem, headPtr);
	}
	return leftRotate(targetItem, tailPtr);
}

template<class ItemType>
inline  Node<ItemType>* DoublyLinkedBag<ItemType>::rightRotate(const ItemType& target, Node<ItemType>* curPtr) const
{
	//Search target
	while (curPtr != nullptr && curPtr->getItem() != target) {
		curPtr = curPtr->getNext();
	}

	//If not found, return
	if (curPtr == nullptr) {
		return curPtr;
	}

	//Print target and everything after
	int counter{};
	while (curPtr != nullptr) {
		cout << curPtr->getItem() << ' ';
		curPtr = curPtr->getNext();
		counter++;
	}

	//If counter is has not reached max, iterate 
	//through the missing elements by starting on the beginning of the list again.
	Node<ItemType>* origChain{ headPtr };
	while (counter++ != getCurrentSize()) {
		cout << origChain->getItem() << ' ';
		origChain = origChain->getNext();
	}

	return origChain; //Serves as a reference point, 
	//won't return null so it means we found the target.
}

template<class ItemType>
inline  Node<ItemType>* DoublyLinkedBag<ItemType>::leftRotate(const ItemType& target, Node<ItemType>* curPtr) const
{
	while (curPtr != nullptr && curPtr->getItem() != target) {
		curPtr = curPtr->getPrev();
	}

	if (curPtr == nullptr) {
		return curPtr;
	}

	int counter{};
	while (curPtr != nullptr) {
		cout << curPtr->getItem() << ' ';
		curPtr = curPtr->getPrev();
		counter++;
	}

	Node<ItemType>* origTail{ tailPtr };
	while (counter++ != getCurrentSize()) {
		cout << origTail->getItem() << ' ';
		origTail = origTail->getPrev();
	}

	return origTail;
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

		nodeToDeletePtr->setNext(nullptr).setPrev(nullptr);
		nodeToDeletePtr = nullptr;
	}

	while (tailPtr != nullptr)
	{
		Node<ItemType>* nodeToDeletePtr{ tailPtr };
		tailPtr = tailPtr->getPrev();

		nodeToDeletePtr->setPrev(nullptr).setNext(nullptr);
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