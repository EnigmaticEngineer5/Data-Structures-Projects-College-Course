#pragma once

#include "../Course Source Code/Chapter09/ArrayList/ArrayList.h"

class IntegerSet
{
private:
	ArrayList<bool> boolList;

public:
	IntegerSet();
	IntegerSet(const ArrayList<bool>);
	IntegerSet(const IntegerSet&);
	IntegerSet(const int[], const size_t);
	~IntegerSet();
	IntegerSet& operator = (const IntegerSet&);

	IntegerSet& setList(const ArrayList<bool>);
	const ArrayList<bool> getBoolList() const;

	void unionOfSets(const IntegerSet&) const;
	void intersectionOfSets(const IntegerSet&) const;
	void differenceBetweenSets(const IntegerSet&) const;
	void symmetricDifference(const IntegerSet&) const;
	const bool operator == (const IntegerSet&) const;

	friend istream& operator >> (istream&, IntegerSet&);
	friend ostream& operator << (ostream&, const IntegerSet&);
};