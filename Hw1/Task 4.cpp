#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	
	int a[27];
	int i = 0;

	for (i = 0; i <= 27; ++i)
	{
		a[i] = 0;
	}


	for (i = 0; i <= 9; ++i)
	{
		for (int h = 0; h <= 9; ++h)
		{
			for (int e = 0; e <= 9; ++e)
			{
				a[i + h + e]++;
			}
		}
	}

	int sum = 0;
	for (i = 0; i <= 27; ++i)
	{
		sum = sum + a[i]*a[i];
	}

	cout << "Number of happy tickets: " << sum;




	return 0;
}