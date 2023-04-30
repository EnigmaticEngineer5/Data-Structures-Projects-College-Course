#include "Polynomial.h"

void getPolynomialIndex(int&, Polynomial, Polynomial);
void printOperations(Polynomial& poli1, Polynomial& poli2);
void getDegreeOperations(int& target, Polynomial& poli1, Polynomial& poli2);
void displayCoefficientOperations(int& target, Polynomial& poli1, int& tmpExp, Polynomial& poli2);
void changeCoefficientOperations(int& target, Polynomial& poli1, Polynomial& poli2);
void removeTermOperations(int& target, Polynomial& poli1, Polynomial& poli2);
void highestPowerOperations(int& target, Polynomial& poli1, Polynomial& poli2);
void increaseCoefficientOperations(int& target, Polynomial& poli1, int& tmpExp, int& tmpCoef, Polynomial& poli2);
void sumOperations(Polynomial& poli1, Polynomial& poli2, bool& polynomialsSorted);
void sortOperations(bool& polynomialsAreSorted, Polynomial& poli1, Polynomial& poli2);
void getTermQuantityOperations(int& target, Polynomial& poli1, Polynomial& poli2);

int main() {
	Polynomial poli1{}, poli2{};
	cout << "Welcome, this is a program that can perform sum operations of Polynomials";
	cin >> poli1 >> poli2;

	const enum Operations {
		printPolynomials = 1,
		sumPolynomials = 2,
		getDegree = 3,
		displayCoefficient = 4,
		changeCoefficient = 5,
		sortPolynomials = 6,
		getTermQuantity = 7,
		removeTerm = 8,
		increaseCoefficient = 9,
		getHighestPowerCoefficient = 10,
		exitProgram = 11
	};

	bool polynomialsAreSorted{ false };
	int selection{};
	do {
		cout << "\n\nSelect your preferred operation:"
			<< "\n\t1) Print the polynomials"
			<< "\n\t2) Sum the two polynomials"
			<< "\n\t3) Get degree of a polynomial"
			<< "\n\t4) Display coefficient given the power of a polynomial"
			<< "\n\t5) Change coefficient/add term to a polynomial"
			<< "\n\t6) Sort polynomials by degrees"
			<< "\n\t7) Get quantity of terms from a polynomial"
			<< "\n\t8) Remove a term from a polynomial"
			<< "\n\t9) Increase coefficient of a polynomial"
			<< "\n\t10) Get highest power coefficient of a polynomial"
			<< "\n\t11) Exit program"
			<< "\nChoose --> ";
		cin >> selection;
		while (cin.fail() || selection < 1 || selection > 11) {
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

		int target{}, tmpCoef{}, tmpExp{};

		switch (selection) {
		case printPolynomials:
			printOperations(poli1, poli2);
			break;

		case sumPolynomials:
			sumOperations(poli1, poli2, polynomialsAreSorted);
			break;

		case getDegree:
			getDegreeOperations(target, poli1, poli2);
			break;

		case displayCoefficient:
			displayCoefficientOperations(target, poli1, tmpExp, poli2);
			break;

		case changeCoefficient:
			changeCoefficientOperations(target, poli1, poli2);
			break;

		case sortPolynomials:
			sortOperations(polynomialsAreSorted, poli1, poli2);
			break;

		case getTermQuantity:
			getTermQuantityOperations(target, poli1, poli2);
			break;

		case removeTerm:
			removeTermOperations(target, poli1, poli2);
			break;

		case increaseCoefficient:
			increaseCoefficientOperations(target, poli1, tmpExp, tmpCoef, poli2);
			break;

		case getHighestPowerCoefficient:
			highestPowerOperations(target, poli1, poli2);
			break;

		default:
			cout << "\nExiting program...";
		}

	} while (selection != exitProgram);

	cout << "\n\n";
	return 0;
}

void getTermQuantityOperations(int& target, Polynomial& poli1, Polynomial& poli2)
{
	getPolynomialIndex(target, poli1, poli2);
	if (target == 1) {
		cout << "\n\t- The term count is --> " << poli1.getPoly().getCurrentSize();
	}
	else {
		cout << "\n\t- The term count is --> " << poli2.getPoly().getCurrentSize();
	}
}

void sortOperations(bool& polynomialsAreSorted, Polynomial& poli1, Polynomial& poli2)
{
	if (polynomialsAreSorted) {
		cout << "\nPolynomials were sorted already...";
	}
	else {
		cout << "\nSorting polynomials...";
		poli1.sortPolynomial();
		poli2.sortPolynomial();
		polynomialsAreSorted = true;
		printOperations(poli1, poli2);
	}
}

void sumOperations(Polynomial& poli1, Polynomial& poli2, bool& polynomialsSorted)
{
	printOperations(poli1, poli2);
	if (polynomialsSorted) {
		poli1 = (poli1 + poli2);
	}
	else {
		poli1 = (poli1.sortPolynomial() + poli2.sortPolynomial());
		polynomialsSorted = true;
	}
	
	cout << "\n\n\t- The sum is --> " << poli1;
	cout << "\n\nThe sum was stored in the first polynomial...";
	printOperations(poli1, poli2);
}

void increaseCoefficientOperations(int& target, Polynomial& poli1, int& tmpExp, int& tmpCoef, Polynomial& poli2)
{
	getPolynomialIndex(target, poli1, poli2);
	if (target == 1) {
		cout << "\n\t- You chose the polynomial --> " << poli1
			<< "\n\t- Enter the exponent to locate the term --> ";
		cin >> tmpExp;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\nInvalid input, please re-enter --> ";
			cin >> tmpExp;
		}

		cout << "\n\t- Enter by how much you would like to increase the coefficient --> ";
		cin >> tmpCoef;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\nInvalid input, please re-enter --> ";
			cin >> tmpCoef;
		}

		poli1.increaseCoefficient(tmpCoef, tmpExp);
		cout << "\n\t- The polynomial now, with the selected coefficient increased is --> " << poli1;
	}
	else {
		cout << "\n\t- You chose the polynomial --> " << poli2
			<< "\n\t- Enter the exponent to locate the term --> ";
		cin >> tmpExp;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\nInvalid input, please re-enter --> ";
			cin >> tmpExp;
		}

		cout << "\n\t- Enter by how much you would like to increase the coefficient --> ";
		cin >> tmpCoef;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\nInvalid input, please re-enter --> ";
			cin >> tmpCoef;
		}

		poli2.increaseCoefficient(tmpCoef, tmpExp);
		cout << "\n\t- The polynomial now, with the selected coefficient increased is --> " << poli2;
	}
}

