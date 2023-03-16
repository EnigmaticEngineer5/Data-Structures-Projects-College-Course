#include <iostream>
using std::cout;

const int searchSimilarOcurrences(const int* arrayOfIntegers, size_t arraySize, const int numToSearch) {
	int count{};
	if (arraySize == 0) {
		return 0;
	}
	else {
		if (arrayOfIntegers[(arraySize - 1)] == numToSearch) {
			count++;
		}
	}

	return searchSimilarOcurrences(arrayOfIntegers, --arraySize, numToSearch) + count;
}

int main() {
	const int arr[] = { 1,2,4,4,5,6,7,8,9,12 };
	cout << "\t- The number of similar ocurrences is --> " 
		<< searchSimilarOcurrences(arr, (sizeof(arr) / sizeof(arr[0])), 4) 
		<< "\n\n\n";

	return 0;
}