#pragma once

template <class ItemType>
class PriorityQueueInterface
{
protected:
	inline PriorityQueueInterface() {
		cout << "\nPriorityQueueInterface constructor invoked...";
	}

	inline ~PriorityQueueInterface() {
		cout << "\nPriorityQueueInterface destructor invoked..." << endl << endl;
	}

public:
	virtual const bool isEmpty() const = 0;
	virtual const bool add(const ItemType&) = 0;
	virtual const bool remove() = 0;
	virtual const ItemType peek() const = 0;
};