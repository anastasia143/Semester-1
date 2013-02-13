#include <iostream>
using namespace std;

int main()
{
	bool flag = true;
	
	char s1[100];
	cout << "Enter the first string: ";
	cin >> s1;

	char s2[100];
	cout << "Enter the second string: ";
	cin >> s2;

	int len1 = strlen(s1);
	int len2 = strlen(s2);

	if (len1 == len2)
	{
		for (int i = 0; i < len1 - 1; i++) // Сортировка первой строки
			for (int k = len1 - 2; k >= i; k--)
			{
				if (s1[k] > s1[k+1])
				{
					swap(s1[k], s1[k+1]);
				}
			}

		for (i = 0; i < len2 - 1; i++) // Сортировка второй строки
			for (int k = len2 - 2; k >= i; k--)
			{
				if (s2[k] > s2[k+1])
				{
					swap(s2[k], s2[k+1]);
				}
			}

		for (i = 0; i < len1; i++) // Ищем несовпадения
		{
			if (s1[i] != s2[i])
			{
				flag = false;
			}
		}

	}
	else
	{
		flag = false;
	}
	
	if (flag)
	{
		cout << "Yes, you can get the second string";
	}
	else
	{
		cout << "No, you can't get the second string";
	}

	return 0;
}
