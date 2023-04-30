#pragma once
#include "LinkedList2.h"

class CircularList
{
private:
	LinkedList<int> numsCircularList;

public:
	CircularList();
	CircularList(const LinkedList<int>&);
	CircularList(const CircularList&);
	~CircularList();

	CircularList& setList(const LinkedList<int>&);
	const LinkedList<int> getList() const;
	const CircularList reverseList();

	friend istream& operator >> (istream&, CircularList&);
	friend ostream& operator << (ostream&, const CircularList&);
};