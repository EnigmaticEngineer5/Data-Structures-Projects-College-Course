#include "CircularList.h"

CircularList::CircularList() : numsCircularList{}
{
}

CircularList::CircularList(const LinkedList<int>& sourceList) : numsCircularList(sourceList)
{
}

CircularList::CircularList(const CircularList& sourceCircularList) :
	numsCircularList(sourceCircularList.numsCircularList)
{
}

CircularList::~CircularList()
{
}

CircularList& CircularList::setList(const LinkedList<int>& sourceList)
{
	this->numsCircularList = sourceList;
	return *this;
}


CircularList& CircularList::reverseList()
{
	this->numsCircularList.reverse();
	cout << "List resversed successfully...";
	return *this;
}

istream& operator>>(istream& input, CircularList& sourceList)
{
	cout << "\n\t- How many numbers would you like to enter? --> ";
	int tmpSize{};
	input >> tmpSize;
	while (input.fail() || tmpSize < 1) {
		if (input.fail()) {
			input.clear();
			input.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\nSorry, please re-enter a valid amount of numbers --> ";
		}
		else {
			cout << "\n\t- Please re-enter a valid size --> ";
		}
		input >> tmpSize;
	}

	for (int i{}; i < tmpSize; i++) {
		cout << "\t- " << (i + 1) << ") Enter number --> ";
		int tmpNum;
		input >> tmpNum;
		while (input.fail()) {
			cout << "\n\t- The entry failed, please re-enter --> ";
			input >> tmpNum;
		}

		sourceList.numsCircularList.insert((i + 1), tmpNum);
	}

	cout << "\nThe numbers you entered are:\n\t --> "
		<< sourceList;

	return input;
}

ostream& operator<<(ostream& output, const CircularList& sourceList)
{
	for (int i{}; i < sourceList.numsCircularList.getLength(); i++) {
		output << sourceList.numsCircularList.getEntry(i + 1) << ' ';
	}

	return output;
}