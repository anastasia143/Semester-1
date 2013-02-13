#include <iostream>
using namespace std;

// Вычисление факториала итеративно
long double result;

int main()
{
	double long fact = 1;
	int n = 0;
	cout << "Enter a number: ";
	cin >> n;

	if (n < 0)
	{
		cout << "Error!";
	}
	else if (n == 0)
	{
		cout << 1;
	}
	else 
	{
		for (int i = 1; i <= n; i++)
		{
			fact = fact * i;
		}
		cout << "Factorial: " << fact;
	}


	return 0;
}