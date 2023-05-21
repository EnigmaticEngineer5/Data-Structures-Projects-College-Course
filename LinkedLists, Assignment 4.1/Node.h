#pragma once

template< class ItemType>
class Node
{
private:
	ItemType item;
	Node<ItemType>* next;

public:
	Node();
	explicit Node(const ItemType&);
	Node(const ItemType&, Node<ItemType>*);
	~Node();

	void setItem(const ItemType&);
	void setNext(Node<ItemType>*);
	const ItemType getItem() const;
	Node<ItemType>* getNext() const;
};

template< class ItemType>
inline Node<ItemType>::Node() : next{}, item{} {};

template< class ItemType>
inline Node<ItemType>::Node(const ItemType& anItem) : item(anItem), next(nullptr) {};

template< class ItemType>
inline Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* nextNodePtr) :
	item(anItem), next(nextNodePtr) {};

template<class ItemType>
inline Node<ItemType>::~Node()
{
	if (next != nullptr) {
		delete next;
		next = nullptr;
	}
}

template< class ItemType>
inline void Node<ItemType>::setItem(const ItemType& anItem)
{
	item = anItem;
}

template< class ItemType>
inline void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr)
{
	next = nextNodePtr;
}

template< class ItemType>
inline const ItemType Node<ItemType>::getItem() const
{
	return item;
}

template< class ItemType>
inline Node<ItemType>* Node<ItemType>::getNext() const
{
	return next;
}