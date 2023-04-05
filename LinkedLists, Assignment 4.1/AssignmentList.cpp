#include "AssignmentList.h"

AssignmentList::AssignmentList() : myAssignments() {};
AssignmentList::AssignmentList(const LinkedBag<Assignment> sourceLink)
	: myAssignments(sourceLink) {};
AssignmentList::~AssignmentList() { /*cout << "\nAssignmentList released...";*/ };

AssignmentList& AssignmentList::setList(const LinkedBag<Assignment> sourceLink)
{
	this->myAssignments = sourceLink;
	return *this;
}

AssignmentList& AssignmentList::addAssignment()
{
	cout << "\nAssignment #" << (getAssignmentList().getCurrentSize() + 1);
	Assignment temporaryAssignment{};
	cin >> temporaryAssignment;

	this->myAssignments.add(temporaryAssignment);

	return *this;
}

AssignmentList& AssignmentList::removeAssignment()
{
	if (!getAssignmentList().isEmpty() && getAssignmentList().getCurrentSize() > 1)
	{
		cout << "\n- Enter the ASSIGNMENT DESCRIPTION to remove/mark as completed --> ";
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
	}
	else if (getAssignmentList().getCurrentSize() == 1)
	{
		myAssignments.clear();
		cout << "\nOnly assignment removed!";
	}
	else {
		cout << "\nThere are no assignments to remove in the list!";
	}


	return *this;
}

void AssignmentList::merge(Assignment* theArray, int first, int mid, int last) const
{
	Assignment* tmpArray{ new Assignment[(last + 1)] };
	int first1{ first },
		last1{ mid },
		first2{ (mid + 1) },
		last2{ last },
		index{ first1 };

	while ((first1 <= last1) && (first2 <= last2)) {
		if (theArray[first1] <= theArray[first2]) {
			tmpArray[index] = theArray[first1];
			first1++;
		}
		else {
			tmpArray[index] = theArray[first2];
			first2++;
		}
		index++;
	}

	while (first1 <= last1) {
		tmpArray[index] = theArray[first1];
		first1++;
		index++;
	}

	while (first2 <= last2) {
		tmpArray[index] = theArray[first2];
		first2++;
		index++;
	}

	for (index = first; index <= last; index++) {
		theArray[index] = tmpArray[index];
	}

	delete[] tmpArray;
	tmpArray = nullptr;
}

void AssignmentList::mergeSort(Assignment* theArray, int first, int last) const
{
	if (first < last) {
		int mid{ (last + first) / 2 };
		mergeSort(theArray, first, mid);
		mergeSort(theArray, mid + 1, last);
		merge(theArray, first, mid, last);
	}
}

void AssignmentList::showInDueDateOrder() const
{
	if (!getAssignmentList().isEmpty())
	{
		const int listSize{ getAssignmentList().getCurrentSize() };
		Assignment* listDownloaded{ new Assignment[listSize] };

		for (int i{}; i < listSize; i++)
		{
			listDownloaded[i] = getAssignmentList().getItem(i);
		}

		mergeSort(listDownloaded, 0, (listSize - 1));
		for (int i{}; i < listSize; i++)
		{
			cout << "\nAssignment #" << (i + 1)
				<< listDownloaded[i];
		}

		delete[] listDownloaded;
		listDownloaded = nullptr;
	}
	else
	{
		cout << "\nThere are no assignments to print!";
	}
}

const LinkedBag<Assignment> AssignmentList::getAssignmentList() const
{
	return myAssignments;
}

void AssignmentList::displayEarliestAssignments() const
{
	if (!getAssignmentList().isEmpty())
	{
		const int listSize{ getAssignmentList().getCurrentSize() };
		Assignment closestDeadline{ getAssignmentList().getItem(0) };

		for (int i{}; i < listSize; i++)
		{
			if (closestDeadline > getAssignmentList().getItem(i)) {
				closestDeadline = getAssignmentList().getItem(i);
			}
		}

		cout << "\nNearest assignments are:\n";
		int assignmentsOnSameDay{};
		for (int i{}; i < listSize; i++)
		{
			if (closestDeadline == getAssignmentList().getItem(i))
			{
				cout << "Assignment on same date #" << ++assignmentsOnSameDay
					<< closestDeadline;
			}
			else if (closestDeadline == getAssignmentList().getItem(i).getDate())
			{
				cout << "Assignment on same date #" << ++assignmentsOnSameDay
					<< getAssignmentList().getItem(i);
			}
		}

		if (assignmentsOnSameDay > 1)
		{
			cout << "\n- You have --> " << assignmentsOnSameDay
				<< " tasks on " << closestDeadline.getDate() << ", the same DATE, and closest DEADLINE!\n";
		}
	}
	else
	{
		cout << "\nThere are no assignments inside the list...";
	}
}

void AssignmentList::displayList() const
{
	if (!getAssignmentList().isEmpty())
	{
		cout << "\nPrinting assignments...";
		for (int i{}; i < getAssignmentList().getCurrentSize(); i++) {
			cout << "\nAssignment #" << (i + 1)
				<< getAssignmentList().getItem(i);
		}
	}
	else
	{
		cout << "\nThere are no assignments to print!";
	}
}

const int AssignmentList::getAssignmentCount() const
{
	return getAssignmentList().getCurrentSize();
}