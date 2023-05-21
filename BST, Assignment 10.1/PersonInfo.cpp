#include "PersonInfo.h"

PersonInfo::PersonInfo() : name(), birhday() {};

PersonInfo::PersonInfo(MyString sourceName, Date sourceBirthday)
	: name(sourceName), birhday(sourceBirthday) {};

PersonInfo::PersonInfo(const PersonInfo& sourcePersonInfo)
	: name(sourcePersonInfo.getName()), birhday(sourcePersonInfo.getBirthday()) {};

PersonInfo::~PersonInfo() {};

PersonInfo& PersonInfo::operator=(const PersonInfo& rightHandSource)
{
	this->name = rightHandSource.getName();
	this->birhday = rightHandSource.getBirthday();
	return *this;
}

PersonInfo& PersonInfo::setName(const MyString sourceName)
{
	this->name = sourceName;
	return *this;
}

PersonInfo& PersonInfo::setBirthday(const Date sourceDate)
{
	this->birhday = sourceDate;
	return *this;
}

const MyString PersonInfo::getName() const
{
	return name;
}

const Date PersonInfo::getBirthday() const
{
	return birhday;
}

const bool PersonInfo::operator==(const PersonInfo& rightSide) const
{
	return (/*getName() == rightSide.getName())*/  (getBirthday() == rightSide.getBirthday()));
}

const bool PersonInfo::operator!=(const PersonInfo& rightSide) const
{
	return ((getName() != rightSide.getName()) && (getBirthday() != rightSide.getBirthday()));
}

const bool PersonInfo::operator>(const PersonInfo& rightSide) const
{
	return (getBirthday() > rightSide.getBirthday());
}

const bool PersonInfo::operator<(const PersonInfo& rightSide) const
{
	return (getBirthday() < rightSide.getBirthday());
}

istream& operator>>(istream& input, PersonInfo& sourcePerson)
{
	cout << "Enter the person's name --> ";
	input >> sourcePerson.name;

	cout << "Enter the person's birthday in format (mm/dd/yyyy) --> ";
	input >> sourcePerson.birhday;

	return input;
}

ostream& operator<<(ostream& output, const PersonInfo& sourcePerson)
{
	return output << "\tName --> " << sourcePerson.getName()
		<< "\n\tBirthday --> " << sourcePerson.getBirthday() << '\n';
}