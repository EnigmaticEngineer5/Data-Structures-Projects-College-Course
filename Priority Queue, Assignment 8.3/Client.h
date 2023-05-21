#pragma once

#include <iostream>
using namespace std;

class Client
{
private:
	char statusOfClient;
	int arrivedTime;
	int transactionTime;

	string clientName;

public:
	Client(const char = '\0', const int = 0, const string = "", const int = 0);
	Client(const Client&);
	inline ~Client() = default;

	const bool operator > (const Client&);
	const bool operator != (const Client&);
	const bool operator == (const Client&);

	Client& setStatus(const char);
	Client& setTime(const int);
	Client& setTransactionTime(const int);
	Client& setClientName(const string);
	const char getStatus() const;
	const int getTime() const;
	const int getTransactionTime() const;
	const string getName() const;

	friend istream& operator >> (istream&, Client&);
	friend ostream& operator << (ostream&, const Client&);
};