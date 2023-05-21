#include "Client.h"

Client::Client(const char sourceStatus, const int sourceTime, const string sourceName, const int sourceTransactionTime)
	: statusOfClient(sourceStatus), arrivedTime(sourceTime), clientName(sourceName), transactionTime(sourceTransactionTime) {};

Client::Client(const Client& sourceClient)
	: statusOfClient(sourceClient.getStatus()), arrivedTime(sourceClient.getTime()),
	clientName(sourceClient.getName()), transactionTime(sourceClient.getTransactionTime()) {};

const bool Client::operator>(const Client& rightSide)
{
	return (getTime() > rightSide.getTime());
}

const bool Client::operator!=(const Client& rightSide)
{
	return (getTime() != rightSide.getTime());
}

const bool Client::operator==(const Client& rightSide)
{
	return (getTime() == rightSide.getTime());
}

Client& Client::setStatus(const char sourceStatus)
{
	this->statusOfClient = sourceStatus;
	return *this;
}

Client& Client::setTime(const int sourceTime)
{
	this->arrivedTime = sourceTime;
	return *this;
}

Client& Client::setClientName(const string sourceName)
{
	this->clientName = sourceName;
	return *this;
}

Client& Client::setTransactionTime(const int sourceTransactionTime)
{
	this->transactionTime = sourceTransactionTime;
	return *this;
}

const char Client::getStatus() const
{
	return statusOfClient;
}

const int Client::getTime() const
{
	return arrivedTime;
}

const string Client::getName() const
{
	return clientName;
}

const int Client::getTransactionTime() const
{
	return transactionTime;
}

istream& operator>>(istream& input, Client& sourceClient)
{
	return input;
}

ostream& operator<<(ostream& output, const Client& sourceClient)
{
	return output << sourceClient.getTime() << '\t'
		<< sourceClient.getTransactionTime() << '\t'
		<< sourceClient.getStatus() << '\t'
		<< sourceClient.getName();
}