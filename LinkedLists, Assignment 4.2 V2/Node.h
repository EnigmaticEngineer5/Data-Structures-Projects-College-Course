#pragma once

template <class ItemType>
class Node
{
private:
	ItemType item;
	Node<ItemType>* prev;
	Node<ItemType>* next;

public:
	Node();
	explicit Node(const ItemType&);
	Node(const ItemType&, Node<ItemType>*, Node<ItemType>* = nullptr);
	~Node();

	Node<ItemType>& setItem(const ItemType&);
	Node<ItemType>& setPrev(Node<ItemType>*);
	Node<ItemType>& setNext(Node<ItemType>*);

	const ItemType getItem() const;
	Node<ItemType>* getPrev() const;
	Node<ItemType>* getNext() const;
};

template<class ItemType>
inline Node<ItemType>::Node()
	: prev(nullptr), next(nullptr), item{} {};

template<class ItemType>
inline Node<ItemType>::Node(const ItemType& sourceItem)
	: prev(nullptr), next(nullptr), item(sourceItem) {};

template<class ItemType>
inline Node<ItemType>::Node(const ItemType& sourceItem, Node<ItemType>* sourcePrevNode, Node<ItemType>* sourceNextNode)
	: item(sourceItem), prev(sourcePrevNode), next(sourceNextNode) {};

template<class ItemType>
inline Node<ItemType>::~Node()
{
	if (prev != nullptr) {
		prev = nullptr;
	}

	if (next != nullptr) {
		delete next;
		next = nullptr;
	}
}

template<class ItemType>
inline Node<ItemType>& Node<ItemType>::setItem(const ItemType& sourceItem)
{
	this->item = sourceItem;
	return *this;
}

template<class ItemType>
inline Node<ItemType>& Node<ItemType>::setPrev(Node<ItemType>* sourcePrev)
{
	this->prev = sourcePrev;
	return *this;
}

template<class ItemType>
inline Node<ItemType>& Node<ItemType>::setNext(Node<ItemType>* sourceNext)
{
	this->next = sourceNext;
	return *this;
}

template<class ItemType>
inline const ItemType Node<ItemType>::getItem() const
{
	return item;
}

template<class ItemType>
inline Node<ItemType>* Node<ItemType>::getPrev() const
{
	return prev;
}

template<class ItemType>
inline Node<ItemType>* Node<ItemType>::getNext() const
{
	return next;
}