#include <iostream>
using std::cout;

int reverseDigits(int number, int reversed = 0) {
	if (number == 0) {
		return reversed;
	}
	else {
		return reverseDigits((number / 10), (reversed * 10) + (number % 10));
	}
}

int main() {
	cout << reverseDigits(123456789);
	return 0;
}