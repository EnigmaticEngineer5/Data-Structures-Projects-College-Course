#pragma once

#include <iostream>
#include <stdexcept>
using namespace std;

class InvalidRange
{
private:
	int num;

public:
	inline InvalidRange(const int value) : num(value) {
		if (num < 0 || num > 100) {
			cerr << "\nInvalid range!";
		}
	}
};

class InputFailure {
public:
	inline InputFailure() {
		cerr << "\nYou cannot enter a string as an answer for the place of an integer!";
	}
};