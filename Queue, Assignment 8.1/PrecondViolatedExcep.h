#pragma once

#include<iostream>
#include <stdexcept>
#include <string>

using namespace std;

class PrecondViolatedExcep final : public logic_error
{
public:
	inline PrecondViolatedExcep(const string& message = "") : logic_error("Precondition Violated Exception: " + message)
	{
		cout << "Not Found Exception: " + message << endl;
	}
};