#include <iostream>
using namespace std;

fibonachiFunction(int r)
{
	if ((r == 1) || (r == 2)) return 1;
	return (fibonachiFunction(r - 1) + fibonachiFunction(r - 2));
}

int main()
{
	int n = 1;
	cout << "Enter n: ";
	cin >> n;
	cout << endl << "Value of n fibonachi number: " << fibonachiFunction(n) << endl;

	return 0;
}