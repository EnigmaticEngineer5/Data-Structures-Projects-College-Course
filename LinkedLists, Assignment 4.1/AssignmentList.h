#pragma once

#include "Assignment.h"
#include "LinkedBag.h"

#include <algorithm>

class AssignmentList
{
private:
	LinkedBag<Assignment> myAssignments;

public:
	AssignmentList();
	AssignmentList(LinkedBag<Assignment>);
	~AssignmentList();

	AssignmentList& setList(const LinkedBag<Assignment>);
	AssignmentList& addAssignment();
	AssignmentList& removeAssignment();

	void showInDueDateOrder();
	const LinkedBag<Assignment> getAssignmentList() const;
	void displayEarliestAssignments() const;
	void displayList() const;
	const int getAssignmentCount() const;
};