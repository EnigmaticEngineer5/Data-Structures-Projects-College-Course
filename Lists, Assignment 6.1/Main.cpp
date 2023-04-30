#include "IntegerSet.h"

int main() {
	IntegerSet set1{}, set2{};

	cout << "\nSet #1";
	cin >> set1;

	cout << "\nSet #2";
	cin >> set2;

	const enum Operations {
		UNION = 1,
		INTERSECTION = 2,
		DIFFERENCE = 3,
		SYMMETRIC_DIFFERENCE = 4,
		EQUAL_TO = 5,
		PRINT = 6,
		EXIT_PROGRAM = 7
	};

	int selection{};
	do {
		cout << "\nSelect what you want to know about your sets:"
			<< "\n\t1) Get Union "
			<< "\n\t2) Get Intersection"
			<< "\n\t3) Get Difference"
			<< "\n\t4) Get Symmetric Difference"
			<< "\n\t5) Compare them"
			<< "\n\t6) Print sets"
			<< "\n\t7) Exit program"
			<< "\nAnswer here --> ";
		cin >> selection;

		while (cin.fail() || selection < 1 || selection > 7) {
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cerr << "\nInvalid entry, please re-enter --> ";
			}
			else {
				cerr << "\nInvalid range of option, please re-enter --> ";
			}
			cin >> selection;
		}

		switch (selection)
		{
		case UNION:
			set1.unionOfSets(set2);
			break;

		case INTERSECTION:
			set1.intersectionOfSets(set2);
			break;

		case DIFFERENCE:
			set1.differenceBetweenSets(set2);
			break;

		case SYMMETRIC_DIFFERENCE:
			set1.symmetricDifference(set2);
			break;

		case EQUAL_TO:
			cout << "\n\t- Is set 1 equal to set 2? --> " << boolalpha << (set1 == set2) << '\n';
			break;

		case PRINT:
			cout << "\nSet #1"
				<< set1;

			cout << "\nSet #2"
				<< set2;
			break;

		default:
			cout << "\nExiting program...";
		}
	} while (selection != EXIT_PROGRAM);

	cout << "\n\n\n";
	return 0;
}