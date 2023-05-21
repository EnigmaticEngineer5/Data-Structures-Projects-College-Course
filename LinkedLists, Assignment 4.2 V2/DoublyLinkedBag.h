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
	explicit DoublyLinkedBag(Node<ItemType>*);
	DoublyLinkedBag(const DoublyLinkedBag<ItemType>&);
	virtual ~DoublyLinkedBag();

	const bool addToBeginning(const ItemType&) override;
	const bool removeFirstNode(const ItemType&) override;
	Node<ItemType>* rotateNodes(const ItemType&);
	Node<ItemType>* rightRotate(const ItemType&, Node<ItemType>* = nullptr)  override;
	Node<ItemType>* leftRotate(const ItemType&, Node<ItemType>* = nullptr)  override;

	void displayForward() const;
	void displayBackwards() const;

	const int getCurrentSize() const override;
	const bool isEmpty() const override;
	const bool add(const ItemType&) override;
	void clear() override;
	const int getFrequencyOf(const ItemType&) const override;
	const bool contains(const ItemType&) const override;
};

template<class ItemType>
inline DoublyLinkedBag<ItemType>::DoublyLinkedBag()
	: headPtr(nullptr), tailPtr(nullptr), itemCount{} {};

template<class ItemType>
inline DoublyLinkedBag<ItemType>::DoublyLinkedBag(Node<ItemType>* sourceHead)
{
	Node<ItemType>* origChainPtr{ sourceHead };
	while (origChainPtr != nullptr) {
		add(origChainPtr->getItem());
		origChainPtr = origChainPtr->getNext();
	}
}

template<class ItemType>
inline DoublyLinkedBag<ItemType>::DoublyLinkedBag(const DoublyLinkedBag<ItemType>& sourceBag)
	: itemCount{}, headPtr(sourceBag.headPtr), tailPtr(sourceBag.tailPtr)
{
	Node<ItemType>* origChainPtr{ sourceBag.headPtr };
	while (origChainPtr != nullptr)
	{
		add(origChainPtr->getItem());
		origChainPtr = origChainPtr->getNext();
	}
}

template<class ItemType>
inline DoublyLinkedBag<ItemType>::~DoublyLinkedBag() { clear(); };

template<class ItemType>
inline const bool DoublyLinkedBag<ItemType>::addToBeginning(const ItemType& newEntry)
{
	if (isEmpty()) {
		return add(newEntry);
	}
	else {
		Node<ItemType>* newNodePtr{ new Node<ItemType>{newEntry} };

		newNodePtr->setNext(headPtr);
		headPtr->setPrev(newNodePtr);
		headPtr = newNodePtr;

		itemCount++;

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
			if (headPtr->getItem() == target) {
				Node<ItemType>* nodeToDelete{ headPtr };
				headPtr = headPtr->getNext();

				nodeToDelete->setNext(nullptr);
				delete nodeToDelete;
				nodeToDelete = nullptr;

				headPtr->setPrev(nullptr);

				itemCount--;
				return true;
			}

			Node<ItemType>* targetPtr{ headPtr };
			while ((targetPtr != nullptr) && (targetPtr->getItem() != target)) {
				targetPtr = targetPtr->getNext();
			}

			if (targetPtr == nullptr) {
				return false;
			}

			Node<ItemType>* prev{ targetPtr->getPrev() }, * next{ targetPtr->getNext() };

			if (prev != nullptr) {
				prev->setNext(next);
			}
			if (next != nullptr) {
				next->setPrev(prev);
			}

			prev = nullptr;
			next = nullptr;

			Node<ItemType>* toMove{ targetPtr };
			targetPtr = nullptr;

			toMove->setPrev(nullptr).setNext(headPtr);
			headPtr->setPrev(toMove);
			headPtr = toMove;

			toMove = nullptr;

			Node<ItemType>* nodeToDelete{ headPtr };
			headPtr = headPtr->getNext();
			nodeToDelete->setNext(nullptr);

			delete nodeToDelete;
			nodeToDelete = nullptr;

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
		cout << "\nList Fowards --> ";

		Node <ItemType>* curPtr{ headPtr };
		while (curPtr != nullptr) {
			cout << curPtr->getItem() << ' ';
			curPtr = curPtr->getNext();
		}
		cout << '\n';
	}
}

