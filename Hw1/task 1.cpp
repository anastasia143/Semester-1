#include <iostream>
using namespace std;

int main()
{
	float x;
	cout << "Vvedite x: ";
	cin >> x;
	float r = x * x;

	float result = r * (r + x + 1) + x + 1;
	cout << "x^4 + x^3 + x^2 + x + 1 = " << result;

	return 0;
}