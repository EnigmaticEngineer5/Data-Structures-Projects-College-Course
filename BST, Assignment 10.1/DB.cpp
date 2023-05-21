#include "DB.h"

DB::DB() : BST{}, numberOfPeople{} {};

DB::DB(const BinarySearchTree<PersonInfo>& sourceBST, const int sourceNumberOfPeople)
	: BST(sourceBST), numberOfPeople(sourceNumberOfPeople) {};

DB::DB(const DB& sourceDB)
	: BST(sourceDB.BST), numberOfPeople(sourceDB.numberOfPeople) {};

DB::~DB() {};

DB& DB::operator=(const DB& sourceRightBST)
{
	if (this != &sourceRightBST) {
		this->setBST(sourceRightBST.getBST()).setNumberOfPeople(sourceRightBST.getNumberOfPeople());
	}
	return *this;
}

DB& DB::setBST(const BinarySearchTree<PersonInfo>& sourceBST)
{
	this->BST = sourceBST;
	return *this;
}

DB& DB::setNumberOfPeople(const int sourceNumberOfPeople)
{
	this->numberOfPeople = sourceNumberOfPeople;
	return *this;
}

const BinarySearchTree<PersonInfo> DB::getBST() const
{
	return BST;
}

const int DB::getNumberOfPeople() const
{
	return BST.getNumberOfNodes();
}

BinarySearchTree<MyString> namesInOrder{};

template<class T>
void accessEntries(T& anEntry) {
	namesInOrder.add(anEntry.getName());
}

void DB::searchPerson() const
{
	if (getNumberOfPeople() == 1) {
		cout << "There is only one person in the database.\n"
			<< "Displaying the person's information...\n"
			<< BST.getRootData() << '\n';
	}
	else if (BST.isEmpty()) {
		cout << "The database is empty.\n";
	}
	else {
		cout << "Enter the name of the person you want to search --> ";
		MyString name{};
		cin >> name;

		BST.preorderTraverse(accessEntries);
		if (namesInOrder.contains(name)) {
			cout << "\nThe person is in the database!\n";
		}
		else {
			cout << "\nThe person is not in the database...\n";
		}
		namesInOrder.clear();
	}
}

void DB::displayPerson() const
{
	if (getNumberOfPeople() == 1) {
		cout << "There is only one person in the database.\n"
			<< "Displaying the person's information...\n"
			<< BST.getRootData() << '\n';
	}
	else if (BST.isEmpty()) {
		cout << "The database is empty.\n";
	}
	else {
		cout << "You need to enter the birthday of the person you want to display.\n"
			<< "Enter the birthday of the person you want to display --> ";
		Date birthday{};
		cin >> birthday;
		const PersonInfo personToSearch{ "", birthday };

		if (BST.contains(personToSearch)) {
			cout << "The person is in the database!\n"
				<< "\nDisplaying the person's information...\n"
				<< BST.getEntry(personToSearch) << '\n';
		}
		else {
			cout << "The person is not in the database.\n";
		}
	}
}

int counter{};
template<class T>
void display(T& anItem) {
	cout << "Person # " << ++counter
		<< '\n' << anItem << '\n';
}

void DB::displayInBirthdayOrder() const
{
	if (!BST.isEmpty()) {
		cout << "\nDisplaying the people in the database in birthday order...\n";
		BST.inorderTraverse(display);
		counter = 0;
	}
	else {
		cout << "The database is empty.\n";
	}
}

void DB::displayInNameOrder() const
{
	if (BST.isEmpty()) {
		cout << "The database is empty.\n";
	}
	else {
		cout << "\nDisplaying the people in the database in name order...\n";

		BST.preorderTraverse(accessEntries);
		namesInOrder.inorderTraverse(display);
		counter = 0;
		namesInOrder.clear();
	}
}

void DB::simulate()
{
	BST.add(PersonInfo("John", Date(1, 1, 2000)));
	BST.add(PersonInfo("Mary", Date(2, 2, 2000)));
	BST.add(PersonInfo("Bob", Date(3, 3, 2000)));
	BST.add(PersonInfo("Alice", Date(4, 4, 2000)));
	BST.add(PersonInfo("Zack", Date(5, 5, 2000)));
	BST.add(PersonInfo("Sally", Date(6, 6, 2000)));
	BST.add(PersonInfo("Joe", Date(7, 7, 2000)));
	BST.add(PersonInfo("Sue", Date(8, 8, 2000)));
	BST.add(PersonInfo("Tom", Date(9, 9, 1950)));
	BST.add(PersonInfo("Jill", Date(10, 10, 2008)));
	BST.add(PersonInfo("Bill", Date(11, 11, 2020)));
	BST.add(PersonInfo("Jen", Date(12, 12, 2007)));
	BST.add(PersonInfo("Tim", Date(12, 13, 2005)));
	BST.add(PersonInfo("Jenny", Date(12, 14, 2003)));

	BST.inorderTraverse(display);
	counter = 0;
}

void DB::preorderDisplay() const
{
	if (BST.isEmpty()) {
		cout << "The database is empty.\n";
	}
	else {
		cout << "\nDisplaying the people in the database in preorder...\n";
		BST.preorderTraverse(display);
		counter = 0;
	}
}

void DB::postorderDisplay() const
{
	if (BST.isEmpty()) {
		cout << "The database is empty.\n";
	}
	else {
		cout << "\nDisplaying the people in the database in postorder...\n";
		BST.postorderTraverse(display);
		counter = 0;
	}
}

void DB::eraseDatabase()
{
	if (BST.isEmpty()) {
		cout << "The database is already empty.\n";
	}
	else {
		BST.clear();
		cout << "Database erased!\n";
	}
}

void DB::modifyPerson()
{
	if (BST.isEmpty()) {
		cout << "The database is empty.\n";
	}
	else {
		BST.inorderTraverse(display);
		counter = 0;
		cout << "Enter the birthday of the person you want to modify --> ";
		Date birthday{};
		cin >> birthday;
		const PersonInfo personToModify{ "", birthday };

		if (BST.contains(personToModify)) {
			cout << "\nPerson found!"
				<< "\nEnter the new information for the person:\n";

			PersonInfo newPerson{};
			cin >> newPerson;
			BST.remove(personToModify);
			BST.add(newPerson);
			cout << "\nPerson modified!\n";
			BST.inorderTraverse(display);
			counter = 0;
		}
		else {
			cout << "\nThe person is not in the database...\n";
		}
	}
}

void DB::removePerson()
{
	if (BST.isEmpty()) {
		cout << "The database is empty.\n";
	}
	else if (getNumberOfPeople() == 1) {
		cout << "There is only one person in the database.\n"
			<< "Removing the person from the database...\n";
		eraseDatabase();
		cout << "Person removed!\n";
	}
	else {
		BST.inorderTraverse(display);
		counter = 0;
		cout << "Enter the birthday of the person you want to remove --> ";
		Date birthday{};
		cin >> birthday;
		const PersonInfo personToRemove{ "", birthday };

		if (BST.contains(personToRemove)) {
			BST.remove(personToRemove);
			cout << "Person removed!\n";
			BST.inorderTraverse(display);
			counter = 0;
		}
		else {
			cout << "The person is not in the database...\n";
		}
	}
}

void DB::addPerson()
{
	cout << "\nEnter the information for the person you want to add:\n";
	PersonInfo personToAdd{};
	cin >> personToAdd;
	BST.add(personToAdd);
	cout << "Person added!\n";
	BST.inorderTraverse(display);
	counter = 0;
}
