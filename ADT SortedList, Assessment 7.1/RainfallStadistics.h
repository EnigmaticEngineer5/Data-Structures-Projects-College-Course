#pragma once

#include "RainfallMonth.h"
#include "../ADTSortedLists, Assignment 7.1/LinkedSortedList.h"

class RainfallStadistics
{
private:
	LinkedSortedList<RainfallMonth> rainfallYear;

public:
	RainfallStadistics();
	RainfallStadistics(const LinkedSortedList<RainfallMonth>&);
	RainfallStadistics(const RainfallStadistics&);
	~RainfallStadistics();

	RainfallStadistics& setStadistics(const LinkedSortedList<RainfallMonth>&);
	const LinkedSortedList<RainfallMonth>& getStadistics() const;

	void displayTotal() const;
	void displayAverage() const;
	void displayHighest() const;
	void displayLowest() const;

	friend istream& operator >> (istream&, RainfallStadistics&);
	friend ostream& operator << (ostream&, const RainfallStadistics&);
};