template<class ItemType>
inline void DoublyLinkedBag<ItemType>::displayBackwards() const
{
	if (isEmpty()) {
		cout << "\nThere are no elements to display...";
	}
	else {
		cout << "\nList Backwards --> ";
		Node <ItemType>* curPtr{ tailPtr };
		while (curPtr != nullptr) {
			cout << curPtr->getItem() << ' ';
			curPtr = curPtr->getPrev();
		}
		cout << '\n';
	}
}

template<class ItemType>
Node<ItemType>* DoublyLinkedBag<ItemType>::rotateNodes(const ItemType& item)
{
	if (isEmpty()) {
		return nullptr;
	}

	if (!contains(item)) {
		return nullptr;
	}

	cout << "\nSelect the direction of the rotations"
		<< "\n\t1) Right"
		<< "\n\t2) Left";

	int choice{};
	bool isValid{ false };
	while (!isValid) {
		try {
			cout << "\nEnter choice --> ";
			cin >> choice;

			if (choice < 1 || choice > 2 || cin.fail()) {
				throw std::invalid_argument("Invalid choice...");
			}
			else {
				isValid = true;
			}
		}
		catch (const std::exception& e) {
			cout << e.what() << '\n';
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}

	if (choice == 1) {
		return rightRotate(item, headPtr);
	}
	else if (choice == 2) {
		return leftRotate(item, tailPtr);
	}
	else {
		cout << "\nInvalid choice...";
		return nullptr;
	}
}

template<class ItemType>
Node<ItemType>* DoublyLinkedBag<ItemType>::rightRotate(const ItemType& target, Node<ItemType>* currentNode)
{
	if (currentNode == nullptr) {
		currentNode = rotateNodes(target);
	}
	if (currentNode == nullptr) {
		return nullptr;
	}

	DoublyLinkedBag oldCopy(headPtr);

	Node<ItemType>* tailNode = tailPtr;
	while (tailNode != currentNode) {
		ItemType tempItem = tailNode->getItem();

		tailNode->setItem(tailNode->getPrev()->getItem());
		tailNode->getPrev()->setItem(tempItem);
		tailNode = tailNode->getPrev();
	}
	ItemType tempItem = currentNode->getItem();

	currentNode->setItem(tailNode->getItem());
	tailNode->setItem(tempItem);

	cout << "\nOld copy: ";
	oldCopy.displayForward();

	cout << "\nNew chain: ";
	displayForward();

	cout << "\n";
	return currentNode;
}

template<class ItemType>
Node<ItemType>* DoublyLinkedBag<ItemType>::leftRotate(const ItemType& target, Node<ItemType>* currentNode)
{
	if (currentNode == nullptr) {
		currentNode = rotateNodes(target);
	}
	if (currentNode == nullptr) {
		return nullptr;
	}

	DoublyLinkedBag oldCopy(headPtr);

	Node<ItemType>* headNode = headPtr;
	while (headNode != currentNode) {
		ItemType tempItem = headNode->getItem();

		headNode->setItem(headNode->getNext()->getItem());
		headNode->getNext()->setItem(tempItem);
		headNode = headNode->getNext();
	}
	ItemType tempItem = currentNode->getItem();

	currentNode->setItem(headNode->getItem());
	headNode->setItem(tempItem);

	cout << "\nOld copy: ";
	oldCopy.displayForward();

	cout << "\nNew chain: ";
	displayForward();

	cout << "\n";
	return currentNode;
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
	if (itemCount == 0) {
		newNodePtr->setNext(nullptr).setPrev(nullptr);
		headPtr = newNodePtr;
		tailPtr = newNodePtr;
	}
	else {
		newNodePtr->setNext(nullptr).setPrev(tailPtr);
		tailPtr->setNext(newNodePtr);
	}

	tailPtr = newNodePtr;
	itemCount++;

	return true;
}

template< class ItemType>
inline void DoublyLinkedBag<ItemType>::clear()
{
	while (headPtr != nullptr) {
		Node<ItemType>* nodeToDeletePtr{ headPtr };
		headPtr = headPtr->getNext();

		nodeToDeletePtr->setNext(nullptr).setPrev(nullptr);
		nodeToDeletePtr = nullptr;
	}

	while (tailPtr != nullptr) {
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
	int frequency{};
	int counter{};
	Node<ItemType>* curPtr{ headPtr };

	while ((curPtr != nullptr) && (counter < itemCount)) {
		if (anEntry == curPtr->getItem()) {
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
	Node<ItemType>* curPtr{ headPtr };
	while (curPtr != tailPtr) {
		if (anEntry == curPtr->getItem()) {
			return true;
		}
		curPtr = curPtr->getNext();
	}
	return false;
}