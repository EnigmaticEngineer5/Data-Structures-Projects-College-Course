//void displayBag(BagInterface<string>* bagPtr)
//{
//	cout << "\nThe bag contains " << bagPtr->getCurrentSize()
//		<< " items:" << endl;
//
//	vector<string> bagItems{ bagPtr->toVector() };
//
//	for (const auto& it : bagItems) {
//		cout << it << ' ';
//	}
//
//	cout << endl << endl;
//}
//
//void bagTester(BagInterface<string>* bagPtr)
//{
//	cout << "isEmpty: returns " << bagPtr->isEmpty()
//		<< "; should be 1 (true)" << endl;
//
//	string items[] = { "one", "two", "three", "four", "five", "one" };
//
//	cout << "Add 6 items to the bag: " << endl;
//	for (int i = 0; i < 6; i++)
//	{
//		bagPtr->add(items[i]);
//	}
//
//	displayBag(bagPtr);
//
//	cout << "isEmpty: returns " << bagPtr->isEmpty()
//		<< "; should be 0 (false)" << endl;
//
//	cout << "getCurrentSize returns : " << bagPtr->getCurrentSize()
//		<< "; should be 6" << endl;
//
//	cout << "Try to add another entry: add(\"extra\") returns "
//		<< bagPtr->add("extra") << endl;
//}
//
//int main()
//{
//	BagInterface<string>* bagPtr = nullptr;
//	char userChoice{};
//	cout << "Enter 'A' to test the array-based implementation\n"
//		<< " or 'L' to test the link-based implementation --> ";
//	cin >> userChoice;
//
//	if (toupper(userChoice) == 'A')
//	{
//		bagPtr = new ArrayBag<string>();
//		cout << "Testing the Array-Based Bag:" << endl;
//	}
//	else
//	{
//		bagPtr = new LinkedBag<string>();
//		cout << "Testing the Link-Based Bag:" << endl;
//	}
//
//	cout << "The initial bag is empty." << endl;
//
//	bagTester(bagPtr);
//
//	delete bagPtr;
//	bagPtr = nullptr;
//
//	cout << "All done!" << endl;
//	return 0;
//}

//template <typename T>
//BagInterface<T>* createBag()
//{
//	BagInterface<T>* dataPtr{ nullptr };
//
//	cout << "\t1) Linked Bag"
//		<< "\n\t2) Array Bag"
//		<< "\n\t --> ";
//	int selection{};
//	cin >> selection;
//
//	switch (selection)
//	{
//	case 1:
//		dataPtr = new LinkedBag<T>();
//		break;
//
//	case 2:
//		dataPtr = new ArrayBag<T>();
//		break;
//
//	default:
//		cout << "\nExiting program...";
//	}
//
//	return dataPtr;
//}
//
//template <typename T>
//void displayBag(BagInterface<T>* elements)
//{
//	const vector<T> toPrint{ elements->toVector() };
//
//	cout << '\n';
//	for (const auto& it : toPrint) {
//		cout << it + '\n';
//	}
//}
//
//int main() {
//	BagInterface<string>* bag{ createBag<string>() };
//
//	if (bag != nullptr)
//	{
//		bag->add("Hello World!");
//
//		displayBag(bag);
//
//		delete bag;
//		bag = nullptr;
//	}
//
//	return 0;
//}