void highestPowerOperations(int& target, Polynomial& poli1, Polynomial& poli2)
{
	getPolynomialIndex(target, poli1, poli2);
	if (target == 1) {
		cout << "\n\t- The coefficient of the highest power is --> " << poli1.getHighestPowerCoefficient();
	}
	else {
		cout << "\n\t- The coefficient of the highest power is --> " << poli2.getHighestPowerCoefficient();

	}
}

void removeTermOperations(int& target, Polynomial& poli1, Polynomial& poli2)
{
	getPolynomialIndex(target, poli1, poli2);
	if (target == 1) {
		cout << "\n\t- Before removing term --> " << poli1;
		poli1.removeTerm().sortPolynomial();
		cout << "\n\t- After trying to remove term --> " << poli1;
	}
	else {
		cout << "\n\t- Before removing term --> " << poli2;
		poli2.removeTerm().sortPolynomial();
		cout << "\n\t- After trying to remove term --> " << poli2;
	}
}

void changeCoefficientOperations(int& target, Polynomial& poli1, Polynomial& poli2)
{
	getPolynomialIndex(target, poli1, poli2);
	if (target == 1) {
		poli1.changeCoefficient().sortPolynomial();
		cout << "\nTerm added...\n"
			<< poli1;
	}
	else {
		poli2.changeCoefficient().sortPolynomial();
		cout << "\nTerm added...\n"
			<< poli2;
	}
}

void displayCoefficientOperations(int& target, Polynomial& poli1, int& tmpExp, Polynomial& poli2)
{
	getPolynomialIndex(target, poli1, poli2);
	if (target == 1) {
		cout << "\n\t- The polynomial is --> " << poli1
			<< "\n\t- Enter the exponent with which you want to find the coefficient --> ";
		cin >> tmpExp;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\nInvalid input, please re-enter --> ";
			cin >> tmpExp;
		}

		cout << "\n\t- The coefficient is --> " << poli1.coefficient(tmpExp);
	}
	else {
		cout << "\n\t- The polynomial is --> " << poli2
			<< "\n\t- Enter the exponent with which you want to find the coefficient --> ";
		cin >> tmpExp;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\nInvalid input, please re-enter --> ";
			cin >> tmpExp;
		}

		cout << "\n\t- The coefficient is --> " << poli2.coefficient(tmpExp);
	}
}

void getDegreeOperations(int& target, Polynomial& poli1, Polynomial& poli2)
{
	getPolynomialIndex(target, poli1, poli2);
	if (target == 1) {
		cout << "\n\t- The degree of polynomial 1 is --> " << poli1.getDegree();
	}
	else {
		cout << "\n\t- The degree of polynomial 2 is --> " << poli2.getDegree();
	}
}

void printOperations(Polynomial& poli1, Polynomial& poli2)
{
	cout << "\n\n\t- Polynomial 1 --> " << poli1
		<< "\n\t- Polynomial 2 --> " << poli2;
}

void getPolynomialIndex(int& polyTarget, Polynomial poli1, Polynomial poli2)
{
	printOperations(poli1, poli2);
	cout << "\n\t- Which Polynomial? --> ";
	cin >> polyTarget;
	while (cin.fail() || polyTarget < 1 ||
		polyTarget >2) {
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