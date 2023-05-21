#include "../ADTSortedLists, Assignment 7.1/LinkedSortedList.h"
#include "../CircularList, Assignment 6.2/LinkedList.h"

int main() {
	LinkedList<char> *wordListPtr = new LinkedList<char>{};
	wordListPtr->insert(1, 'z');
	wordListPtr->insert(1, 'a');
	wordListPtr->insert(2, 'y');
	wordListPtr->insert(3, 'x');
	wordListPtr->insert(4, 'w');
	wordListPtr->insert(5, 'v');
	wordListPtr->insert(6, 'u');
	wordListPtr->insert(7, 'b');
	wordListPtr->insert(7, 't');
	wordListPtr->insert(8, 's');
	wordListPtr->insert(9, 'r');
	wordListPtr->insert(10, 'q');
	wordListPtr->insert(11, 'p');
	wordListPtr->insert(12, 'o');
	wordListPtr->insert(13, 'n');
	wordListPtr->insert(14, 'm');
	wordListPtr->insert(15, 'l');
	wordListPtr->insert(16, 'k');
	wordListPtr->insert(17, 'j');

	cout << "The original list is: \n";
	for (int i{}; i < wordListPtr->getLength(); i++) {
		cout << wordListPtr->getEntry(i + 1) << ' ';
	}
	cout << endl;

	LinkedSortedList<char> sortedList{};
	for (int i{}; i < wordListPtr->getLength(); i++) {
		sortedList.insertSorted(wordListPtr->getEntry(i + 1));
	}

	cout << "\nThe new sorted list is: \n";
	sortedList.display();

	return 0;
}
