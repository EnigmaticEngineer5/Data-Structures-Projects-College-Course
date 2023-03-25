#include <iostream>
using namespace std;

template<class ItemType, const int MAX_SIZE>
class ArrayBag final {
private:
	ItemType list[MAX_SIZE];

public:
	ArrayBag(const ItemType[]);
	const int contains(const ItemType, int&, int currentIndex = 0) const;
	void displayBag() const;
};

template<class ItemType, const int MAX_SIZE>
ArrayBag<ItemType, MAX_SIZE>::ArrayBag(const ItemType sourceList[]) {
	for (int i{}; i < MAX_SIZE; i++) {
		this->list[i] = sourceList[i];
	}
}

template<class ItemType, const int MAX_SIZE>
const int ArrayBag<ItemType, MAX_SIZE>::contains(const ItemType target, int& firstEncounter, int currentIndex) const {
	if (currentIndex < MAX_SIZE) {
		if (list[currentIndex] == target) {
			if (firstEncounter == 0) {
				firstEncounter = currentIndex;
			}

			return contains(target, firstEncounter, ++currentIndex) + 1;
		}
		else {
			return contains(target, firstEncounter, ++currentIndex);
		}
	}

	return 0;
}

template<class ItemType, const int MAX_SIZE>
void ArrayBag<ItemType, MAX_SIZE>::displayBag() const {
	for (const auto& it : this->list) {
		cout << it << '\n';
	}
}

int main() {
	const string names[]{
		"Carlos",
		"Roberto",
		"Roberto",
		"Roberto"
	};

	ArrayBag<string, 4> namesList{ names };
	namesList.displayBag();

	int firstEncounter{};
	cout << "\n\t- The frequency of the elements found is --> " << namesList.contains("Roberto", firstEncounter)
		<< "\n\t- The position of the first occurrence of the name in the array is --> " << firstEncounter << '\n';

	return 0;
}