#include "Date.h"

Date::Date(int sourceMonth, int sourceDay, int sourceYear)
	: month(sourceMonth), day(sourceDay), year(sourceYear) {};

Date::Date(const Date& sourceDate)
	: month(sourceDate.getMonth()), day(sourceDate.getDay()), year(sourceDate.getYear()) {};

Date::~Date() { /*cout << "\nDate object released...";*/ };

Date& Date::operator=(const Date& sourceDate)
{
	if (this != &sourceDate)
	{
		setMonth(sourceDate.getMonth()).setDay(sourceDate.getDay()).setYear(sourceDate.getYear());
	}

	return *this;
}

Date& Date::setMonth(const int sourceMonth)
{
	this->month = sourceMonth;
	return *this;
}

Date& Date::setDay(const int sourceDay)
{
	this->day = sourceDay;
	return *this;
}

Date& Date::setYear(const int sourceYear)
{
	this->year = sourceYear;
	return *this;
}

const int Date::getMonth() const
{
	return month;
}

const int Date::getDay() const
{
	return day;
}

const int Date::getYear() const
{
	return year;
}

const bool Date::operator==(const Date& rightSide) const
{
	int daysOfMonth{ 30 }, daysOfYear{ 365 };
	return (((getMonth() * daysOfMonth) + getDay() + (getYear() * daysOfYear))
		== ((rightSide.getMonth() * daysOfMonth) + rightSide.getDay() + (rightSide.getYear() * daysOfYear)));
}

const bool Date::operator!=(const Date& rightSide) const
{
	int daysOfMonth{ 30 }, daysOfYear{ 365 };
	return (((getMonth() * daysOfMonth) + getDay() + (getYear() * daysOfYear))
		!= ((rightSide.getMonth() * daysOfMonth) + rightSide.getDay() + (rightSide.getYear() * daysOfYear)));
}

const bool Date::operator>(const Date& rightSide) const
{
	int daysOfMonth{ 30 }, daysOfYear{ 365 };
	return (((getMonth() * daysOfMonth) + getDay() + (getYear() * daysOfYear))
		> ((rightSide.getMonth() * daysOfMonth) + rightSide.getDay() + (rightSide.getYear() * daysOfYear)));
}

const bool Date::operator<(const Date& rightSide) const
{
	int daysOfMonth{ 30 }, daysOfYear{ 365 };
	return (((getMonth() * daysOfMonth) + getDay() + (getYear() * daysOfYear))
		< ((rightSide.getMonth() * daysOfMonth) + rightSide.getDay() + (rightSide.getYear() * daysOfYear)));
}

const bool Date::operator<=(const Date& rightSide) const
{
	int daysOfMonth{ 30 }, daysOfYear{ 365 };
	return (((getMonth() * daysOfMonth) + getDay() + (getYear() * daysOfYear))
		<= ((rightSide.getMonth() * daysOfMonth) + rightSide.getDay() + (rightSide.getYear() * daysOfYear)));
}

istream& operator>>(istream& input, Date& sourceObj)
{
	input >> sourceObj.month >> sourceObj.day >> sourceObj.year;

	while (input.fail() ||
		sourceObj.getMonth() < 0 || sourceObj.getMonth() > 12 ||
		sourceObj.getDay() < 0 || sourceObj.getDay() > 31 ||
		sourceObj.getYear() < 2023)
	{
		if (input.fail())
		{
			input.clear();
			input.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\nInvalid entry, please make sure all inputs are integer types!"
				<< "\n\t--> ";
			input >> sourceObj.month >> sourceObj.day >> sourceObj.year;
		}
		else {
			cout << "\nPlease enter integers in a valid date format range! --> ";
			input >> sourceObj.month >> sourceObj.day >> sourceObj.year;
		}
	}

	return input;
}

ostream& operator<<(ostream& output, const Date& sourceObj)
{
	return output << '(' << sourceObj.getMonth() << '/' << sourceObj.getDay() << '/' << sourceObj.getYear() << ')';
}