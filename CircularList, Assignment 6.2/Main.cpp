#include "CircularList.h"

int main() {
	CircularList list1;
	cin >> list1;

	list1.reverseList();
	cout << "\n\t --> Reversed list: " << list1 << "\n\n";

	return 0;
}