#include <iostream>
using std::cout;

const int ackermannFunction(const int m, const int n) {
	if (m == 0) {
		return (n + 1);
	}
	else if (n == 0) {
		return ackermannFunction(m - 1, 1);
	}
	else {
		return ackermannFunction(m - 1, ackermannFunction(m, n - 1));
	}
}

int main() {
	cout << "A(0, 0) = " << ackermannFunction(0, 0) << '\n'
		<< "A(0, 1) = " << ackermannFunction(0, 1) << '\n'
		<< "A(1, 1) = " << ackermannFunction(1, 1) << '\n'
		<< "A(1, 2) = " << ackermannFunction(1, 2) << '\n'
		<< "A(1, 3) = " << ackermannFunction(1, 3) << '\n'
		<< "A(2, 2) = " << ackermannFunction(2, 2) << '\n'
		<< "A(3, 2) = " << ackermannFunction(3, 2) << '\n';

	return 0;
}