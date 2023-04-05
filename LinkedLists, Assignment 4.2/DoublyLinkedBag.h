#pragma once

#include "BagInterface.h"
#include "Node.h"

template<class ItemType>
class DoublyLinkedBag : public BagInterface<ItemType>
{
private:
	Node <ItemType>* headPtr;
	Node <ItemType>* tailPtr;
	int itemCount;
	int currentNode;

	Node<ItemType>* rightRotate(const ItemType&, Node<ItemType>*) const;
	Node<ItemType>* leftRotate(const ItemType&, Node<ItemType>*) const;

public:
	DoublyLinkedBag();
	DoublyLinkedBag(const DoublyLinkedBag<ItemType>&);
	virtual ~DoublyLinkedBag();

	const int getCurrentSize() const override;
	const bool isEmpty() const override;
	const bool add(const ItemType&) override;
	const bool remove(const ItemType&) override; //Needs work
	void clear() override;
	const int getFrequencyOf(const ItemType&) const override;
	const bool contains(const ItemType&) const override;

	const vector<ItemType> toVector() const override; //Left to right
	const vector<ItemType> toVectorRightToLeft() const;
	void fillVector(vector<ItemType>&, Node<ItemType>*) const; //Left to right
	void fillVectorRightToLeft(vector<ItemType>&, Node<ItemType>*) const;

	const ItemType getRightItem();
	const ItemType getLeftItem();
	const ItemType getCurrentItem() const;
	const int getNodePosition() const;
	
	const ItemType getItem(const int) const override;

	const bool addToBeginning(const ItemType&) override;
	const bool removeFirstNode() override;
	const ItemType searchItemRightRotating(const ItemType&, Node<ItemType>* = nullptr) const;
	const ItemType searchItemLeftRotating(const ItemType&, Node<ItemType>* = nullptr) const;
};

template<class ItemType>
inline Node<ItemType>* DoublyLinkedBag<ItemType>::rightRotate(const ItemType& target, Node<ItemType>* curPtr) const
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
			result = rightRotate(target, curPtr->getNext());
		}
	}
	return result;
}

template<class ItemType>
inline Node<ItemType>* DoublyLinkedBag<ItemType>::leftRotate(const ItemType& target, Node<ItemType>* curPtr) const
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
			result = leftRotate(target, curPtr->getPrev());
		}
	}
	return result;
}

template<class ItemType>
inline DoublyLinkedBag<ItemType>::DoublyLinkedBag()
	: headPtr(nullptr), tailPtr(nullptr), itemCount{}, currentNode{} {};

template<class ItemType>
inline DoublyLinkedBag<ItemType>::DoublyLinkedBag(const DoublyLinkedBag<ItemType>& sourceBag)
	: itemCount{}, headPtr(sourceBag.headPtr), tailPtr(sourceBag.tailPtr), currentNode{}
{
	Node<ItemType>* origChainPtr{ sourceBag.headPtr };  // Points to nodes in original chain
	while (origChainPtr != nullptr)
	{
		add(origChainPtr->getItem());
		origChainPtr = origChainPtr->getNext();
	}
}

template<class ItemType>
inline DoublyLinkedBag<ItemType>::~DoublyLinkedBag()
{
	clear();
	//cout << "\nDoublyLinkedBag released...";
}

template<class ItemType>
inline const int DoublyLinkedBag<ItemType>::getCurrentSize() const
{
	return itemCount;
}

template<class ItemType>
inline const bool DoublyLinkedBag<ItemType>::isEmpty() const
{
	return (itemCount == 0);
}

template<class ItemType>
inline const bool DoublyLinkedBag<ItemType>::add(const ItemType& newEntry)
{
	Node<ItemType>* newNodePtr{ new Node<ItemType>{newEntry} };
	if (itemCount == 0)
	{
		newNodePtr->setNext(nullptr).setPrev(nullptr);
		headPtr = newNodePtr;
		tailPtr = newNodePtr;
	}
	else
	{
		newNodePtr->setNext(nullptr).setPrev(tailPtr);
		tailPtr->setNext(newNodePtr);
	}

	tailPtr = newNodePtr;
	itemCount++;

	return true;
}

template< class ItemType>
inline const bool DoublyLinkedBag<ItemType>::remove(const ItemType& anEntry)
{
	Node<ItemType>* entryNodePtr{ rightRotate(anEntry, headPtr) };
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
inline void DoublyLinkedBag<ItemType>::clear() {
	while (headPtr != nullptr)
	{
		Node<ItemType>* nodeToDeletePtr{ headPtr };
		headPtr = headPtr->getNext();

		nodeToDeletePtr->setNext(nullptr);
		delete nodeToDeletePtr;
	}

	while (tailPtr != nullptr)
	{
		Node<ItemType>* nodeToDeletePtr{ tailPtr };
		tailPtr = tailPtr->getPrev();

		if (tailPtr != nullptr)
		{
			tailPtr->setNext(nullptr);
		}

		nodeToDeletePtr->setPrev(nullptr);
	}

	itemCount = 0;
}

template< class ItemType>
inline const int DoublyLinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
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
inline const bool DoublyLinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
	return (leftRotate(anEntry, headPtr) != nullptr);
}

