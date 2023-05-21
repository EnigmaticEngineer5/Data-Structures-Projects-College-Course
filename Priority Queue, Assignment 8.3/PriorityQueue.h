#include "PriorityQueueInterface.h"
#include "../ADTSortedLists, Assignment 7.1/LinkedSortedList.h"

template<class ItemType>
class SL_PriorityQueue final : public PriorityQueueInterface<ItemType>
{
private:
	LinkedSortedList<ItemType>* slistPtr;

public:
	SL_PriorityQueue();
	virtual ~SL_PriorityQueue();

	const bool isEmpty() const override;
	const bool add(const ItemType&) override;
	const bool remove() override;

	const ItemType peek() const override;
	void display() const override;
};

template<class ItemType>
inline SL_PriorityQueue<ItemType>::SL_PriorityQueue() : slistPtr(new LinkedSortedList<ItemType>{}) {};

template<class ItemType>
inline SL_PriorityQueue<ItemType>::~SL_PriorityQueue()
{
	if (slistPtr) {
		delete slistPtr;
		slistPtr = nullptr;
	}
}

template<class ItemType>
inline const bool SL_PriorityQueue<ItemType>::isEmpty() const
{
	return slistPtr->isEmpty();
}

template<class ItemType>
const bool SL_PriorityQueue<ItemType>::add(const ItemType& newEntry)
{
	slistPtr->insertSorted(newEntry);
	return true;
}

template<class ItemType>
const bool SL_PriorityQueue<ItemType>::remove()
{
	return slistPtr->remove1(1);
}

template<class ItemType>
inline const ItemType SL_PriorityQueue<ItemType>::peek() const
{
	return slistPtr->getEntry(1);
}

template<class ItemType>
void SL_PriorityQueue<ItemType>::display() const {
	slistPtr->display();
}