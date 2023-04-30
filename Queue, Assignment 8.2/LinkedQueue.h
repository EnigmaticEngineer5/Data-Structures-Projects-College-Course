//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** ADT queue: Link-based implementation.
 Listing 14-3.
 @file LinkedQueue.h */
#ifndef _LINKED_QUEUE
#define _LINKED_QUEUE

#include <cassert>

#include "../Course Source Code/Chapter14/Queue/QueueInterface.h"
#include "../Stacks, Assignment 5.2/LinkedStack.h"
#include "../Queue, Assignment 8.1/PrecondViolatedExcep.h"

template<class ItemType>
class LinkedQueue : public QueueInterface<ItemType>
{
private:
	// The queue is implemented as a chain of linked nodes that has 
	// two external pointers, a head pointer for front of the queue and
	// a tail pointer for the back of the queue.
	Node<ItemType>* backPtr;
	Node<ItemType>* frontPtr;

public:
	LinkedQueue();
	LinkedQueue(const LinkedQueue& aQueue);
	~LinkedQueue();

	bool isEmpty() const;
	bool enqueue(const ItemType& newEntry);
	bool dequeue();

	/** @throw PrecondViolatedExcep if the queue is empty */
	ItemType peekFront() const throw(PrecondViolatedExcep);
}; // end LinkedQueue
#endif

//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

// PARITALLY COMPLETE.

/** @file LinkedQueue.cpp */

template<class ItemType>
inline LinkedQueue<ItemType>::LinkedQueue() : frontPtr(nullptr), backPtr(nullptr) {};

template<class ItemType>
inline LinkedQueue<ItemType>::LinkedQueue(const LinkedQueue& aQueue)
{
	Node<ItemType>* origChain{ aQueue.frontPtr };
	while (origChain){
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
inline bool LinkedQueue<ItemType>::isEmpty() const
{
	return (!frontPtr);
}

template<class ItemType>
bool LinkedQueue<ItemType>::enqueue(const ItemType& newEntry)
{
	Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);

	// Insert the new node
	if (isEmpty())
		frontPtr = newNodePtr;        // Insertion into empty queue
	else
		backPtr->setNext(newNodePtr); // Insertion into nonempty queue

	backPtr = newNodePtr;            // New node is at back

	return true;
}  // end enqueue

template<class ItemType>
bool LinkedQueue<ItemType>::dequeue()
{
	bool result = false;
	if (!isEmpty())
	{
		// Queue is not empty; delete front
		Node<ItemType>* nodeToDeletePtr = frontPtr;
		if (frontPtr == backPtr)
		{  // Special case: one node in queue
			frontPtr = nullptr;
			backPtr = nullptr;
		}
		else
			frontPtr = frontPtr->getNext();

		// Return deleted node to system
		nodeToDeletePtr->setNext(nullptr);
		delete nodeToDeletePtr;
		nodeToDeletePtr = nullptr;

		result = true;
	}  // end if

	return result;
}  // end dequeue

template<class ItemType>
inline ItemType LinkedQueue<ItemType>::peekFront() const throw(PrecondViolatedExcep)
{
	return (isEmpty()) ? cout << "\nThe queue is empty!", ItemType() : frontPtr->getItem();
}