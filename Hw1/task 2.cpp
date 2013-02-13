#include <iostream>
using namespace std;

int main()
{
	int a = 1; int b = 1;
	cout << "Enter a: ";
	cin >> a;

	cout << "Enter b: ";
	cin >> b;

	int result = 0;

	while (a >= b)
	{
		a = a - b;
		result++;
	};
	cout << "Result: " << result;



	return 0;
}