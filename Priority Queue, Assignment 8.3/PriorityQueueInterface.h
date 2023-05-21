#pragma once

template <class ItemType>
class PriorityQueueInterface
{
protected:
	inline PriorityQueueInterface() = default;

public:
	virtual const bool isEmpty() const = 0;
	virtual const bool add(const ItemType&) = 0;
	virtual const bool remove() = 0;
	virtual const ItemType peek() const = 0;
	virtual void display() const = 0;

	inline ~PriorityQueueInterface() = default;
};