#pragma once

#include "BagInterface.h" 
#include "Node.h" 

template< class ItemType>
class LinkedBag final : public BagInterface<ItemType>
{
private:
	Node<ItemType>* headPtr;
	int itemCount;

	Node<ItemType>* getPointerTo(const ItemType&, Node<ItemType>*) const;

public:
	LinkedBag();
	LinkedBag(const LinkedBag<ItemType>&);
	virtual ~LinkedBag();

	const int getCurrentSize() const override;
	const bool isEmpty() const override;
	const bool add(const ItemType&) override;
	const bool remove(const ItemType&) override;
	void clear() override;
	const int getFrequencyOf(const ItemType&) const override;
	const bool contains(const ItemType&) const override;

	const ItemType getItem(const int) const override;

	const vector<ItemType> toVector() const override;
	void fillVector(vector<ItemType>&, Node<ItemType>*) const;
};

template< class ItemType>
inline LinkedBag<ItemType>::LinkedBag() : headPtr(nullptr), itemCount(0) {};

template<class ItemType>
LinkedBag<ItemType>::LinkedBag(const LinkedBag<ItemType>& aBag)
	: itemCount(aBag.getCurrentSize())
{
	Node<ItemType>* origChainPtr{ aBag.headPtr };  // Points to nodes in original chain

	if (origChainPtr == nullptr)
	{
		headPtr = nullptr;  
	}
	else
	{
		headPtr = new Node<ItemType>();
		headPtr->setItem(origChainPtr->getItem());

		Node<ItemType>* newChainPtr{ headPtr };      
		origChainPtr = origChainPtr->getNext();   

		while (origChainPtr != nullptr)
		{
			ItemType nextItem{ origChainPtr->getItem() };

			Node<ItemType>* newNodePtr{ new Node<ItemType>(nextItem) };
			newChainPtr->setNext(newNodePtr);

			newChainPtr = newChainPtr->getNext();
			origChainPtr = origChainPtr->getNext();
		} 

		newChainPtr->setNext(nullptr);           
	} 
}

template< class ItemType>
inline LinkedBag<ItemType>::~LinkedBag()
{
	//cout << "\nLinked bag released...";
	clear();
}

template< class ItemType>
inline const int LinkedBag<ItemType>::getCurrentSize() const
{
	return itemCount;
}

template< class ItemType>
inline const bool LinkedBag<ItemType>::isEmpty() const
{
	return itemCount == 0;
}

template< class ItemType>
inline const bool LinkedBag<ItemType>::add(const ItemType& newEntry)
{
	Node<ItemType>* newNodePtr{ new Node<ItemType>() };

	newNodePtr->setItem(newEntry);
	newNodePtr->setNext(headPtr);
	headPtr = newNodePtr;

	itemCount++;

	return true;
}

template< class ItemType>
inline const bool LinkedBag<ItemType>::remove(const ItemType& anEntry)
{
	Node<ItemType>* entryNodePtr{ getPointerTo(anEntry, headPtr) };
	const bool canRemoveItem{ (!isEmpty() && (entryNodePtr != nullptr)) };

	if (canRemoveItem) {
		entryNodePtr->setItem(headPtr->getItem());

		Node<ItemType>* nodeToDeletePtr{ headPtr };
		headPtr = headPtr->getNext();

		nodeToDeletePtr->setNext(nullptr);

		delete nodeToDeletePtr;
		nodeToDeletePtr = nullptr;

		itemCount--;
	}
	return canRemoveItem;
}

template< class ItemType>
inline void LinkedBag<ItemType>::clear() {
	while (headPtr != nullptr)
	{
		Node<ItemType>* nodeToDeletePtr{ headPtr };
		headPtr = headPtr->getNext();

		nodeToDeletePtr->setNext(nullptr);
		delete nodeToDeletePtr;
	}

	itemCount = 0;
}

template< class ItemType>
inline const int LinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
	int frequency{}, counter{};
	Node<ItemType>* curPtr{ headPtr };

	while ((curPtr != nullptr) && (counter < itemCount))
	{
		if (anEntry == curPtr->getItem())
		{
			frequency++;
		}
		counter++;
		curPtr = curPtr->getNext();
	}
	return frequency;
}

template< class ItemType>
inline const bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
	return (getPointerTo(anEntry, headPtr) != nullptr);
}

template<class ItemType>
inline const ItemType LinkedBag<ItemType>::getItem(const int index) const
{
	ItemType tmpItem{};
	Node<ItemType> *origChain{ headPtr };
	int counter{};
	while (counter <= index)
	{
		tmpItem = origChain->getItem();
		if (counter == index)
		{
			origChain = nullptr;
			return tmpItem;
		}
		else
		{
			origChain = origChain->getNext();
		}
		counter++;
	}
}

template< class ItemType>
inline const vector<ItemType> LinkedBag<ItemType>::toVector() const
{
	vector<ItemType> bagContents{};
	fillVector(bagContents, headPtr);
	return bagContents;
}

template< class ItemType>
inline void LinkedBag<ItemType>::fillVector(vector<ItemType>& bagContents, Node<ItemType>* curPtr) const
{
	if (curPtr != nullptr)
	{
		bagContents.push_back(curPtr->getItem());
		fillVector(bagContents, curPtr->getNext());
	}
}

template< class ItemType>
inline Node<ItemType>* LinkedBag<ItemType>::getPointerTo(const ItemType& target,
	Node<ItemType>* curPtr) const
{
	Node<ItemType>* result{ nullptr };
	if (curPtr != nullptr)
	{
		if (target == curPtr->getItem())
		{
			result = curPtr;
		}
		else
		{
			result = getPointerTo(target, curPtr->getNext());
		}
	}
	return result;
}