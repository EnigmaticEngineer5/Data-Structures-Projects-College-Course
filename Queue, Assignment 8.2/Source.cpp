//#include "LinkedQueue.h"
//#include "Source.h"
//
//const bool isPalindrome(const string someString) {
//	LinkedQueue<char> aQueue{};
//	LinkedStack<char> aStack{};
//
//	for (const auto& character : someString) {
//		addCharacter(character, aQueue, aStack);
//	}
//
//	bool charactersAreEqual{ true };
//	while (!aQueue.isEmpty() && charactersAreEqual) {
//		compareCharacters(aQueue, aStack, charactersAreEqual);
//	}
//
//	return charactersAreEqual;
//}
//
//void compareCharacters(LinkedQueue<char>& aQueue, LinkedStack<char>& aStack, bool& charactersAreEqual)
//{
//	if (tolower(aQueue.peekFront()) == tolower(aStack.peek())) {
//		aQueue.dequeue();
//		aStack.pop();
//	}
//	else {
//		charactersAreEqual = false;
//	}
//}
//
//void addCharacter(const char& character, LinkedQueue<char>& aQueue, LinkedStack<char>& aStack)
//{
//	if (character != ' ') {
//		aQueue.enqueue(character);
//		aStack.push(character);
//	}
//}
//
//const bool isPalindromeImproved(const string someString) {
//	LinkedQueue<char> aQueue{};
//	LinkedStack<char> aStack{};
//
//	for (size_t i{}; i < someString.size(); i++) {
//		addCharacter(i, someString, aQueue, aStack);
//	}
//
//	bool charactersAreEqual{ true };
//	while (!aQueue.isEmpty() && !aStack.isEmpty() && charactersAreEqual) {
//		compareCharacters(aQueue, aStack, charactersAreEqual);
//	}
//
//	return charactersAreEqual;
//}
//
//void addCharacter(const size_t& i, const std::string& someString, LinkedQueue<char>& aQueue, LinkedStack<char>& aStack)
//{
//	if (i < (someString.size() / 2) && someString.at(i) != ' ') {
//		aQueue.enqueue(someString.at(i));
//	}
//	else if (someString.at(i) != ' ') {
//		aStack.push(someString.at(i));
//	}
//}
//
//int main() {
//	string someString{ "Lepers Repel" };
//	cout << someString
//		<< "\n\t- The string is palindrome? (Enhanced algorithm) --> " << boolalpha << isPalindromeImproved(someString)
//		<< "\n\t- The string is palindrome? (Normal algorithm) --> " << boolalpha << isPalindrome(someString) << "\n\n\n";
//
//	someString = "abcda";
//
//	cout << someString
//		<< "\n\t- The string is palindrome? (Enhanced algorithm) --> " << boolalpha << isPalindromeImproved(someString)
//		<< "\n\t- The string is palindrome? (Normal algorithm) --> " << boolalpha << isPalindrome(someString) << "\n\n\n";
//
//	return 0;
//}