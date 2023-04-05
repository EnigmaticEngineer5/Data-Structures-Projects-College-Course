#include "ArrayStack.h"

#include <iostream>
#include <string>
using namespace std;

const bool checkBraces(const string sourceString) {
	ArrayStack<char> aStack{};
	bool balancedSoFar{ true };
	int i{};

	while (balancedSoFar && (i < sourceString.length())) {
		char ch{ sourceString.at(i) };
		i++;

		if (ch == '{' || ch == '(' || ch == '[') {
			aStack.push(ch);
		}
		else if (ch == '}' || ch == ')' || ch == ']') {
			if (!aStack.isEmpty() && aStack.peek() == ch) {
				aStack.pop();
			}
			else {
				balancedSoFar = false;
			}
		}
	}
	if (balancedSoFar && aStack.isEmpty()) {
		cout << "\nThe string is balanced!\n\n";
	}
	else {
		cout << "\nThe string is not balanced...\n\n";
	}

	return balancedSoFar;
}

int main() {
	cout << "\t- Enter a string --> ";
	string aString{};
	getline(cin >> ws, aString);
	checkBraces(aString);

	return 0;
}