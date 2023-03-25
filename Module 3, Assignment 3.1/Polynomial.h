#pragma once

#include "ArrayBag.h"
#include "Term.h"

class Polynomial
{
private:
	ArrayBag<Term> poly;

public:
	Polynomial();
	Polynomial(const ArrayBag<Term>);
	Polynomial(const Polynomial&);
	~Polynomial();

	Polynomial& changeCoefficient(const Term);
	const int getDegree() const;
	const int coefficient(const int) const;
	Polynomial& increaseCoefficient(const int, const int);

	Polynomial& operator + (Polynomial&);
	friend ostream& operator << (ostream&, const Polynomial&);
};