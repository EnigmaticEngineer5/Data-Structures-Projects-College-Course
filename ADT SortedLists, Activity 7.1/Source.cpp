#include "../ADTSortedLists, Assignment 7.1/LinkedSortedList.h"

int main() {
	LinkedSortedList<int> orderedList1{};
	LinkedSortedList<int> orderedList2{};

	orderedList1.insertSorted(90);
	orderedList1.insertSorted(80);
	orderedList1.insertSorted(70);
	orderedList1.insertSorted(60);

	orderedList2.insertSorted(50);
	orderedList2.insertSorted(40);
	orderedList2.insertSorted(1230);
	orderedList2.insertSorted(30);
	orderedList2.insertSorted(20);

	cout << "\nOrdered list 1:\n";
	orderedList1.display();

	cout << "\nOrdered list 2:\n";
	orderedList2.display();

	cout << "\n\nMerging ordered list 1 and ordered list 2:\n";
	LinkedSortedList<int> mergedList(orderedList1);
	for (int i{}; i < orderedList2.getLength(); i++) {
		mergedList.insertSorted(orderedList2.getEntry(i + 1));
	}
	mergedList.display();

	return 0;
}
