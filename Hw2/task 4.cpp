#include <iostream>
using namespace std;

int main()
{
	int n = 2;
	cout << "Enter n more than 1: ";
	cin >> n;
	
	cout << "Irreducible fractions: ";
	bool flag;

	for (int i = 2; i <= n; i++)
	{
		for (int k = 1; k < i; k++)
		{
			for (int g = 2; g <= k; g++)
			{
				if ((i % g == 0) && (k % g == 0))
					{
						flag = true;
					}
			}
			if (!(flag) || (k == 1))
			{
				cout << k << "/" << i << " ";
			}
			flag = false;

		}
	}

	return 0;
}