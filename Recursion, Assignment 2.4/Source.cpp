#include <iostream>
#include <cstdlib>

using namespace std;

template<typename ItemType>
ItemType* createList(int&);

template<typename ItemType>
void getValues(ItemType[], const int);

template<typename ItemType>
void elementSearch(ItemType*, int);

template<typename ItemType>
void operationsMenu(ItemType*&, int&);

template<typename ItemType>
void displayValues(const ItemType[], const int);

template<typename ItemType>
void merge(ItemType[], int, int, int);

template<typename ItemType>
void mergeSort(ItemType[], int, int);

template <typename ItemType>
const int binarySearch(const ItemType[], int, int, const ItemType);

void memError();

int main() {
	int listSize{};
	int *list{ createList<int>(listSize) };
	getValues(list, listSize);

	cout << "\nThe list values are:";
	displayValues(list, listSize);

	cout << "\nThe list sorted values are:"
		<< "\nSorting list...";
	mergeSort(list, 0, (listSize - 1));
	displayValues(list, listSize);
	operationsMenu(list, listSize);

	if (list != nullptr) {
		delete[] list;
		list = nullptr;
	}

	cout << "\n\n";
	return 0;
}

template<typename ItemType>
void operationsMenu(ItemType*& numsList, int& listSize) {
	enum MyEnum {
		searchList = 1,
		enterNewList = 2,
		displayList = 3,
		exitProgram = 4
	};

	int optionSelected{};
	do {
		cout << "\nSelect an option"
			<< "\n\t1) Search List"
			<< "\n\t2) Enter New List"
			<< "\n\t3) Display List"
			<< "\n\t4) Exit Program"
			<< "\n--> ";
		cin >> optionSelected;

		while (cin.fail() || optionSelected < searchList || optionSelected > exitProgram) {
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "\nPlease re-enter a valid option --> ";
				cin >> optionSelected;
			}
			else {
				cout << "\nChoose between a valid range --> ";
				cin >> optionSelected;
			}
		}

		switch (optionSelected) {
		case searchList:
			elementSearch(numsList, listSize);
			break;

		case enterNewList:
			delete[] numsList;
			numsList = createList<int>(listSize);
			getValues(numsList, listSize);
			cout << "\nSorting list...";
			mergeSort(numsList, 0, (listSize - 1));
			break;

		case displayList:
			displayValues(numsList, listSize);
			break;

		default:
			cout << "\nExiting program...";
			break;
		}
	} while (optionSelected != exitProgram);
}

template<typename ItemType>
ItemType* createList(int& listSize) {
	cout << "\t- Enter SIZE of list --> ";
	std::cin >> listSize;

	while (cin.fail() || listSize < 1) {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cerr << "\nInvalid input, re-enter --> ";
			cin >> listSize;
		}
		else {
			cerr << "\nPlease re-enter a SIZE above zero --> ";
			cin >> listSize;
		}
	}

	ItemType* list{ nullptr };
	try {
		list = new ItemType[listSize] {};
	}
	catch (std::bad_alloc) {
		memError();
	}

	return list;
}

template<typename ItemType>
void elementSearch(ItemType* numsList, int listSize) {
	cout << "\n\t- Enter the TARGET --> ";
	ItemType targetElement{};
	cin >> targetElement;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\nInvalid entry, re-enter --> ";
		cin >> targetElement;
	}

	const int elementIndex{ binarySearch(numsList, 0, (listSize - 1), targetElement) };
	(elementIndex == -1) ? cout << "\n\nThe element was not found...\n" : cout << "\n\nElement found in cell #" << elementIndex << '\n';
}

template<typename ItemType>
void getValues(ItemType numsList[], const int listSize) {
	cout << '\n';
	for (int i{}; i < listSize; i++) {
		cout << "\t- Enter value #" << (i + 1) << " --> ";
		cin >> numsList[i];

		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cerr << "\nInvalid input, re-enter --> ";
			cin >> numsList[i];
		}
	}
}

template<typename ItemType>
void merge(ItemType theArray[], int first, int mid, int last) {
	ItemType* tempArray{ new ItemType[(last + 1)] {} };
	int first1{ first },
		last1{ mid },
		first2{ (mid + 1) },
		last2{ last },
		index{ first1 };

	while ((first1 <= last1) && (first2 <= last2)) {
		if (theArray[first1] <= theArray[first2]) {
			tempArray[index] = theArray[first1];
			first1++;
		}
		else {
			tempArray[index] = theArray[first2];
			first2++;
		}
		index++;
	} 

	while (first1 <= last1) {
		tempArray[index] = theArray[first1];
		first1++;
		index++;
	}  

	while (first2 <= last2) {
		tempArray[index] = theArray[first2];
		first2++;
		index++;
	}

	for (index = first; index <= last; index++) {
		theArray[index] = tempArray[index];
	}
}

template <typename ItemType>
void mergeSort(ItemType theArray[], int first, int last) {
	if (first < last) {
		int mid{ (last + first) / 2 };
		mergeSort(theArray, first, mid);
		mergeSort(theArray, mid + 1, last);
		merge(theArray, first, mid, last);
	} 
}  

template<typename ItemType>
void displayValues(const ItemType numsList[], const int listSize) {
	cout << "\n\t\t";
	for (int i{}; i < listSize; i++) {
		if ((i + 1) % 6 == 0) {
			cout << "\n\t\t";
		}
		cout << '[' << numsList[i] << ']';
	}
	cout << "\n\n";
}

template <typename ItemType>
const int binarySearch(const ItemType anArray[], int first, int last, const ItemType target) {
	int index{};
	if (first > last) {
		index = -1;
	}
	else {
		int mid = first + (last - first) / 2;
		if (target == anArray[mid]) {
			index = mid;
		}
		else if (target < anArray[mid]) {
			index = binarySearch(anArray, first, mid - 1, target);
		}
		else {
			index = binarySearch(anArray, mid + 1, last, target);
		}
	}
	return index;
}

void memError() {
	cerr << "Error --> Heap Out of memory\n";
	exit(EXIT_FAILURE);
}