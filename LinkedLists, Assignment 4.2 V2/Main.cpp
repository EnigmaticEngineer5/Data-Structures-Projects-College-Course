#include "DoublyLinkedBag.h"
#include "Main.h"

#include <string>

int main()
{
	DoublyLinkedBag<string> namesList{};

	const enum Options
	{
		addToBeginning = 1,
		removeBeginning = 2,
		displayListForward = 3,
		displayListBackward = 4,
		rotateNodesBothDirections = 5,
		exitProgram = 6
	};

	int selectedOption{};
	do
	{
		cout << "\n\n\t1) Add element to beginning of list"
			<< "\n\t2) Remove element from beginning"
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

		case removeBeginning:
			namesList.removeFirstNode();
			namesList.displayForward();
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