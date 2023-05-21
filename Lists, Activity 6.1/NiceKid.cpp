#include "NiceKid.h"
//
////NiceKid::NiceKid() : kidName{}, giftList{} {};
////NiceKid::~NiceKid() {};
//
NiceKid& NiceKid::addGift()
{
	cout << "\n\t- Enter the Kid's new gift --> ";
	string tmpGift{};
	getline(cin >> ws, tmpGift);
	this->giftList.insert(1, tmpGift);

	return *this;
}

void NiceKid::checkIndex(int& sourceIndex)
{
	cin >> sourceIndex;

	while (cin.fail() || sourceIndex < 1 || sourceIndex > getGiftCount()) {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\nInvalid element index, please re-enter --> ";
			cin >> sourceIndex;
		}
		else {
			cout << "\nPlease re-enter an element index in a valid range --> ";
			cin >> sourceIndex;
		}
	}
}

NiceKid& NiceKid::removeGift()
{
	cout << "\n\t- Enter the Kid's gift index to remove --> ";
	int elementToRemove{};
	checkIndex(elementToRemove);
	this->giftList.remove(elementToRemove);

	return *this;
}

NiceKid& NiceKid::replaceGift()
{
	cout << "\n\t- Enter the Kid's new gift --> ";
	string tmpGift{};
	getline(cin >> ws, tmpGift);

	cout << "\n\t- Enter the Kid's gift index to replace --> ";
	int elementToReplace{};
	checkIndex(elementToReplace);
	this->giftList.setEntry(elementToReplace, tmpGift);

	return *this;
}

const int NiceKid::getGiftCount() const
{
	return giftList.getLength();
}

NiceKid& NiceKid::setKidName(const string sourceName)
{
	this->kidName = sourceName;
	return *this;
}

NiceKid& NiceKid::setGiftList(const LinkedList<string>& sourceList)
{
	this->giftList = sourceList;
	return *this;
}

const string NiceKid::getKidName() const
{
	return kidName;
}

istream& operator>>(istream& input, NiceKid& sourceKid)
{
	cout << "\n\t- Enter the Kid's name --> ";
	getline(input >> ws, sourceKid.kidName);

	cout << "\t- How many gifts for " << sourceKid.getKidName() << "? --> ";
	int giftCount{};
	input >> giftCount;

	cout << '\n';
	for (int i{}; i < giftCount; i++) {
		cout << "\t- What's gift #" << (i + 1) << "? --> ";
		string giftDescription{};
		getline(input >> ws, giftDescription);
		sourceKid.giftList.insert(1, giftDescription);
	}
	return input;
}

ostream& operator<<(ostream& output, const NiceKid& sourceKid)
{
	cout << "\n\t- " << sourceKid.getKidName() << " has " << sourceKid.getGiftCount() << " gifts!"
		<< "\nThose are:";
	for (int i{ 1 }; i <= sourceKid.getGiftCount(); i++) {
		cout << "\nGift #" << i << " --> " << sourceKid.giftList.getEntry(i);
	}
	return output;
}