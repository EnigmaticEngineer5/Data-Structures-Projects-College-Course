#include "Polynomial.h"
#include "Main.h"

int main() {
	ArrayBag<Polynomial> polynomials{};
	cout << "Welcome, this is a program that can perform sum operations of Polynomials"
		<< "\n\t- How many polynomials would you like to store? (count > 2 & < " << polynomials.getDefaultCapacity() << ") --> ";
	int polyCount{};
	cin >> polyCount;
	while (cin.fail() || polyCount < 2 || polyCount > polynomials.getDefaultCapacity()) {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\nPlease, re-enter a valid integer Polynomial Count --> ";
			cin >> polyCount;
		}
		else {
			cout << "\nRe-enter an integer in a valid range --> ";
			cin >> polyCount;
		}
	}

	for (int i{}; i < polyCount; i++) {
		cout << "\nPolynomial #" << (i + 1);
		Polynomial tmpPolynomial{};
		cin >> tmpPolynomial;
		polynomials.add(tmpPolynomial);
	}

	const enum Operations {
		printPolynomials = 1,
		sumPolynomials = 2,
		getDegree = 3,
		displayCoefficient = 4,
		changeCoefficient = 5,
		enterNewPolynomial = 6,
		removePolynomial = 7,
		sortPolynomials = 8,
		getTermQuantity = 9,
		getPolynomialQuantity = 10,
		removeTermFromApolynomial = 11,
		increaseCoefficient = 12,
		getHighestPowerCoefficient = 13,
		getHighestDegreeOfAllPolynomials = 14,
		exitProgram = 15
	};

	bool polynomialsAreSorted{ false };
	int selection{};
	do {
		cout << "\n\nSelect your preferred operation:"
			<< "\n\t1) Print the polynomials"
			<< "\n\t2) Sum two polynomials"
			<< "\n\t3) Get degree of a polynomial"
			<< "\n\t4) Display coefficient given the power of a polynomial"
			<< "\n\t5) Change coefficient/add term to a polynomial"
			<< "\n\t6) Enter new polynomial"
			<< "\n\t7) Remove a polynomial"
			<< "\n\t8) Sort polynomials by degrees"
			<< "\n\t9) Get quantity of terms"
			<< "\n\t10) Get quantity of polynomials"
			<< "\n\t11) Remove a term from a polynomial"
			<< "\n\t12) Increase coefficient"
			<< "\n\t13) Get highest power coefficient"
			<< "\n\t14) Get highest degree of all the polynomials"
			<< "\n\t15) Exit program"
			<< "\nChoose --> ";
		cin >> selection;
		while (cin.fail() || selection < 1 || selection > 15) {
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "\nPlease re-enter a valid integer --> ";
				cin >> selection;
			}
			else {
				cout << "\nInvalid option, please re-enter a valid one --> ";
				cin >> selection;
			}
		}

		switch (selection) {
		case printPolynomials:
			printOperations(polynomials);
			break;

		case sumPolynomials:
			sortOperations(polynomialsAreSorted, polynomials);
			sumOperations(polynomials);
			break;

		case getDegree:
			getDegreeOperation(polynomials);
			break;

		case displayCoefficient:
			displayCoefficientOperations(polynomials);
			break;

		case changeCoefficient:
			changeCoefficientOperations(polynomials);
			break;

		case enterNewPolynomial:
			newPolynomialOperations(polynomials);
			break;

		case removePolynomial:
			removeOperations(polynomials);
			break;

		case sortPolynomials:
			sortOperations(polynomialsAreSorted, polynomials);
			break;

		case getTermQuantity:
			getTermQuantityOperations(polynomials);
			break;

		case getPolynomialQuantity:
			getPolynomialQuantityOperations(polynomials);
			break;

		case removeTermFromApolynomial:
			removeTermOperations(polynomials);
			break;

		case increaseCoefficient:
			increaseCoefficientOperations(polynomials);
			break;

		case getHighestPowerCoefficient:
			highestPowerCoefficientOperations(polynomials);
			break;

		case getHighestDegreeOfAllPolynomials:
			allPolynomialsDegreeOperations(polynomials);
			break;

		default:
			cout << "\nExiting program...";
		}

	} while (selection != exitProgram);

	cout << "\n\n";
	return 0;
}

