#include "Client.h"

int main() {
	PriorityQueueInterface<string>* abstractPointer{ new SL_PriorityQueue<string>{} };
	
	abstractPointer->add("Pepe");
	cout << '\n' << abstractPointer->peek() + "\n\n";
	abstractPointer->remove();

	abstractPointer->add("Hannah");
	cout << '\n' << abstractPointer->peek() + "\n\n";
	
	abstractPointer = nullptr;
	return 0;
}