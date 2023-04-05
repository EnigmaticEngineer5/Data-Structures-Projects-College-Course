#pragma once

template<class ItemType>
class LinkedBagInterface
{
protected:
	inline LinkedBagInterface();
	virtual ~LinkedBagInterface();

public:
	virtual const int getCurrentSize() const = 0;
	virtual const bool isEmpty() const = 0;
	virtual const bool add(const ItemType&) = 0;
	virtual const bool addToBeginning(const ItemType&) = 0;
	virtual const bool remove(const ItemType&) = 0;
	virtual const bool removeFirstNode() = 0;


};

