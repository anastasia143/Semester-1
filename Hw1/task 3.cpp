#include <iostream>
using namespace std;

int main()
{
	int a[300];
	int m = 1;
	int n = 1;
	int i = 1;


	cout << "Enter m: ";
	cin >> m;
	cout << "Enter n: ";
	cin >> n;

	cout << "Enter " << n + m << " elements of array: ";
	for (i = 1; i <= n + m; i++)
	{
		cin >> a[i];
	}

	for (i = 1; i <= m; i++)
	{
		a[m + n + i] = a[i];
		a[i] = 0;

	}

	cout << "Result: ";
	for (i = m + 1; i <= n + m + m; i++) 
	{
		cout << a[i] << " ";
	}

	return 0;
}