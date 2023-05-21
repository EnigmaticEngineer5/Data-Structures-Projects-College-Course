#pragma once

#include "Client.h"
#include "PriorityQueue.h"
#include "../Queue, Assignment 8.2/LinkedQueue.h"

#include <fstream>

class BankLine
{
private:
	SL_PriorityQueue<Client> arrivalsAndDepartures;
	LinkedQueue <Client> waitingList;

public:
	BankLine();
	BankLine(const SL_PriorityQueue<Client>&, const LinkedQueue<Client>&);
	BankLine(const BankLine&);
	inline ~BankLine() = default;

	BankLine& setArrivalsAndDepartures(const SL_PriorityQueue<Client>&);
	BankLine& setWaitingList(const LinkedQueue<Client>&);
	const SL_PriorityQueue<Client> getArrivalsAndDepartures() const;
	const LinkedQueue<Client> getWaitingList() const;

	void simulation();
	void extractFile(std::ifstream& inputFile, Client& currentClient);
	void displayEvents(char departed);
	void filterEvents(int& counter, int& clientDeparture, Client& priorDeparture, char departed, double&);
	void checkIfCumulative(Client& priorDeparture, int& clientDeparture, char departed, double&);
};