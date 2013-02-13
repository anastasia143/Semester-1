#include <iostream>
using namespace std;

int main()
{
	char s[200];
	char s2[200];
	int count = 0;
	
	cout << "Enter s: ";
	cin >> s;

	cout << "Enter s2: ";
	cin >> s2;
	bool flag = true;

	for (int i = 0; i <= strlen(s) - strlen(s2); i++)
	{
		for (int g = 0; g <= strlen(s2) - 1; g++)
		{
			if (s[i + g] != s2[g])
			{
				flag = false;
			};

		}
		if (flag == true)
		{
			count++;
		}
		flag = true;
	}

	cout << "Number s2 in s: " << count;

	return 0;
}