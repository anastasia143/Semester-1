#include <iostream>
using namespace std;

// Вычисление факториала рекурсивно
int Factorial (int k)
{
	if (k > 1) 
	{
		return k * Factorial(k - 1);
	}
	else 
	{
		return 1;
	}
}

int main()
{
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
		cout << "Factorial: " << Factorial (n);
	}

	return 0;
}