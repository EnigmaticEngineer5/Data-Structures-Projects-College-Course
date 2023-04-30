#include "ArrayQueue.h"

#include<iostream>
using namespace::std;


int main() {
	ArrayQueue <int> myQueue1;

	myQueue1.enqueue(5);
	myQueue1.enqueue(15);
	myQueue1.enqueue(20);
	myQueue1.enqueue(25);

	myQueue1.display();
	cout << myQueue1.peekFront() << endl;

	myQueue1.dequeue();
	myQueue1.display();

	myQueue1.dequeue();
	myQueue1.display();

	myQueue1.enqueue(30);
	myQueue1.enqueue(35);
	myQueue1.dequeue(); 
	myQueue1.display();

	ArrayQueue<int> myQueue2(myQueue1);
	myQueue2.display();

	return 0;
}
