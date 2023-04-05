#pragma once

#include <iostream>
#include <vector> 

using namespace std;

template <class ItemType>
class BagInterface
{
protected:
	inline  BagInterface() = default;
	inline  ~BagInterface() = default;

public:
	inline virtual const int getCurrentSize() const = 0;
	inline virtual const bool isEmpty() const = 0;
	inline virtual const bool add(const ItemType&) = 0;
	inline virtual const bool remove(const ItemType&) = 0;
	inline virtual void clear() = 0;
	inline virtual const int getFrequencyOf(const ItemType&) const = 0;
	inline virtual const bool contains(const ItemType&) const = 0;
	inline virtual const vector<ItemType> toVector() const = 0;
	inline virtual const ItemType getItem(const int) const = 0;

	inline virtual const bool addToBeginning(const ItemType&) = 0;
	inline virtual const bool removeFirstNode() = 0;
};