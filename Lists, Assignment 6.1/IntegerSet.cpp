#include "IntegerSet.h"
#include "InvalidRange.h"

IntegerSet::IntegerSet()
{
	for (size_t i{}; i < 101; i++) {
		boolList.insert(i, false);
	}
}

IntegerSet::IntegerSet(const ArrayList<bool> sourceList) : boolList(sourceList) {};
IntegerSet::IntegerSet(const IntegerSet& sourceSet) : boolList(sourceSet.getBoolList()) {};

IntegerSet::IntegerSet(const int sourceNumsArray[], size_t sourceArrSize) : IntegerSet()
{
	int counter{ -1 };
	while (++counter < sourceArrSize) {
		boolList.setEntry(sourceNumsArray[counter], true);
	}
}

IntegerSet::~IntegerSet()
{
	//cout << "\nIntegerSet object released...";
}

IntegerSet& IntegerSet::operator=(const IntegerSet& sourceSet)
{
	this->setList(sourceSet.getBoolList());
	return *this;
}

IntegerSet& IntegerSet::setList(const ArrayList<bool> sourceList)
{
	this->boolList = sourceList;
	return *this;
}

const ArrayList<bool> IntegerSet::getBoolList() const
{
	return boolList;
}

void IntegerSet::unionOfSets(const IntegerSet& sourceSet) const
{
	IntegerSet unionOfSets{ boolList };
	for (size_t i{}; i < 101; i++) {
		if (sourceSet.getBoolList().getEntry(i) == true) {
			unionOfSets.boolList.setEntry(i, sourceSet.getBoolList().getEntry(i));
		}
	}
	cout << "Union of sets..." << unionOfSets;
}

void IntegerSet::intersectionOfSets(const IntegerSet& sourceSet) const
{
	IntegerSet intersectionOfSets{};
	for (size_t i{}; i < 101; i++) {
		if (boolList.getEntry(i) == true && sourceSet.getBoolList().getEntry(i) == true) {
			intersectionOfSets.boolList.setEntry(i, true);
		}
	}
	cout << "\nIntersection of sets..." << intersectionOfSets;
}

void IntegerSet::differenceBetweenSets(const IntegerSet& sourceSet) const
{
	IntegerSet differenceOfSets{};
	bool differenceDetected{ false };
	for (size_t i{}; i < 101; i++) {
		if (getBoolList().getEntry(i) == true && sourceSet.getBoolList().getEntry(i) == false) {
			differenceOfSets.boolList.setEntry(i, true);
			differenceDetected = true;
		}
	}

	if (differenceDetected) {
		cout << "\nDifference between sets..." << differenceOfSets;
	}
	else {
		cout << "\nNo differences were detected!";
	}
}

void IntegerSet::symmetricDifference(const IntegerSet& sourceSet) const
{
	IntegerSet symmetricDifferenceOfSets{};
	bool differenceDetected{ false };
	for (size_t i{}; i < 101; i++) {
		if (getBoolList().getEntry(i) == true && sourceSet.getBoolList().getEntry(i) == false) {
			symmetricDifferenceOfSets.boolList.setEntry(i, true);
			differenceDetected = true;
		}
		else if (sourceSet.getBoolList().getEntry(i) == true && getBoolList().getEntry(i) == false) {
			symmetricDifferenceOfSets.boolList.setEntry(i, true);
			differenceDetected = true;
		}
	}

	if (differenceDetected) {
		cout << "\nSymmetric difference between sets..." << symmetricDifferenceOfSets;
	}
	else {
		cout << "\nNo symmetric differences were detected!";
	}
}

const bool IntegerSet::operator==(const IntegerSet& rightSet) const
{
	for (int i{}; i < rightSet.getBoolList().getLength(); i++) {
		if (boolList.getEntry(i) != rightSet.getBoolList().getEntry(i)) {
			return false;
		}
	}
	return true;
}

istream& operator>>(istream& input, IntegerSet& sourceSet)
{
	cout << "\n\t- How many numbers for the set would you like? --> ";
	int numsCount{};
	input >> numsCount;
	while (input.fail() || numsCount < 1 || numsCount > 100) {
		if (input.fail()) {
			input.clear();
			input.ignore(numeric_limits<streamsize>::max(), '\n');
			cerr << "\nInvalid entry, please re-enter --> ";
			input >> numsCount;
		}
		else {
			cerr << "\nPlease re-enter a valid amount of numbers --> ";
			input >> numsCount;
		}
	}

	int* numsArray{ new int[numsCount] {} };
	for (size_t i{}; i < numsCount; i++) {
		cout << "\t- Enter the number #" << (i + 1) << " --> ";
		input >> numsArray[i];

		bool tryAgain{ true };
		while (tryAgain) {
			try {
				if (numsArray[i] < 0 || numsArray[i] > 100) {
					throw InvalidRange(numsArray[i]);
				}
				else if (input.fail()) {
					throw InputFailure{};
				}

				tryAgain = false;
			}
			catch (InvalidRange invalidRange) {
				cout << "\n\t- Enter the number again --> ";
				input >> numsArray[i];
			}
			catch (InputFailure) {
				input.clear();
				input.ignore(numeric_limits<streamsize>::max(), '\n');
				cerr << "\nInvalid entry, please re-enter --> ";
				input >> numsArray[i];
			}
		}
	}

	sourceSet = IntegerSet(numsArray, numsCount);
	delete[] numsArray;
	numsArray = nullptr;

	return input;
}

ostream& operator<<(ostream& output, const IntegerSet& sourceSet)
{
	for (int i{ 1 }; i < (sourceSet.getBoolList().getLength() + 1); i++) {
		if (sourceSet.getBoolList().getEntry(i) == true) {
			output << "\n\t" << i << " is true.";
		}
	}

	return output << '\n';
}