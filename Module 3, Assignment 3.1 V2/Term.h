
#pragma once

#include <iostream>
using namespace std;

class Term {
private:
	int coef, exp;

public:
	Term(const int sourceCoef = 0, const int sourceExp = 0);
	Term(const Term&);
	~Term() = default;
	Term& operator = (const Term&);

	const int getCoef() const;
	const int getExp() const;

	Term& operator += (const Term&);

	const bool operator == (const Term&) const;
	const bool operator != (const Term&) const;
	const bool operator > (const Term&) const;
	const bool operator >= (const Term&) const;
	const bool operator < (const Term&) const;
	const bool operator <= (const Term&) const;

	friend istream& operator >> (istream&, Term&);
	friend ostream& operator << (ostream&, const Term&);
};