void allPolynomialsDegreeOperations(ArrayBag<Polynomial>& polynomials) {
	int highestDegreeOfAll{};
	for (int i{}; i < polynomials.getCurrentSize(); i++) {
		const int tmpDegree{ polynomials.getItem(i).getDegree() };
		if (tmpDegree > highestDegreeOfAll) {
			highestDegreeOfAll = tmpDegree;
		}
	}

	cout << "\n\t- The highest degree between all the polynomials is --> " << highestDegreeOfAll;
}

void removeTermOperations(ArrayBag<Polynomial>& polynomials) {
	printOperations(polynomials);
	int polyTarget{};
	getPolynomialIndex(polyTarget, polynomials);
	cout << "\n\t- Before removing term --> " << polynomials.getItem(--polyTarget);
	polynomials.replaceItem(polynomials.getItem(polyTarget).removeTerm().sortPolynomial(), polyTarget);
	cout << "\n\t- After removing term --> " << polynomials.getItem(polyTarget);
}

void highestPowerCoefficientOperations(ArrayBag<Polynomial>& polynomials) {
	printOperations(polynomials);
	int polyTarget{};
	getPolynomialIndex(polyTarget, polynomials);
	cout << "\n\t- The coefficient of the highest power is --> " << polynomials.getItem(--polyTarget).getHighestPowerCoefficient();
}

void increaseCoefficientOperations(ArrayBag<Polynomial>& polynomials) {
	printOperations(polynomials);
	int polyTarget{};
	getPolynomialIndex(polyTarget, polynomials);
	cout << "\n\t- You chose the polynomial --> " << polynomials.getItem(--polyTarget)
		<< "\n\t- Enter the exponent to locate the term --> ";
	int tmpExp{};
	cin >> tmpExp;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\nInvalid input, please re-enter --> ";
		cin >> tmpExp;
	}

	cout << "\n\t- Enter by how much you would like to increase the coefficient --> ";
	int tmpCoef{};
	cin >> tmpCoef;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\nInvalid input, please re-enter --> ";
		cin >> tmpCoef;
	}

	polynomials.replaceItem(polynomials.getItem(polyTarget).increaseCoefficient(tmpCoef, tmpExp), polyTarget);
	cout << "\n\t- The polynomial now, with the selected coefficient increased is --> " << polynomials.getItem(polyTarget);
}

void getPolynomialQuantityOperations(ArrayBag<Polynomial>& polynomials) {
	cout << "\n\t- There are --> " << polynomials.getCurrentSize() << " polynomials!";
}

void getTermQuantityOperations(ArrayBag<Polynomial>& polynomials) {
	printOperations(polynomials);
	int polyTarget{};
	getPolynomialIndex(polyTarget, polynomials);
	cout << "\n\t- This polynomial has --> " << polynomials.getItem(--polyTarget).getPoly().getCurrentSize() << " terms!";
}

void newPolynomialOperations(ArrayBag<Polynomial>& polynomials) {
	if (polynomials.getCurrentSize() == polynomials.getDefaultCapacity()) {
		cout << "\nArray bag is full!";
	}
	else {
		Polynomial tmpPolynomial{};
		cin >> tmpPolynomial;
		polynomials.add(tmpPolynomial.sortPolynomial());
	}
}

void removeOperations(ArrayBag<Polynomial>& polynomials) {
	if (polynomials.getCurrentSize() > 2) {
		printOperations(polynomials);
		int polyTarget{};
		getPolynomialIndex(polyTarget, polynomials);
		const bool removed{ (polynomials.remove(polynomials.getItem(--polyTarget))) };
		if (removed) {
			cout << "\nPolynomial removed successfully!";
			printOperations(polynomials);
		}
		else {
			cout << "\nUnable to remove it/not found!";
		}
	}
	else {
		cout << "\nThere needs to be a minimum of two polynomials in the list!";
	}
}

void changeCoefficientOperations(ArrayBag<Polynomial>& polynomials) {
	printOperations(polynomials);
	int polyTarget{};
	getPolynomialIndex(polyTarget, polynomials);
	polynomials.replaceItem(polynomials.getItem(--polyTarget).changeCoefficient().sortPolynomial(), polyTarget);
	cout << "Term added...";
	printOperations(polynomials);
}

