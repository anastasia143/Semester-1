#include <iostream>
using namespace std;

int degreeFunction(int b, int m)
{
	int result = 1;
	while(m > 0)
	{
		if (m % 2 == 1)
		{
			result = result * b;
			m--;
		}
		else
		{
			b = b * b;
			m = m / 2;
		}
	}
	return result;
}

int main()
{
	int a;
	cout << "Enter number: ";
	cin >> a;

	int n;
	cout << "Enter degree: ";
	cin >> n;

	cout << "Result: " << degreeFunction(a, n);

	return 0;
}