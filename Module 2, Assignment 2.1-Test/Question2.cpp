#include <iostream>
using namespace std;

int search(int first, int last, int n);
int mystery(int n);

//int main()
//{
//	cout << mystery(30);
//	return 0;
//}

int search(int first, int last, int n)
{
	int returnValue = 0;
	cout << "Enter: first = " << first << " last = "
		<< last << endl;

	int mid = (first + last) / 2;
	if ((mid * mid) <= n && (n < (mid + 1) * (mid + 1)))
		returnValue = mid;
	else if (mid * mid > n)
		returnValue = search(first, mid - 1, n);
	else
		returnValue = search(mid + 1, last, n);

	cout << "Leave: first = " << first << " last = "
		<< last << endl;
	return returnValue;
}

int mystery(int n)
{
	return search(1, n, n);
}