#include "DB.h"
#include "Main.h"

int main() {
	DB binaryTreeDatabase{};
	cout << "Welcome to the database!\n";

	const enum MenuOptions {
		ADD = 1,
		REMOVE,
		SEARCH,
		MODIFY,
		DISPLAY,
		DISPLAY_BIRTHDAY_ORDER,
		EXIT,
		NUMBER_OF_PEOPLE,
		ALPHABETICAL_ORDER,
		HEIGHT,
		ROOT,
		PREORDER,
		POSTORDER,
		SIMULATE,
		ERASE
	};

	int userChoice{};
	do {
		cout << "\nWhat would you like to do?\n"
			<< "\t1. Add a person\n"
			<< "\t2. Remove a person\n"
			<< "\t3. Search for a person\n"
			<< "\t4. Modify a person\n"
			<< "\t5. Display a person\n"
			<< "\t6. Display all people in birthday order\n"
			<< "\t7. Exit\n"
			<< "____________________EXTRAS_____________________\n"
			<< "\n\t8. Display the number of people in the database\n"
			<< "\t9. Display the people in the database in alphabetical order\n"
			<< "\t10. Display height of the tree\n"
			<< "\t11. Display root of the tree\n"
			<< "\t12. Preorder traverse\n"
			<< "\t13. Postorder traverse\n"
			<< "\t14. Simulate by providing entries\n"
			<< "\t15. Erase the database\n"
			<< "______________________________________________\n"
			<< "Enter your choice --> ";

		const int MIN_CHOICE{ 1 };
		const int MAX_CHOICE{ 15 };
		do {
			cin >> userChoice;
			validateSelection(userChoice, MIN_CHOICE, MAX_CHOICE);

		} while (userChoice < ADD || userChoice > ERASE);

		switch (userChoice)
		{
		case ADD:
			binaryTreeDatabase.addPerson();
			break;

		case REMOVE:
			binaryTreeDatabase.removePerson();
			break;

		case SEARCH:
			binaryTreeDatabase.searchPerson();
			break;

		case MODIFY:
			binaryTreeDatabase.modifyPerson();
			break;

		case DISPLAY:
			binaryTreeDatabase.displayPerson();
			break;

		case DISPLAY_BIRTHDAY_ORDER:
			binaryTreeDatabase.displayInBirthdayOrder();
			break;

		case NUMBER_OF_PEOPLE:
			cout << "\nThere are " << binaryTreeDatabase.getNumberOfPeople() << " people in the database.\n";
			break;

		case ALPHABETICAL_ORDER:
			binaryTreeDatabase.displayInNameOrder();
			break;

		case HEIGHT:
			cout << "\nThe height of the tree is " << binaryTreeDatabase.getBST().getHeight() << ".\n";
			break;

		case ROOT:
			cout << "\nThe root of the tree is " << binaryTreeDatabase.getBST().getRootData() << ".\n";
			break;

		case PREORDER:
			cout << "\nPreorder traversal:\n";
			binaryTreeDatabase.preorderDisplay();
			break;

		case POSTORDER:
			cout << "\nPostorder traversal:\n";
			binaryTreeDatabase.postorderDisplay();
			break;

		case SIMULATE:
			binaryTreeDatabase.simulate();
			break;

		case ERASE:
			binaryTreeDatabase.eraseDatabase();
			break;
		default:
			cout << "Exiting program...\n";
		}
	} while (userChoice != EXIT);

	return 0;
}

void validateSelection(int userChoice, const int& MIN_CHOICE, const int& MAX_CHOICE)
{
	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid choice. Please enter a valid choice --> ";
	}
	else if (userChoice < MIN_CHOICE || userChoice > MAX_CHOICE) {

		cout << "Invalid choice. Please enter a valid choice --> ";
	}
}
