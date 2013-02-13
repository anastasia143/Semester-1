#include <iostream>
#include "string.h"

using namespace std;

int main()
{
	
	char a[200];
	bool flag = 1;

	cout << "Enter a string: ";
	cin >> a;

	int len = strlen(a);

	for (int i = 0; i < (len / 2); i++)
	{
		if (a[i] != (a[len - i - 1]))
		{
			flag = 0;
		};
	}

	if (flag == 0)
	{
		cout << "Not polindrom";
	} else 
	{
		cout << "Polindrom";
	};

	return 0;
}