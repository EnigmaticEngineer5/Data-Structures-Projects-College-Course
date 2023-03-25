#include "Polynomial.h"

Polynomial::Polynomial() : poly{} {};
Polynomial::Polynomial(const ArrayBag<Term> sourceBag) : poly{ sourceBag } {};
Polynomial::Polynomial(const Polynomial& sourcePolynomial) : poly{ sourcePolynomial.poly } {};
Polynomial::~Polynomial() {
	cout << "\nPolynomial object released...";
}

Polynomial& Polynomial::changeCoefficient(const Term sourceTerm) {
	this->poly.add(sourceTerm);

	return *this;
}

const int Polynomial::getDegree() const {
	const vector <Term> polynomial{ poly.toVector() };

	int highestDegree{};
	for (const auto& it : polynomial) {
		if (it.getExp() > highestDegree) {
			highestDegree = it.getExp();
		}
	}

	return highestDegree;
}

const int Polynomial::coefficient(const int sourceExponent) const {
	const vector <Term> polynomial{ poly.toVector() };

	for (const auto& it : polynomial) {
		if (it.getExp() == sourceExponent) {
			return it.getCoef();
		}
	}

	cout << "\nThe Coefficient does not exist!";
	return 0;
}

Polynomial& Polynomial::increaseCoefficient(const int sourceCoefficient, const int degree) {
	Term toIncrease{ sourceCoefficient, degree };

	if (this->poly.contains(toIncrease)) {
		vector<Term> polynomial{ this->poly.toVector() };
		polynomial.at(this->poly.getIndexOf(toIncrease, 0)) += toIncrease;

		ArrayBag<Term> temporaryBag{};
		for (const auto& it : polynomial) {
			temporaryBag.add(it);
		}
		this->poly = temporaryBag;
	}
	else {
		cout << "\nThe term you were looking for was not found!";
	}

	return *this;
}


Polynomial& Polynomial::operator+(Polynomial& rightHandSide) {
	vector<Term> left{ this->poly.toVector() }, right{ rightHandSide.poly.toVector() };
	ArrayBag<Term> results{};

	if (left.size() != right.size()) { //Polynomials have different number of expressions...
		if (left.size() > right.size()) { //Left has the most amount of expressions.
			for (const auto& it : right) { //Iterate through right polynomial.
				if (this->poly.contains(it)) { //Search if any term in the left side is similar. 
					const int indexOfLikeTerm{ this->poly.getIndexOf(it, 0) }; //Get the index of that term.
					left.at(indexOfLikeTerm) += it; //Combine the terms.
				}
			}

			for (const auto& it : left) { //Add to a new array bag the elements.
				results.add(it);
			}

		}
		else {
			for (const auto& it : left) { //Repeat process if right polynomial is greater than the left.
				if (rightHandSide.poly.contains(it)) {
					const int indexOfLikeTerm{ rightHandSide.poly.getIndexOf(it, 0) };
					right.at(indexOfLikeTerm) += it;
				}
			}

			for (const auto& it : right) { //Add to new array bag.
				results.add(it);
			}
		}
	}
	else { //Polynomials have the same size.
		for (int i{}; i < left.size(); i++) {
			if (left.at(i) != right.at(i)) { //If elements cannot combine.
				if (this->poly.contains(right.at(i))) { //Search compatible term.
					int indexOfLikeTerm{ this->poly.getIndexOf(i, 0) };
					left.at(indexOfLikeTerm) += right.at(i); //Sum the compatible terms.
				}
			}
			else {
				left.at(i) += right.at(i);
			}
		}
		for (const auto& it : left) {
			if (rightHandSide.poly.contains(it)) {
				rightHandSide.poly.remove(it);
			}
		}

		for (const auto& it : left) {
			results.add(it);
		}
	}

	this->poly = results;
	return *this;
}

ostream& operator<<(ostream& output, const Polynomial& sourcePolynomial) {
	const vector<Term> polynomial{ sourcePolynomial.poly.toVector() };

	for (auto it = polynomial.begin(); it != polynomial.end(); it++) {
		if ((it + 1) != polynomial.end()) {
			output << *it << " + ";
		}
		else {
			output << *it;
		}
	}
}