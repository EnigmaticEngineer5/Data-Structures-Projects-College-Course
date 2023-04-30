#include "CircularList.h"

int main() {
	CircularList numsList{};
	cin >> numsList;
	cout << "\n\t- The reversed list is --> " << numsList.reverseList() << "\n\n";

	return 0;
}