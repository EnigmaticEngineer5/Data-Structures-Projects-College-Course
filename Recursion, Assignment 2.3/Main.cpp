#include <iostream>
using std::cout;

int activationRecords{};

const int searchSimilarOcurrences(const int* arrayOfIntegers, size_t arraySize, const int numberToSearch) {
	activationRecords++;

	int count{};
	if (arraySize == 0) {
		return 0;
	}
	else {
		(arrayOfIntegers[(arraySize - 1)] == numberToSearch) ? count++ : count = 0;
	}

	return searchSimilarOcurrences(arrayOfIntegers, --arraySize, numberToSearch) + count;
}

int main() {
	const int integersArray[] = { 1,2,4,4,5,6,7,8,9,12 },
		arraySize{ (sizeof(integersArray) / sizeof(integersArray[0])) },
		numberToSearch{ 4 };

	cout << "\t- The number of similar occurrences is --> "
		<< searchSimilarOcurrences(integersArray, arraySize, numberToSearch)
		<< "\n\t- The number of activation records are --> " << activationRecords << "\n\n";

	return 0;
}