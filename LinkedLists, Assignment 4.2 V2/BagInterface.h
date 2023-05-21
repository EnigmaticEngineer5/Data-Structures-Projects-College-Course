#pragma once

#include "Node.h"

#include <iostream>
using namespace std;

template <class ItemType>
class BagInterface
{
protected:
	inline BagInterface() = default;
	inline ~BagInterface() = default;

public:
	inline virtual const bool addToBeginning(const ItemType&) = 0;
	inline virtual const bool removeFirstNode(const ItemType&) = 0;
	inline virtual const Node<ItemType>* rightRotate(const ItemType&, Node<ItemType>* = nullptr) = 0;
	inline virtual const Node<ItemType>* leftRotate(const ItemType&, Node<ItemType>* = nullptr) = 0;

	inline virtual const int getCurrentSize() const = 0;
	inline virtual const bool isEmpty() const = 0;
	inline virtual const bool add(const ItemType&) = 0;
	inline virtual void clear() = 0;
	inline virtual const int getFrequencyOf(const ItemType&) const = 0;
	inline virtual const bool contains(const ItemType&) const = 0;
};