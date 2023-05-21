#pragma once

template<class ItemType>
class QueueInterface
{
protected:
	inline QueueInterface() = default;

public:
	virtual const bool isEmpty() const = 0;
	virtual const bool enqueue(const ItemType&) = 0;
	virtual const bool dequeue() = 0;
	virtual const ItemType peekFront() const = 0;

	inline virtual ~QueueInterface() = default;
};