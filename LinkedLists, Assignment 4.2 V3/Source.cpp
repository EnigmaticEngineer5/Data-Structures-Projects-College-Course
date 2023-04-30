#include "DoublyLinkedBag.h"

#include <string>

void addOperations(DoublyLinkedBag<std::string>& namesList);
void rotateNodes(DoublyLinkedBag<std::string>& namesList);
void removeOperations(DoublyLinkedBag<std::string>& namesList);

int main()
{
	DoublyLinkedBag<string> namesList{};
	namesList.add("Carlos");
	namesList.add("Juan");
	namesList.add("Andrea");
	namesList.add("Hannah");
	namesList.add("Ana");
	namesList.add("Genesis");

	const enum Options
	{
		addToBeginning = 1,
		removeElement = 2,
		displayListForward = 3,
		displayListBackward = 4,
		rotateNodesBothDirections = 5,
		exitProgram = 6
	};

	int selectedOption{};
	do
	{
		cout << "\n\n\t1) Add element to beginning of list"
			<< "\n\t2) Remove element"
			<< "\n\t3) Display list forward"
			<< "\n\t4) Display list backward"
			<< "\n\t5) Rotate nodes"
			<< "\n\t6) Exit program"
			<< "\nAnswer here --> ";
		cin >> selectedOption;
		while (cin.fail() || selectedOption < 1 || selectedOption > 6)
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "\nPlease select a valid option --> ";
				cin >> selectedOption;
			}
			else
			{
				cout << "\nInvalid range, please re-enter --> ";
				cin >> selectedOption;
			}
		}

		switch (selectedOption)
		{
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

		case rotateNodesBothDirections:
			rotateNodes(namesList);
			break;

		default:
			cout << "\nExiting program...";
		}
	} while (selectedOption != exitProgram);

	cout << "\n\n";

	return 0;
}

void removeOperations(DoublyLinkedBag<std::string>& namesList)
{
	if (!namesList.isEmpty()) {
		namesList.displayForward();
		cout << "\n\t- Enter the element to delete --> ";
		string toDelete{};
		getline(cin >> ws, toDelete);
		if (namesList.removeFirstNode(toDelete)) {
			namesList.displayForward();
		}
		else {
			cout << "\nThe element was not found!";
		}
	}
	else {
		cout << "\nNo nodes to delete...";
	}
}

void rotateNodes(DoublyLinkedBag<std::string>& namesList)
{
	if (namesList.isEmpty()) {
		cout << "\nThere are no elements to search!";
	}
	else {
		cout << "\n\t- Enter element to initiate rotation --> ";
		string tmpName{};
		getline(cin >> ws, tmpName);

		if (namesList.rotateNodes(tmpName) != nullptr) {
			cout << "\nElement found...";
		}
		else {
			cout << "\nThe element is not present in the list...";
		}
	}
}

void addOperations(DoublyLinkedBag<std::string>& namesList)
{
	string tmpName{};
	cout << "\n\t- Enter name --> ";
	getline(cin >> ws, tmpName);
	namesList.addToBeginning(tmpName);
}