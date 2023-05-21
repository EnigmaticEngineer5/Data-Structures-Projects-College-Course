#include "DoublyLinkedBag.h"

void addOperations(DoublyLinkedBag<int>& namesList);
void rotateNodes(DoublyLinkedBag<int>& namesList);
void removeOperations(DoublyLinkedBag<int>& namesList);

int main()
{
	DoublyLinkedBag<int> namesList{};
	namesList.addToBeginning(1);
	namesList.addToBeginning(2);
	namesList.addToBeginning(3);
	namesList.addToBeginning(4);
	namesList.addToBeginning(5);
	namesList.addToBeginning(6);
	namesList.addToBeginning(7);
	cout << "\nSome numbers were added to the list for agilizing testing\n";

	const enum Options {
		addToBeginning = 1,
		removeElement = 2,
		displayListForward = 3,
		displayListBackward = 4,
		RotateNodes = 5,
		exitProgram = 6
	};

	int selectedOption{};
	do {
		cout << "\n\t1) Add element to beginning of list"
			<< "\n\t2) Remove element"
			<< "\n\t3) Display list forward"
			<< "\n\t4) Display list backward"
			<< "\n\t5) Rotate nodes"
			<< "\n\t6) Exit program"
			<< "\nAnswer here --> ";
		cin >> selectedOption;
		while (cin.fail() || selectedOption < 1 || selectedOption > 6) {
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "\nPlease select a valid option --> ";
				cin >> selectedOption;
			}
			else {
				cout << "\nInvalid range, please re-enter --> ";
				cin >> selectedOption;
			}
		}

		switch (selectedOption) {
		case addToBeginning:
			addOperations(namesList);
			namesList.displayForward();
			break;

		case removeElement:
			removeOperations(namesList);
			break;

		case displayListForward:
			namesList.displayForward();
			break;

		case displayListBackward:
			namesList.displayBackwards();
			break;

		case RotateNodes:
			rotateNodes(namesList);
			break;

		default:
			cout << "\nExiting program...";
		}
	} while (selectedOption != exitProgram);

	cout << "\n\n";

	return 0;
}

void removeOperations(DoublyLinkedBag<int>& namesList)
{
	if (namesList.getCurrentSize() > 1) {
		namesList.displayForward();
		cout << "\nWhat element do you want to remove --> ";
		int tmpNum{};
		cin >> tmpNum;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\nPlease enter a valid integer --> ";
			cin >> tmpNum;
		}
		namesList.removeFirstNode(tmpNum);
		namesList.displayForward();
	}
	else if (namesList.getCurrentSize() == 1) {
		namesList.removeFirstNode(int{});
	}
	else {
		cout << "\nThe list is empty...";
	}
}

void rotateNodes(DoublyLinkedBag<int>& namesList)
{
	if (namesList.isEmpty()) {
		cout << "\nThere are no elements to search!";
	}
	else {
		namesList.displayForward();
		cout << "\n\t- Enter element to initiate rotation --> ";
		int tmpInt{};
		cin >> tmpInt;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\nPlease enter a valid integer --> ";
			cin >> tmpInt;
		}

		if (namesList.rotateNodes(tmpInt) != nullptr) {
			cout << "\nElement found...";
		}
		else {
			cout << "\nThe element is not present in the list...\n";
		}
	}
}


void addOperations(DoublyLinkedBag<int>& namesList)
{
	int tmpInt{};
	cout << "\n\t- Enter number --> ";
	cin >> tmpInt;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\nPlease enter a valid integer --> ";
		cin >> tmpInt;
	}

	namesList.addToBeginning(tmpInt);
}