#include "RainfallMonth.h"

RainfallMonth::RainfallMonth(const string sourceMonth, const float sourceRain)
	: monthName(sourceMonth), rainfall(sourceRain) {};

RainfallMonth::RainfallMonth(const RainfallMonth& sourceObj)
	: monthName(sourceObj.getMonth()), rainfall(sourceObj.getRainfall()) {};

RainfallMonth::~RainfallMonth() {};

RainfallMonth& RainfallMonth::setMonth(const string sourceMonth)
{
	this->monthName = sourceMonth;
	return *this;
}

RainfallMonth& RainfallMonth::setRainfall(const float sourceRain)
{
	this->rainfall = sourceRain;
	return *this;
}

const string RainfallMonth::getMonth() const
{
	return monthName;
}

const float RainfallMonth::getRainfall() const
{
	return rainfall;
}

const bool RainfallMonth::operator==(const RainfallMonth& rightObj) const
{
	return (getRainfall() == rightObj.getRainfall());
}

const bool RainfallMonth::operator!=(const RainfallMonth& rightObj) const
{
	return (getRainfall() != rightObj.getRainfall());
}

const bool RainfallMonth::operator>(const RainfallMonth& rightObj) const
{
	return (getRainfall() > rightObj.getRainfall());
}

const bool RainfallMonth::operator<(const RainfallMonth& rightObj) const
{
	return (getRainfall() < rightObj.getRainfall());
}

istream& operator>>(istream& input, RainfallMonth& sourceObj)
{
	cout << "\t- Enter the INCHES of RAIN that happened during " << sourceObj.getMonth() << " --> ";
	input >> sourceObj.rainfall;
	while (input.fail() || sourceObj.getRainfall() < 0) {
		if (input.fail()) {
			input.clear();
			input.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\nSorry, invalid input, please re-enter a valid value as indicated --> ";
		}
		else {
			cout << "\nNo negative values accepted, please re-enter a valid number of inches for the rain --> ";
		}
		input >> sourceObj.rainfall;
	}
	return input;
}

ostream& operator<<(ostream& output, const RainfallMonth& sourceObj)
{
	return (output << "\n\t- MONTH --> " << sourceObj.getMonth()
		<< "\n\t- The RAIN was --> " << sourceObj.getRainfall()) << " inches";
}