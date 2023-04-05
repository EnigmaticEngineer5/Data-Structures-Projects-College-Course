#pragma once

#include "Assignment.h"
#include "LinkedBag.h"

class AssignmentList
{
private:
	LinkedBag<Assignment> myAssignments;

public:
	AssignmentList();
	AssignmentList(const LinkedBag<Assignment>);
	~AssignmentList();

	AssignmentList& setList(const LinkedBag<Assignment>);
	AssignmentList& addAssignment();
	AssignmentList& removeAssignment();
	void merge(Assignment*, int, int, int) const;
	void mergeSort(Assignment*, int, int) const;
	
	const LinkedBag<Assignment> getAssignmentList() const;
	void showInDueDateOrder() const;
	void displayEarliestAssignments() const;
	void displayList() const;
	const int getAssignmentCount() const;
};