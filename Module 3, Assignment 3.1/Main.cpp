#include "Polynomial.h"

int main() {
	Polynomial poly1{}, poly2{}, poly3{}, poly4{}, poly5{}, poly6{}, poly7{};
	poly1.changeCoefficient(Term{ 5, 4 });
	poly1.changeCoefficient(Term{ 10, 3 });
	poly1.changeCoefficient(Term{ 2, 2 });
	poly1.changeCoefficient(Term{ -7, 1 });
	poly1.changeCoefficient(Term{ -7 });

	poly2.changeCoefficient(Term{ 20, 4 });
	poly2.changeCoefficient(Term{ 8, 3 });
	poly2.changeCoefficient(Term{ 2, 2 });
	poly2.changeCoefficient(Term{ -2, 1 });
	poly2.changeCoefficient(Term{ -10 });

	poly4.changeCoefficient(Term{ 20, 3 });
	poly4.changeCoefficient(Term{ -4, 1 });
	poly4.changeCoefficient(Term{ 15 });

	poly6.changeCoefficient(Term{ 20, 8 });
	poly6.changeCoefficient(Term{ -30, 6 });
	poly6.changeCoefficient(Term{ 3, 4 });
	poly6.changeCoefficient(Term{ 13, 2 });
	poly6.changeCoefficient(Term{ 2 });

	//Showcase of examples:

	cout << "Polynomial 1 --> " << poly1;
	cout << "\nPolynomial 2 --> " << poly2;

	//c. Compute the sum of two polynomials (same amount of terms).
	poly3 = (poly1 + poly2);
	cout << "\n\t- Sum of polynomials one and two --> " << poly3;

	//c. Compute the sum of two polynomials (different sizes).
	cout << "\n\nPolynomial three --> " << poly3;
	cout << "\nPolynomial four --> " << poly4;
	poly5 = (poly3 + poly4);
	cout << "\n\t- Sum of polynomials three and four --> " << poly5;

	//Get the degree of a polynomial.
	cout << "\n\nPolynomial five is --> " << poly5;
	cout << "\n\t- The degree is --> " << poly5.getDegree();

	//a. Display the coefficient of the term that has the highest power
	cout << "\n\nThe coefficient of polynomial one --> " << poly1;
	cout << "\n\t- For degree 3 is --> " << poly1.coefficient(3);

	//a. Display the coefficient of a missing term.
	cout << "\n\nThe coefficient of polynomial three --> " << poly3;
	cout << "\n\t- For degree 7 is --> " << poly3.coefficient(7);

	//Change coefficient/add term.
	cout << "\n\nPolynomial four before adding terms --> " << poly4;
	poly4.changeCoefficient(Term{ 3,2 });
	poly4.changeCoefficient(Term{ 10, 7 });
	cout << "\n\t- Polynomial after adding terms --> " << poly4;

	//Adding polynomials with same size but not all terms are alike,
	//and showing the parts that were not added
	//as the remainder of the right side.
	cout << "\n\nPolynomial four before doing a sum --> " << poly4;
	cout << "\nPolynomial to sum --> " << poly6;
	poly7 = (poly4 + poly6);
	cout << "\n\t- Result of polynomials --> " << poly7;
	cout << "\n\t- Residual of polynomial 6, the one added to polynomial four --> " << poly6;

	//b. Increase the coefficient of the term x^3 by 8.
	cout << "\n\nIncreasing the coefficients of a term, polynomial 7 --> " << poly7;
	poly7.increaseCoefficient(8, 3);
	poly7.increaseCoefficient(50, 7);
	cout << "\n\t- Result --> " << poly7;

	cout << "\n\n\n";
	return 0;
}