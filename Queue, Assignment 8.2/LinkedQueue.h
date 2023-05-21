#pragma once

#include <cassert>

#include "../Course Source Code/Chapter14/Queue/QueueInterface.h"
#include "../LinkedLists, Assignment 4.1/Node.h"
#include "../Queue, Assignment 8.1/PrecondViolatedExcep.h"

template<class ItemType>
class LinkedQueue final : public QueueInterface<ItemType>
{
private:
	Node<ItemType>* backPtr;
	Node<ItemType>* frontPtr;

public:
	LinkedQueue();
	LinkedQueue(const LinkedQueue&);
	virtual ~LinkedQueue();

	const bool isEmpty() const override;
	const bool enqueue(const ItemType&) override;
	const bool dequeue() override;
	 
	const ItemType peekFront() const throw(PrecondViolatedExcep) override;
};

template<class ItemType>
inline LinkedQueue<ItemType>::LinkedQueue() : frontPtr(nullptr), backPtr(nullptr) {};

template<class ItemType>
inline LinkedQueue<ItemType>::LinkedQueue(const LinkedQueue& aQueue)
{
	Node<ItemType>* origChain{ aQueue.frontPtr };
	while (origChain) {
		enqueue(origChain->getItem());
		origChain = origChain->getNext();
	}
}

template<class ItemType>
inline LinkedQueue<ItemType>::~LinkedQueue()
{
	while (frontPtr) {
		dequeue();
	}
}

template<class ItemType>
inline const bool LinkedQueue<ItemType>::isEmpty() const
{
	return (!frontPtr);
}

template<class ItemType>
inline const bool LinkedQueue<ItemType>::enqueue(const ItemType& newEntry)
{
	Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);

	if (isEmpty()) {
		frontPtr = newNodePtr;
	}
	else {
		backPtr->setNext(newNodePtr);
	}
	backPtr = newNodePtr;

	return true;
}

template<class ItemType>
inline const bool LinkedQueue<ItemType>::dequeue()
{
	bool result = false;
	if (!isEmpty()) {
		Node<ItemType>* nodeToDeletePtr = frontPtr;
		if (frontPtr == backPtr) {
			frontPtr = nullptr;
			backPtr = nullptr;
		}
		else {
			frontPtr = frontPtr->getNext();
		}

		nodeToDeletePtr->setNext(nullptr);
		delete nodeToDeletePtr;
		nodeToDeletePtr = nullptr;

		result = true;
	}

	return result;
}

template<class ItemType>
inline const ItemType LinkedQueue<ItemType>::peekFront() const throw(PrecondViolatedExcep)
{
	return (isEmpty()) ? cout << "\nThe queue is empty!", ItemType() : frontPtr->getItem();
}