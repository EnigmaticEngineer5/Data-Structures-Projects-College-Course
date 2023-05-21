#pragma once

#include "../Queue, Assignment 8.1/PrecondViolatedExcep.h"

template<class ItemType>
class SortedListInterface
{
protected:
	inline SortedListInterface() = default;

public:
	virtual void insertSorted(const ItemType&) = 0;
	virtual const bool removeSorted(const ItemType&) = 0;
	virtual const int getPosition(const ItemType&) const = 0;

	virtual const bool isEmpty() const = 0;
	virtual const int getLength() const = 0;
	virtual const bool remove1(const int) = 0;
	virtual const bool remove(const ItemType&) = 0;

	virtual void clear() = 0;
	virtual const ItemType getEntry(const int) const throw(PrecondViolatedExcep) = 0;
	virtual void display() const = 0;

	inline virtual ~SortedListInterface() = default;
};