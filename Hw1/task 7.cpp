#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int n;
	cout << "Enter a number: ";
	cin >> n;
	bool flag = true;

	for (int i = 2; i < n; i++)
	{
		for (int c = 2; c < i; c++)
		{
			if (fmod(i, c) == 0) 
			{
				flag = false;
			}
		}
		if (flag == true) 
		{
			cout << i << " ";
		}
		flag = true;
	}

	return 0;
}