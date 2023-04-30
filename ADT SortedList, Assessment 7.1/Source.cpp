#include "../LinkedLists, Assignment 4.2 V2/Node.h"
#include <iostream>
using namespace std;

template< typename ItemType>
Node<ItemType>* getNodeBefore(const ItemType& anEntry, Node<ItemType>*& headPtr)
{
	Node<ItemType>* curPtr = headPtr;
	Node<ItemType>* prevPtr = nullptr;
	while ((curPtr != nullptr) && (anEntry > curPtr->getItem()))
	{
		prevPtr = curPtr;
		curPtr = curPtr->getNext();
	} // end while 
	return prevPtr;
} // end getNodeBefore 

template <typename ItemType>
void insertSorted(const ItemType& newEntry, Node<ItemType>*& headPtr) {
	Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
	Node<ItemType>* prevPtr = getNodeBefore<int>(newEntry, headPtr);

	if (!headPtr) // Add at beginning 
	{
		newNodePtr->setNext(nullptr);
		headPtr = newNodePtr;
	}
	else // Add after node before 
	{
		Node<ItemType>* aftPtr = prevPtr->getNext();
		newNodePtr->setNext(aftPtr);
		prevPtr->setNext(newNodePtr);
	} // end if 
} // end insertSorted 

int main() {
	const int unsortedList[] = { 5,9,6,9,2 };
	Node<int>* headPtr{ nullptr };

	for (int i{}; i < (sizeof(unsortedList) / sizeof(unsortedList[0])); i++) {
		insertSorted<int>(unsortedList[i], headPtr);
	}

	for (int i{}; i < (sizeof(unsortedList) / sizeof(unsortedList[0])); i++) {
		cout << headPtr->getItem() << ' ';
		headPtr = headPtr->getNext();
	}

	return 0;
}

//Question: Suppose that wordListPtr points to an unsorted list of words.
//Using the operations of the ADT list and the ADT sorted list, create a sorted list of these words.