#pragma once

#include "../LinkedLists, Assignment 4.2 V2/Node.h"

#include <iostream>
using namespace std;

template <class ItemType>
class BagInterface
{
protected:
	inline BagInterface() {
		cout << "\nBag interface constructor invoked...";
	}

	inline ~BagInterface() {
		cout << "\nBagInterface destructor invoked...";
	}

public:
	//Requested methods...
	inline virtual const bool addToBeginning(const ItemType&) = 0;
	inline virtual const bool removeFirstNode(const ItemType&) = 0;
	inline virtual const Node<ItemType>* rightRotate(const ItemType&, Node<ItemType>* = nullptr) const = 0;
	inline virtual const Node<ItemType>* leftRotate(const ItemType&, Node<ItemType>* = nullptr) const = 0;

	//Default methods...
	inline virtual const int getCurrentSize() const = 0;
	inline virtual const bool isEmpty() const = 0;
	inline virtual const bool add(const ItemType&) = 0;
	inline virtual void clear() = 0;
	inline virtual const int getFrequencyOf(const ItemType&) const = 0;
	inline virtual const bool contains(const ItemType&) const = 0;
};