#include "Assignment.h"

Assignment::Assignment(const string sourceDescription, const Date sourceDate) :
	description(sourceDescription), dueDate(sourceDate) {};

Assignment::Assignment(const Assignment& sourceAssignment) :
	description(sourceAssignment.getDescription()), dueDate(sourceAssignment.getDate()) {};

Assignment::~Assignment() { /*cout << "\nAssignment object released...";*/ };

Assignment& Assignment::operator=(const Assignment& sourceAssignment)
{
	if (this != &sourceAssignment)
	{
		setDescription(sourceAssignment.getDescription());
		setDate(sourceAssignment.getDate());
	}

	return *this;
}

Assignment& Assignment::setDescription(const string sourceDescription)
{
	this->description = sourceDescription;
	return *this;
}

Assignment& Assignment::setDate(const Date sourceDate)
{
	this->dueDate = sourceDate;
	return *this;
}

const string Assignment::getDescription() const
{
	return description;
}

const Date Assignment::getDate() const
{
	return dueDate;
}

const bool Assignment::operator==(const Assignment& rightSide) const
{
	return (getDescription() == rightSide.getDescription());
}

const bool Assignment::operator==(const Date& rightSide)
{
	return (getDate() == rightSide);
}

const bool Assignment::operator!=(const Assignment& rightSide) const
{
	return (getDate() != rightSide.getDate());
}

const bool Assignment::operator>(const Assignment& rightSide) const
{
	return (getDate() > rightSide.getDate());
}

const bool Assignment::operator<(const Assignment& rightSide) const
{
	return (getDate() < rightSide.getDate());
}

istream& operator>>(istream& input, Assignment& sourceObj)
{
	cout << "\n\t- Enter the DESCRIPTION of the ASSIGNMENT --> ";
	getline(input >> ws, sourceObj.description);

	cout << "\t- Enter the DATE of the ASSIGNMENT, in FORMAT (MM/DD/YY) --> ";
	return input >> sourceObj.dueDate;
}

ostream& operator<<(ostream& output, const Assignment& sourceObj)
{
	return output
		<< "\n\t- The ASSIGNMENT DESCRIPTION is --> " + sourceObj.getDescription()
		<< "\n\t- The ASSIGNMENT DATE is --> " << sourceObj.getDate() << '\n';
}