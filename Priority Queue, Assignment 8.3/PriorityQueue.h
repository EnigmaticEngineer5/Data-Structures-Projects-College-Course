//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** ADT priority queue: ADT sorted list implementation.
 Listing 14-6.
 @file SL_PriorityQueue.h */

#ifndef _PRIORITY_QUEUE
#define _PRIORITY_QUEUE

#include "PriorityQueueInterface.h"
#include "../ADTSortedLists, Assignment 7.1/LinkedSortedList.h"

template<class ItemType>
class SL_PriorityQueue : public PriorityQueueInterface<ItemType>
{
private:
	LinkedSortedList<ItemType>* slistPtr;  // Pointer to sorted list of
	// items in the priority queue

public:
	SL_PriorityQueue();
	SL_PriorityQueue(const SL_PriorityQueue& pq);
	~SL_PriorityQueue();

	const bool isEmpty() const override;
	const bool add(const ItemType& newEntry) override;
	const bool remove() override;

	/** @throw PrecondViolatedExcep if priority queue is empty. */
	const ItemType peek() const override;
}; // end SL_PriorityQueues

#endif

//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.
// PARITALLY COMPLETE.

/** ADT priority queue: ADT sorted list implementation.
 @file SL_PriorityQueue.cpp */

template<class ItemType>
inline SL_PriorityQueue<ItemType>::SL_PriorityQueue() : slistPtr(new LinkedSortedList<ItemType>{})
{
}

template<class ItemType>
inline SL_PriorityQueue<ItemType>::SL_PriorityQueue(const SL_PriorityQueue& pq) : slistPtr(pq.slistPtr)
{
}

template<class ItemType>
inline SL_PriorityQueue<ItemType>::~SL_PriorityQueue()
{
	cout << "SL_PriorityQueue destructor invoked...";
}

template<class ItemType>
inline const bool SL_PriorityQueue<ItemType>::isEmpty() const
{
	return slistPtr->isEmpty();
}

template<class ItemType>
const bool SL_PriorityQueue<ItemType>::add(const ItemType& newEntry)
{
	slistPtr->insertSorted(newEntry);
	return true;
}  // end add

template<class ItemType>
const bool SL_PriorityQueue<ItemType>::remove()
{
	// The highest priority item is at the end of the sorted list
	return slistPtr->remove(slistPtr->getLength());
}  // end remove

template<class ItemType>
inline const ItemType SL_PriorityQueue<ItemType>::peek() const
{
	return slistPtr->getEntry(1);
}