void displayCoefficientOperations(ArrayBag<Polynomial>& polynomials) {
	printOperations(polynomials);
	int polyTarget{};
	getPolynomialIndex(polyTarget, polynomials);
	cout << "\n\t- The polynomial is --> " << polynomials.getItem(--polyTarget)
		<< "\n\t- Enter the exponent with which you want to find the coefficient --> ";
	int tmpExp{};
	cin >> tmpExp;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\nInvalid input, please re-enter --> ";
		cin >> tmpExp;
	}

	cout << "\n\t- The coefficient is --> " << polynomials.getItem(polyTarget).coefficient(tmpExp);
}

void sortOperations(bool& polynomialsAreSorted, ArrayBag<Polynomial>& polynomials) {
	if (!polynomialsAreSorted) {
		printOperations(polynomials);
		for (int i{}; i < polynomials.getCurrentSize(); i++) {
			polynomials.replaceItem(polynomials.getItem(i).sortPolynomial(), i);
		}
		polynomialsAreSorted = true;
		cout << "\n\nSorted polynomials are:";
		printOperations(polynomials);
	}
	else {
		cout << "\nThe polynomials are sorted already...";
	}
}

void printOperations(const ArrayBag<Polynomial>& polynomials) {
	for (int i{}; i < polynomials.getCurrentSize(); i++) {
		cout << "\nPolynomial #" << (i + 1)
			<< "\n\tIs --> " << polynomials.getItem(i) << '\n';
	}
}

void sumOperations(ArrayBag<Polynomial>& polynomials) {
	Polynomial tmpPolynomial{};
	if (polynomials.getCurrentSize() > 2) {
		cout << "\n\t- Which polynomials do you want to sum? --> ";
		int sum1{}, sum2{};
		cin >> sum1 >> sum2;

		while (cin.fail() || sum1 < 1 || sum1 > polynomials.getCurrentSize() ||
			sum2 < 1 || sum2 > polynomials.getCurrentSize()) {
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "\nPlease re-enter valid polynomial positions --> ";
				cin >> sum1 >> sum2;
			}
			else {
				cout << "\nPlease re-enter polynomials in a valid range --> ";
				cin >> sum1 >> sum2;
			}
		}
		tmpPolynomial = (polynomials.getItem(--sum1) + polynomials.getItem(--sum2));
	}
	else {
		tmpPolynomial = (polynomials.getItem(0) + polynomials.getItem(1));
	}

	cout << "\n\t- The sum of the polynomials is --> " << tmpPolynomial << '\n';

	if (polynomials.getCurrentSize() < 6) {
		cout << "\nThere is space available to store the result of the sum,"
			<< "\nWould you like to?"
			<< "\n\t1) Yes"
			<< "\n\t2) No"
			<< "\nAnswer --> ";
		int answer{};
		cin >> answer;
		while (cin.fail() || answer < 1 || answer > 2) {
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "\nPlease re-enter a valid integer response --> ";
				cin >> answer;
			}
			else {
				cout << "Please re-enter a valid option --> ";
				cin >> answer;
			}
		}

		if (answer == 1) {
			polynomials.add(tmpPolynomial);
			cout << "\nItem saved...";
		}
		else {
			cout << "\nOk, it will not be saved...";
		}
	}
}

void getDegreeOperation(const ArrayBag<Polynomial>& polynomials) {
	printOperations(polynomials);
	int polyTarget{};
	getPolynomialIndex(polyTarget, polynomials);
	cout << "\t- The degree of the polynomial is --> " << polynomials.getItem(--polyTarget).getDegree();
}

void getPolynomialIndex(int& polyTarget, const ArrayBag<Polynomial>& polynomials)
{
	cout << "\n\t- Which Polynomial? --> ";
	cin >> polyTarget;
	while (cin.fail() || polyTarget < 1 ||
		polyTarget > polynomials.getCurrentSize()) {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\nPlease re-enter a valid integer target --> ";
			cin >> polyTarget;
		}
		else {
			cout << "\nInvalid range! Please re-enter --> ";
			cin >> polyTarget;
		}
	}
}