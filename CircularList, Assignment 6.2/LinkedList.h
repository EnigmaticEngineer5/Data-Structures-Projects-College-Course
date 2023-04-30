//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** ADT list: Link-based implementation.
    Listing 9-2.
    @file LinkedList.h */

#ifndef _LINKED_LIST
#define _LINKED_LIST

#include "../Course Source Code/Chapter08/ListInterface.h"
#include "../LinkedLists, Assignment 4.1/Node.h"
#include <cassert>

template<class T>
class LinkedList : public ListInterface<T>
{
private:
    Node<T>* headPtr; // Pointer to first node in the chain;
    // (contains the first entry in the list)
    int itemCount;           // Current count of list items 

    // Locates a specified node in this linked list.
    // @pre  position is the number of the desired node;
    //       position >= 1 and position <= itemCount.
    // @post  The node is found and a pointer to it is returned.
    // @param position  The number of the node to locate.
    // @return  A pointer to the node at the given position.
    Node<T>* getNodeAt(int position) const;

    // Adds a given node at a given position within the subchain pointed to by subChainPtr.
    // Returns a pointer to the augmented subchain.
    Node<T>* insertNode(int newPosition, Node<T>* newNodePtr, Node<T>* subChainPtr);

public:
    LinkedList();
    LinkedList(const LinkedList<T>& aList);
    virtual ~LinkedList();

    bool isEmpty() const;
    int getLength() const;
    bool insert(int newPosition, const T& newEntry);
    bool remove(int position);
    void clear();

    /** @throw PrecondViolatedExcep if position < 1 or
                                       position > getLength(). */
    T getEntry(int position) const throw(PrecondViolatedExcep);

    /** @throw PrecondViolatedExcep if position < 1 or
                                       position > getLength(). */
    //void setEntry(int position, const T& newEntry)
    //    throw(PrecondViolatedExcep);
}; // end LinkedList

#endif 

// The copy constructor and the method setEntry are left as exercises.
// ===================================================================

//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** Implementation file for the class LinkedList.
 @file LinkedList.cpp */

template<class T>
LinkedList<T>::LinkedList() : headPtr(nullptr), itemCount(0)
{
}  // end default constructor

template<class T>
LinkedList<T>::~LinkedList()
{
    clear();
}  // end destructor

template<class T>
bool LinkedList<T>::isEmpty() const
{
    return itemCount == 0;
}  // end isEmpty

template<class T>
int LinkedList<T>::getLength() const
{
    return itemCount;
}  // end getLength

template<class T>
bool LinkedList<T>::insert(int newPosition, const T& newEntry)
{
    bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
    if (ableToInsert)
    {
        // Create a new node containing the new entry
        Node<T>* newNodePtr = new Node<T>(newEntry);
        headPtr = insertNode(newPosition, newNodePtr, headPtr);
    }  // end if

    return ableToInsert;
}  // end insert

template<class T>
bool LinkedList<T>::remove(int position)
{
    bool ableToRemove = (position >= 1) && (position <= itemCount);
    if (ableToRemove)
    {
        Node<T>* curPtr = nullptr;
        if (position == 1)
        {
            // Remove the first node in the chain
            curPtr = headPtr; // Save pointer to node
            headPtr = headPtr->getNext();
        }
        else
        {
            // Find node that is before the one to delete
            Node<T>* prevPtr = getNodeAt(position - 1);

            // Point to node to delete
            curPtr = prevPtr->getNext();

            // Disconnect indicated node from chain by connecting the
            // prior node with the one after
            prevPtr->setNext(curPtr->getNext());
        }  // end if

        // Return node to system
        curPtr->setNext(nullptr);
        delete curPtr;
        curPtr = nullptr;

        itemCount--;  // Decrease count of entries
    }  // end if

    return ableToRemove;
}  // end remove

template<class T>
void LinkedList<T>::clear()
{
    while (!isEmpty())
        remove(1);
}  // end clear

template<class T>
T LinkedList<T>::getEntry(int position) const throw(PrecondViolatedExcep)
{
    // Enforce precondition
    bool ableToGet = (position >= 1) && (position <= itemCount);
    if (ableToGet)
    {
        Node<T>* nodePtr = getNodeAt(position);
        return nodePtr->getItem();
    }
    else
    {
        string message = "getEntry() called with an empty list or ";
        message = message + "invalid position.";
        throw(PrecondViolatedExcep(message));
    }  // end if
}  // end getEntry

template<class T>
Node<T>* LinkedList<T>::getNodeAt(int position) const
{
    // Debugging check of precondition
    assert((position >= 1) && (position <= itemCount));

    // Count from the beginning of the chain
    Node<T>* curPtr = headPtr;
    for (int skip = 1; skip < position; skip++)
        curPtr = curPtr->getNext();

    return curPtr;
}  // end getNodeAt

// RECURSIVE
template<class T>
Node<T>* LinkedList<T>::insertNode(int position, Node<T>* newNodePtr,
    Node<T>* subChainPtr)
{
    if (position == 1)
    {
        // Insert new node at beginning of subchain
        newNodePtr->setNext(subChainPtr);
        subChainPtr = newNodePtr;
        itemCount++;  // Increase count of entries
    }
    else
    {
        Node<T>* afterPtr = insertNode(position - 1, newNodePtr, subChainPtr->getNext());
        subChainPtr->setNext(afterPtr);
    }  // end if

    return subChainPtr;
}  // end insertNode

//  End of implementation file.