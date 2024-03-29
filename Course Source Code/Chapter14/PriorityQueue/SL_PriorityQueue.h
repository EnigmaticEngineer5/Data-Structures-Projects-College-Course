//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** ADT priority queue: ADT sorted list implementation.
 Listing 14-6.
 @file SL_PriorityQueue.h */

#ifndef _PRIORITY_QUEUE
#define _PRIORITY_QUEUE

#include "PriorityQueueInterface.h"
#include "LinkedSortedList.h"
#include "PrecondViolatedExcep.h"

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

   bool isEmpty() const;
   bool add(const ItemType& newEntry);
   bool remove();

   /** @throw PrecondViolatedExcep if priority queue is empty. */
   ItemType peek() const throw(PrecondViolatedExcep);
}; // end SL_PriorityQueue

#endif

//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.
// PARITALLY COMPLETE.

/** ADT priority queue: ADT sorted list implementation.
 @file SL_PriorityQueue.cpp */

template<class ItemType>
bool SL_PriorityQueue<ItemType>::add(const ItemType& newEntry)
{
    slistPtr->insertSorted(newEntry);
    return true;
}  // end add

template<class ItemType>
bool SL_PriorityQueue<ItemType>::remove()
{
    // The highest priority item is at the end of the sorted list
    return slistPtr->remove(slistPtr->getLength());
}  // end remove


