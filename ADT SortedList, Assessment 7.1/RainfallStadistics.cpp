#include "RainfallStadistics.h"

RainfallStadistics::RainfallStadistics() : rainfallYear{} {};

RainfallStadistics::RainfallStadistics(const LinkedSortedList<RainfallMonth>& sourceList)
	: rainfallYear(sourceList) {};

RainfallStadistics::RainfallStadistics(const RainfallStadistics& sourceStadistics)
	: rainfallYear(sourceStadistics.getStadistics()) {};

RainfallStadistics::~RainfallStadistics() {};

RainfallStadistics& RainfallStadistics::setStadistics(const LinkedSortedList<RainfallMonth>& sourceList)
{
	this->rainfallYear = sourceList;
	return *this;
}

const LinkedSortedList<RainfallMonth>& RainfallStadistics::getStadistics() const
{
	return rainfallYear;
}

void RainfallStadistics::displayTotal() const
{
	float yearRainfall{};
	for (int i{}; i < getStadistics().getLength(); i++) {
		yearRainfall += getStadistics().getEntry(i + 1).getRainfall();
	}
	cout << "\n\t- The TOTAL of rainfall throughout the year is --> " << yearRainfall;
}

void RainfallStadistics::displayAverage() const
{
	float yearRainfall{};
	for (int i{}; i < getStadistics().getLength(); i++) {
		yearRainfall += getStadistics().getEntry(i + 1).getRainfall();
	}
	cout << "\n\t- The AVERAGE of rainfall throughout the year is --> " << (yearRainfall / 12.0);
}

void RainfallStadistics::displayHighest() const
{
	cout << "\n\n\t- The month with HIGHEST rain was --> " << getStadistics().getEntry(12).getMonth()
		<< "\n\t- With a rain amount of --> " << getStadistics().getEntry(12).getRainfall();
}

void RainfallStadistics::displayLowest() const
{
	cout << "\n\n\t- The month with LOWEST rain was --> " << getStadistics().getEntry(1).getMonth()
		<< "\n\t- With a rain amount of --> " << getStadistics().getEntry(1).getRainfall();
}

istream& operator>>(istream& input, RainfallStadistics& sourceStadistics)
{
	const int monthsOfYear{ 12 };
	RainfallMonth months[monthsOfYear] = {
		{"January"},
		{"February"},
		{"March"},
		{"April"},
		{"May"},
		{"June"},
		{"July"},
		{"August"},
		{"September"},
		{"October"},
		{"November"},
		{"December"}
	};

	for (int i{}; i < monthsOfYear; i++) {
		input >> months[i];
		sourceStadistics.rainfallYear.insertSorted(months[i]);
	}
	return input;
}

ostream& operator<<(ostream& output, const RainfallStadistics& sourceStadistics)
{
	output << "\nStats:";

	sourceStadistics.displayTotal();
	sourceStadistics.displayAverage();
	sourceStadistics.displayHighest();
	sourceStadistics.displayLowest();

	int counter{};
	output << "\n\nThe months, in order of highest to lowest, with respect to rain are:";
	for (int i{ ((sourceStadistics.getStadistics().getLength()) - 1) }; i >= 0; i--) {
		output << "\nMonth #" << ++counter
			<< sourceStadistics.getStadistics().getEntry(i + 1) << '\n';
	}
	return output;
}