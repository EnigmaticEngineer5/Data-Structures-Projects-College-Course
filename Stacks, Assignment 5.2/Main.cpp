#include "LinkedStack.h"

#include <iostream>
using namespace std;

int precedence(char ch) {
	switch (ch) {
	case '(':
		return 0;
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	case '^':
		return 3;
	default:
		return -1;
	}
}

string infixToPostfix(string infixExp) {
	LinkedStack<char> aStack{};
	string postfixExp{};

	for (char ch : infixExp) {
		switch (ch) {
		case '(':
			aStack.push(ch);
			break;
		case ')':
			while (!aStack.isEmpty() && aStack.peek() != '(') {
				postfixExp += aStack.peek();
				aStack.pop();
			}
			if (!aStack.isEmpty() && aStack.peek() == '(') {
				aStack.pop();
			}
			break;
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
			while (!aStack.isEmpty() && precedence(aStack.peek()) >= precedence(ch)) {
				postfixExp += aStack.peek();
				aStack.pop();
			}
			aStack.push(ch);
			break;
		default:
			if (ch != ' ') {
				postfixExp += ch;
			}
			break;
		}
	}

	while (!aStack.isEmpty()) {
		postfixExp += aStack.peek();
		aStack.pop();
	}

	return postfixExp;
}

int main() {
	const string infixExps[] = {
		"a - b + c",
		"a - (b / c * d)",
		"a / (b * c)",
		"a / b / c - (d + e) * f",
		"(a + b) * c",
		"a * (b / c / d) + e",
		"a - (b + c)",
		"a - (b + c * d) / e"
	};

	for (size_t i{}; i < (infixExps->size() - 1); i++) {
		cout << "\nExpression #" << (i + 1)
			<< "\n- Infix Expression --> " << infixExps[i]
			<< "\n\t- Postfix Expression --> " << infixToPostfix(infixExps[i]) + '\n';
	}

	cout << "\n\n";
	return 0;
}