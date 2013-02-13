#include <iostream>
using namespace std;

int main()
{
	char s[100];
	int open = 0;

	cout << "Enter a string: ";
	cin >> s;

	int len = strlen(s);

	for (int i = 0; i < len; i++)
	{
		if (s[i] == '(')
		{
			open++;
		}

		if (s[i] == ')')
		{
			open--;
			if (open == -1)
			{
				break;
			}
		}
	}

	if (open == 0)
	{
		cout << "Right";
	}
	else
	{
		cout << "Wrong";
	}

	return 0;
}