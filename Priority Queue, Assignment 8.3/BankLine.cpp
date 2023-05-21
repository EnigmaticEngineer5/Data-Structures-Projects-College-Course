#include "BankLine.h"

BankLine::BankLine() : arrivalsAndDepartures{}, waitingList{} {};

BankLine::BankLine(const SL_PriorityQueue<Client>& sourceArrivals, const LinkedQueue<Client>& sourceWaitingList)
	: arrivalsAndDepartures(sourceArrivals), waitingList(sourceWaitingList) {};

BankLine::BankLine(const BankLine& sourceBankLine)
	: arrivalsAndDepartures(sourceBankLine.getArrivalsAndDepartures()), waitingList(sourceBankLine.getWaitingList()) {};

BankLine& BankLine::setArrivalsAndDepartures(const SL_PriorityQueue<Client>& sourceArrivals)
{
	this->arrivalsAndDepartures = sourceArrivals;
	return *this;
}

BankLine& BankLine::setWaitingList(const LinkedQueue<Client>& sourceWaitingList)
{
	this->waitingList = sourceWaitingList;
	return *this;
}

const SL_PriorityQueue<Client> BankLine::getArrivalsAndDepartures() const
{
	return arrivalsAndDepartures;
}

const LinkedQueue<Client> BankLine::getWaitingList() const
{
	return waitingList;
}

void BankLine::simulation()
{
	ifstream inputFile("Input.txt");
	Client currentClient{ 'A', 0, "Unnamed", 0 };

	if (inputFile) {
		extractFile(inputFile, currentClient);
	}
	else {
		cerr << "\nUnable to open file...";
		return;
	}
	inputFile.close();

	cout << "\nInput file\n"
		<< "_____________________________________________\n";
	LinkedQueue<Client> waitingListCopy(waitingList);
	while (!waitingListCopy.isEmpty()) {
		cout << '\n' << waitingListCopy.peekFront();
		waitingListCopy.dequeue();
	}

	cout << "\n\n";

	int counter{}, clientDeparture{}, totalOfPeople{};
	double totalOfWaitTimes{};
	char departed{ 'D' };
	Client priorDeparture{};
	while (!waitingList.isEmpty()) {
		filterEvents(counter, clientDeparture, priorDeparture, departed, totalOfWaitTimes);
		totalOfPeople++;
	}

	cout << "\n\nOutput from processing file above\n"
		<< "_____________________________________________\n"
		<< "\nSimulation begins";

	while (!arrivalsAndDepartures.isEmpty()) {
		displayEvents(departed);
		arrivalsAndDepartures.remove();
	}

	cout << "\nSimulation Ends"
		<< "\n\nFinal Stadistics:"
		<< "\n\t- Total number of people processed --> " << totalOfPeople
		<< "\n\t- Average amount of time spent waiting --> " << (totalOfWaitTimes / totalOfPeople);
}

void BankLine::extractFile(std::ifstream& inputFile, Client& currentClient)
{
	while (!inputFile.eof()) {
		int time{}, waitTime{};
		inputFile >> time >> waitTime;
		currentClient.setTime(time).setTransactionTime(waitTime);
		waitingList.enqueue(currentClient);
	}
}

void BankLine::displayEvents(char departed)
{
	if (arrivalsAndDepartures.peek().getStatus() == departed) {
		cout << "\nProcessing a departure event at time --> " << arrivalsAndDepartures.peek().getTime();
	}
	else {
		cout << "\nProcessing an arrival event at time --> " << arrivalsAndDepartures.peek().getTime();
	}
}

void BankLine::filterEvents(int& counter, int& clientDeparture, Client& priorDeparture, char departed, double& totalWaitTimes)
{
	arrivalsAndDepartures.add(waitingList.peekFront());
	if (counter++ == 0) {
		clientDeparture = (waitingList.peekFront().getTime() + waitingList.peekFront().getTransactionTime());
		priorDeparture = Client(departed, clientDeparture, waitingList.peekFront().getName(), waitingList.peekFront().getTransactionTime());
		totalWaitTimes += priorDeparture.getTransactionTime();
	}
	else {
		checkIfCumulative(priorDeparture, clientDeparture, departed, totalWaitTimes);
	}

	arrivalsAndDepartures.add(priorDeparture);
	waitingList.dequeue();
}

void BankLine::checkIfCumulative(Client& priorDeparture, int& clientDeparture, char departed, double& totalWaitTimes)
{
	if (priorDeparture > waitingList.peekFront()) {
		clientDeparture = (priorDeparture.getTime() + waitingList.peekFront().getTransactionTime());
		priorDeparture = Client(departed, clientDeparture, waitingList.peekFront().getName(), (clientDeparture - waitingList.peekFront().getTime()));
	}
	else {
		clientDeparture = (waitingList.peekFront().getTime() + waitingList.peekFront().getTransactionTime());
		priorDeparture = Client(departed, clientDeparture, waitingList.peekFront().getName(), (clientDeparture - waitingList.peekFront().getTime()));
	}
	totalWaitTimes += priorDeparture.getTransactionTime();
}



