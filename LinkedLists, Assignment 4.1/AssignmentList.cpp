#include "AssignmentList.h"

AssignmentList::AssignmentList() : myAssignments() {};

AssignmentList::AssignmentList(LinkedBag<Assignment> sourceLink)
	: myAssignments(sourceLink) {};

AssignmentList::~AssignmentList() { /*cout << "\nAssignmentList released...";*/ };

AssignmentList& AssignmentList::setList(const LinkedBag<Assignment> sourceLink)
{
	this->myAssignments = sourceLink;
	return *this;
}

AssignmentList& AssignmentList::addAssignment()
{
	Assignment temporaryAssignment{};
	cin >> temporaryAssignment;

	this->myAssignments.add(temporaryAssignment);

	return *this;
}

AssignmentList& AssignmentList::removeAssignment()
{
	cout << "\n- Enter the ASSIGNMENT DESCRIPTION to remove --> ";
	string searchByDescription{};
	getline(cin >> ws, searchByDescription);

	if (this->myAssignments.remove(Assignment{ searchByDescription }))
	{
		cout << "\nAssignment removed successfully...\n";
	}
	else
	{
		cout << "\nUnable to remove assignment, not found..."
			<< "\nLet's try again!";
		removeAssignment();
	}

	return *this;
}

void AssignmentList::showInDueDateOrder()
{
	vector<Assignment> listDownloaded{ myAssignments.toVector() };
	sort(listDownloaded.begin(), listDownloaded.end());
	for (const auto& assignment : listDownloaded)
	{
		cout << assignment;
	}
}

const LinkedBag<Assignment> AssignmentList::getAssignmentList() const
{
	return myAssignments;
}

void AssignmentList::displayEarliestAssignments() const
{
	const vector<Assignment> listDownloaded{ myAssignments.toVector() };
	Assignment closestDeadline{ listDownloaded.at(0) };

	for (const auto& assignment : listDownloaded)
	{
		if (closestDeadline > assignment)
		{
			closestDeadline = assignment;
		}
	}
	
	cout << "\nNearest assignments are:\n";
	int sameDay{};
	for (int i{}; i < myAssignments.getCurrentSize(); i++)
	{
		if (closestDeadline == listDownloaded.at(i))
		{
			cout << closestDeadline;
			sameDay++;
			continue;
		}
		else if (closestDeadline == listDownloaded.at(i).getDate())
		{
			cout << listDownloaded.at(i);
			sameDay++;
		}
	}

	if (sameDay > 1)
	{
		cout << "\n- You have --> " << sameDay
			<< " tasks on " << closestDeadline.getDate() << ", the same DATE, and closest DEADLINE!\n";
	}
}

void AssignmentList::displayList() const
{
	const vector<Assignment> listDownloaded{ myAssignments.toVector() };

	cout << "\nPrinting assignments...";
	for (const auto& assignment : listDownloaded) 
	{
		cout << assignment;
	}
}

const int AssignmentList::getAssignmentCount() const
{
	return myAssignments.getCurrentSize();
}