#pragma once

#include <iostream>
#include <vector> 

using namespace std;

template <class ItemType>
class BagInterface {
public:
	virtual const int getCurrentSize() const = 0;
	virtual const bool isEmpty() const = 0;
	virtual const bool add(const ItemType&) = 0;
	virtual const bool remove(const ItemType&) = 0;
	virtual void clear() = 0;
	virtual const int getFrequencyOf(const ItemType&) const = 0;
	virtual const bool contains(const ItemType&) const = 0;
	virtual const std::vector<ItemType> toVector() const = 0;

	virtual ItemType getItem(const int) const = 0; //Extra...
	virtual void replaceItem(const ItemType, const int) = 0; //Extra...
};