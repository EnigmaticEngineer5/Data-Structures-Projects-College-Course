#include "NiceKid.h"

int main() {
	NiceKid aKidGifts{};
	cin >> aKidGifts;

	int selection{};
	const enum Options {
		checkIfEmpty = 1,
		getLength = 2,
		insertGift = 3,
		removeGift = 4,
		displayList = 5,
		replaceGift = 6,
		exitProgram = 7
	};

	do {
		cout << "\n\nSelect an operation:"
			<< "\n\t1) Check if the gift list is empty"
			<< "\n\t2) Get gift count"
			<< "\n\t3) Add a new gift"
			<< "\n\t4) Remove a gift"
			<< "\n\t5) Display gift list"
			<< "\n\t6) Replace a gift"
			<< "\n\t7) Exit program"
			<< "\nAnswer --> ";
		cin >> selection;
		while (cin.fail() || selection < 1 || selection > 7) {
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "\nInvalid option, please enter an integer number --> ";
				cin >> selection;
			}
			else {
				cout << "\nPlease choose an option between a valid range --> ";
				cin >> selection;
			}
		}

		switch (selection)
		{
		case checkIfEmpty:
			if (aKidGifts.getGiftCount() == 0) {
				cout << "\nThe kid does not have gifts...";
			}
			else {
				cout << "\nThe kid has pending gifts!";
			}
			break;

		case getLength:
			if (aKidGifts.getGiftCount() != 0) {
				cout << "\n\t- The kid has --> " << aKidGifts.getGiftCount() << " pending gifts!";
			}
			else {
				cout << "\nThe kid does not have pending gifts!";
			}
			break;

		case insertGift:
			aKidGifts.addGift();
			cout << aKidGifts;
			break;

		case removeGift:
			aKidGifts.removeGift();
			cout << aKidGifts;
			break;

		case displayList:
			cout << aKidGifts;
			break;

		case replaceGift:
			aKidGifts.replaceGift();
			cout << aKidGifts;
			break;

		default:
			cout << "\nExiting program...";
		}
	} while (selection != exitProgram);

	cout << "\n\n";
	return 0;
}