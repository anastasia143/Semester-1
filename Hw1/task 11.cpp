#include <iostream>
using namespace std;

void quickSort(int i, int j, int n[])
{
	int a = i;
	int b = j;
	int x = n[(i + j) / 2];

	while (a <= b)
	{

		while (n[a] < x)
		{
			a++; 
		}
		while (n[b] > x)
		{
			b--;
		}
		if (a <= b)
		{
		swap(n[b], n[a]);
		a++;
		b--;
		}

	}

	if (a < j)
	{
		quickSort(a, j, n);
	}

	if (i < b)
	{
		quickSort(i, b, n);
	}
}

int main()
{
	int size = 1;
	cout << "Enter size of array: ";
	cin >> size;

	int k[100];

	cout << "Enter "<< size << " elements of array: ";

	for (int y = 1; y <= size; y++)
	{
		cin >> k[y];
	}

	quickSort(1, size, k);

	cout << "Result: ";
	for (y = 1; y <= size; y++)
	{
		cout << k[y]; cout << " ";
	}
	return 0;
}