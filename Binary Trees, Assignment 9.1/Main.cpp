#include "BinaryNodeTree.h"

#include<iostream>
#include "Main.h"

using namespace std;

template<class T>
void display(T& anItem) {
	cout << anItem << ",";
}

int main() {
	BinaryNodeTree <char> balanceTree{};
	balanceTree.add('A');
	balanceTree.add('B');
	balanceTree.add('C');
	balanceTree.add('D');
	balanceTree.add('E');
	balanceTree.add('F');
	balanceTree.add('G');
	displayTraversals(balanceTree);
	return 0;
}

void displayTraversals(BinaryNodeTree<char>& balanceTree)
{
	cout << "Preorder Traversal:";
	balanceTree.preorderTraverse(display);

	cout << "\nIn-order Traversal:";
	balanceTree.inorderTraverse(display);

	cout << "\nPostorder Traversal:";
	balanceTree.postorderTraverse(display);
	cout << '\n';
}
