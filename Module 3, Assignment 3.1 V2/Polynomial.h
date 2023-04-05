#pragma once

#include "ArrayBag.h"
#include "Term.h"

class Polynomial {
private:
	ArrayBag<Term> poly;

public:
	Polynomial();
	Polynomial(const ArrayBag<Term>);
	Polynomial(const Polynomial&);
	~Polynomial();
	Polynomial& operator = (const Polynomial&);

	Polynomial& changeCoefficient();
	const int getDegree() const;
	const int coefficient(const int) const;
	Polynomial& increaseCoefficient(const int, const int);
	const ArrayBag<Term> getPoly() const;
	const int getHighestPowerCoefficient() const;
	Polynomial& removeTerm();

	Polynomial& sortPolynomial();
	Polynomial& checkSimilarTerms();
	Polynomial& merge(int, int, int);
	Polynomial& mergeSort(int, int);

	const bool operator == (const Polynomial&) const;
	Polynomial& operator + (const Polynomial&);
	friend ostream& operator << (ostream&, const Polynomial&);
	friend istream& operator >> (istream&, Polynomial&);
};