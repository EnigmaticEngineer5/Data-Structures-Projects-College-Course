#include "Term.h"

Term::Term(const int sourceCoef, const int sourceExp) : coef(sourceCoef), exp(sourceExp) {};
Term::Term(const Term& sourceTerm) : coef(sourceTerm.getCoef()), exp(sourceTerm.getExp()) {};

Term& Term::operator=(const Term& rightSide) {
	this->coef = rightSide.getCoef();
	this->exp = rightSide.getExp();
	return *this;
}

const int Term::getCoef() const {
	return coef;
}

const int Term::getExp() const {
	return exp;
}

Term& Term::operator += (const Term& rightHandTerm) {
	this->coef += rightHandTerm.getCoef();
	this->exp = rightHandTerm.getExp();
	return *this;
}

const bool Term::operator == (const Term& rightHandTerm) const {
	return (getExp() == rightHandTerm.getExp());
}

const bool Term::operator != (const Term& rightHandTerm) const {
	return (getExp() != rightHandTerm.getExp());
}

const bool Term::operator > (const Term& rightTerm) const {
	return (getExp() > rightTerm.getExp());
}

const bool Term::operator >= (const Term& rightTerm) const {
	return (getExp() >= rightTerm.getExp());
}

const bool Term::operator < (const Term& rightTerm) const {
	return (getExp() < rightTerm.getExp());
}

const bool Term::operator <= (const Term& rightTerm) const {
	return (getExp() <= rightTerm.getExp());
}

istream& operator >> (istream& input, Term& sourceTerm) {
	cout << "\n\t- Enter the COEFFICIENT of the TERM --> ";
	input >> sourceTerm.coef;
	while (input.fail()) {
		input.clear();
		input.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\nInvalid entry, please re-enter an integer --> ";
		input >> sourceTerm.coef;
	}

	cout << "\t- Enter the DEGREE of the TERM --> ";
	input >> sourceTerm.exp;
	while (input.fail()) {
		input.clear();
		input.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\nInvalid entry, please re-enter an integer --> ";
		input >> sourceTerm.exp;
	}

	return input;
}

ostream& operator << (ostream& output, const Term& sourceTerm) {
	output << sourceTerm.getCoef();

	if (sourceTerm.getExp() != 0) {
		return output << "x^" << sourceTerm.getExp();
	}

	return output;
}