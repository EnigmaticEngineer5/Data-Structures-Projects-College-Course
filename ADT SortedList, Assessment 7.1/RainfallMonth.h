#pragma once

#include <iostream>
#include <string>

using namespace std;

class RainfallMonth
{
private:
	string monthName;
	float rainfall;

public:
	RainfallMonth(const string = "", const float = 0.0);
	RainfallMonth(const RainfallMonth&);
	~RainfallMonth();

	RainfallMonth& setMonth(const string);
	RainfallMonth& setRainfall(const float);
	const string getMonth() const;
	const float getRainfall() const;

	const bool operator == (const RainfallMonth&) const;
	const bool operator != (const RainfallMonth&) const;
	const bool operator > (const RainfallMonth&) const;
	const bool operator < (const RainfallMonth&) const;

	friend istream& operator >> (istream&, RainfallMonth&);
	friend ostream& operator << (ostream&, const RainfallMonth&);
};