template< class ItemType>
inline const vector<ItemType> DoublyLinkedBag<ItemType>::toVector() const
{
	vector<ItemType> bagContents{};
	fillVector(bagContents, headPtr);
	return bagContents;
}

template<class ItemType>
inline const vector<ItemType> DoublyLinkedBag<ItemType>::toVectorRightToLeft() const
{
	vector<ItemType> bagContents{};
	fillVectorRightToLeft(bagContents, tailPtr);
	return bagContents;
}

template< class ItemType>
inline void DoublyLinkedBag<ItemType>::fillVector(vector<ItemType>& bagContents, Node<ItemType>* curPtr) const
{
	if (curPtr != nullptr)
	{
		bagContents.push_back(curPtr->getItem());
		fillVector(bagContents, curPtr->getNext());
	}
}

template<class ItemType>
inline void DoublyLinkedBag<ItemType>::fillVectorRightToLeft(vector<ItemType>& bagContents, Node<ItemType>* curPtr) const
{
	if (curPtr != nullptr)
	{
		bagContents.push_back(curPtr->getItem());
		fillVectorRightToLeft(bagContents, curPtr->getPrev());
	}
}

template<class ItemType>
inline const ItemType DoublyLinkedBag<ItemType>::getRightItem()
{
	ItemType tmpItem{};
	if (!isEmpty())
	{
		if (getNodePosition() == 0)
		{
			tmpItem = headPtr->getItem();
			currentNode++;
		}
		else if (getNodePosition() != getCurrentSize())
		{
			int counter{};
			Node<ItemType>* origChain{ headPtr };
			currentNode++;

			while (counter < getNodePosition())
			{
				tmpItem = origChain->getItem();
				origChain = origChain->getNext();
				counter++;
			}

			origChain = nullptr;
		}
		else
		{
			cout << "\nEnd of the list reached!";
		}
	}
	else
	{
		cout << "\nThe list is empty!";
	}
	return tmpItem;
}

template<class ItemType>
inline const ItemType DoublyLinkedBag<ItemType>::getLeftItem()
{
	ItemType tmpItem{};
	if (!isEmpty())
	{
		if (getNodePosition() == getCurrentSize())
		{
			tmpItem = tailPtr->getItem();
			currentNode--;
		}
		else if (getNodePosition() > 1)
		{
			currentNode--;
			int counter{ getCurrentSize() };
			Node<ItemType>* origChain{ tailPtr };

			while (counter > getNodePosition())
			{
				origChain = origChain->getPrev();
				tmpItem = origChain->getItem();
				counter--;
			}

			if (getNodePosition() == 1)
			{
				currentNode = 0;
			}
			origChain = nullptr;
		}
		else
		{
			currentNode = 0;
			cout << "\nBeginning of list reached!";
		}

	}
	else
	{
		cout << "\nThe list is empty!";
	}

	/*ItemType target{};
	if (!isEmpty())
	{
		currentNode--;
		Node<ItemType>* traverser{ tailPtr };
		int counter{ getNodePosition() };
		while (counter != getNodePosition())
		{
			traverser = tailPtr->getNext();

			if (getNodePosition() == --currentNode)
			{
				target = traverser;
			}
		}
	}*/

	return tmpItem;
}

template<class ItemType>
inline const ItemType DoublyLinkedBag<ItemType>::getCurrentItem() const
{
	ItemType tmpItem{};
	if (!isEmpty())
	{
		int counter{};
		Node<ItemType>* origChain{ headPtr };
		while (counter < getNodePosition())
		{
			if (counter == getNodePosition())
			{
				tmpItem = origChain->getItem();
			}
			else
			{
				origChain = origChain->getNext();
			}
			counter++;
		}

		origChain = nullptr;
	}
	else
	{
		cout << "\nThe list is empty!";
	}
	return tmpItem;
}

template<class ItemType>
inline const int DoublyLinkedBag<ItemType>::getNodePosition() const
{
	return currentNode;
}

template<class ItemType>
inline const ItemType DoublyLinkedBag<ItemType>::getItem(const int index) const
{
	ItemType tmpItem{};
	Node<ItemType>* origChain{ headPtr };
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

template<class ItemType>
inline const bool DoublyLinkedBag<ItemType>::addToBeginning(const ItemType& newEntry)
{
	if (isEmpty())
	{
		return add(newEntry);
	}
	else
	{
		Node<ItemType>* newNodePtr{ new Node<ItemType>{newEntry} };
		newNodePtr->setNext(headPtr).setPrev(nullptr);
		headPtr = newNodePtr;
		tailPtr = newNodePtr;
		return true;
	}

	return false;
}

template<class ItemType>
inline const bool DoublyLinkedBag<ItemType>::removeFirstNode()
{
	return false;
}
