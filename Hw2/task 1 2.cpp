#include <iostream>
using namespace std;

fibonachiFunction(int r)
{
	int a[200];
	a[1] = 1;
	a[2] = 1;
	for (int i = 3; i <= r; i++)
	{
		a[i] = a[i - 2] + a [i - 1];
	}
	return a[r];
}

int main()
{
	int n = 1;
	cout << "Enter n: ";
	cin >> n;
	cout << endl << "Value of n fibonachi number: " << fibonachiFunction(n) << endl;

	return 0;
}