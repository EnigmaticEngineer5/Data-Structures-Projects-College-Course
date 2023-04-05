#pragma once

#include "BagInterface.h"

static constexpr const int DEFAULT_CAPACITY{ 20 };

template<class ItemType>
class ArrayBag final : public BagInterface<ItemType> {
private:
	ItemType items[DEFAULT_CAPACITY];
	int itemCount, maxItems;

public:
	ArrayBag();
	ArrayBag(const ArrayBag&);
	~ArrayBag();

	const int getIndexOf(const ItemType&, int) const; //Original method was private
	const int getCurrentSize() const override;
	const bool isEmpty() const override;
	const bool add(const ItemType&) override;
	const bool remove(const ItemType&) override;
	void clear() override;
	const int getFrequencyOf(const ItemType&) const override;
	const bool contains(const ItemType&) const override;
	const std::vector<ItemType> toVector() const override;

	ItemType getItem(const int) const override; //Extra
	void replaceItem(const ItemType, const int) override; //Extra
	const int getDefaultCapacity() const; //Extra

	const int countFrequency(const ItemType&, int) const;
};

template<class ItemType>
inline ArrayBag<ItemType>::ArrayBag() : itemCount(0), maxItems(DEFAULT_CAPACITY), items{} {};

template<class ItemType>
inline ArrayBag<ItemType>::ArrayBag(const ArrayBag& sourceBag)
	: itemCount(sourceBag.getCurrentSize()),
	maxItems(DEFAULT_CAPACITY)
{
	int counter{};
	for (const auto& it : sourceBag.items) {
		this->items[counter++] = it;
	}
}

template<class ItemType>
inline ArrayBag<ItemType>::~ArrayBag() {
	//cout << "\nArray bag data type released...";
}

template<class ItemType>
inline const int ArrayBag<ItemType>::getCurrentSize() const {
	return itemCount;
}

template<class ItemType>
inline const bool ArrayBag<ItemType>::isEmpty() const {
	return (itemCount == 0);
}

template<class ItemType>
inline const bool ArrayBag<ItemType>::add(const ItemType& newEntry) {
	bool hasRoomToAdd{ (itemCount < maxItems) };
	if (hasRoomToAdd) {
		items[itemCount++] = newEntry;
	}
	return hasRoomToAdd;
}

template<class ItemType>
inline const bool ArrayBag<ItemType>::remove(const ItemType& anEntry) {
	int locatedIndex{ getIndexOf(anEntry, 0) };
	bool canRemoveItem{ (!isEmpty() && (locatedIndex > -1)) };
	if (canRemoveItem) {
		itemCount--;
		items[locatedIndex] = items[itemCount];
	}
	return canRemoveItem;
}

template<class ItemType>
inline void ArrayBag<ItemType>::clear() {
	itemCount = 0;
}

template<class ItemType>
inline const int ArrayBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const {
	return countFrequency(anEntry, 0);
}

template<class ItemType>
inline const bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const {
	bool found{ false };
	int curIndex{};
	while (!found && (curIndex < itemCount)) {
		if (anEntry == items[curIndex]) {
			found = true;
		}
		curIndex++;
	}
	return found;
}

template<class ItemType>
inline const std::vector<ItemType> ArrayBag<ItemType>::toVector() const {
	std::vector<ItemType> bagContents;
	for (int i{}; i < itemCount; i++) {
		bagContents.push_back(items[i]);
	}
	return bagContents;
}

template<class ItemType>
inline  ItemType ArrayBag<ItemType>::getItem(const int index) const {
	if (index >= getCurrentSize()) {
		throw exception("Boundaries exceeded...");
	}

	return items[index];
}

template<class ItemType>
inline void ArrayBag<ItemType>::replaceItem(const ItemType sourceReplacement, const int index) {
	items[index] = sourceReplacement;
}

template<class ItemType>
inline const int ArrayBag<ItemType>::getDefaultCapacity() const {
	return DEFAULT_CAPACITY;
}

template<class ItemType>
inline const int ArrayBag<ItemType>::getIndexOf(const ItemType& target, int searchIndex) const {
	int result{ -1 };
	if (searchIndex < itemCount) {
		if (items[searchIndex] == target) {
			result = searchIndex;
		}
		else {
			result = getIndexOf(target, searchIndex + 1);
		}
	}
	return result;
}

template<class ItemType>
inline const int ArrayBag<ItemType>::countFrequency(const ItemType& target,
	int searchIndex) const {
	int frequency{};
	if (searchIndex < itemCount) {
		if (items[searchIndex] == target) {
			frequency = 1 + countFrequency(target, searchIndex + 1);
		}
		else {
			frequency = countFrequency(target, searchIndex + 1);
		}
	}
	return frequency;
}