#include <iostream>
using namespace std;

int main()
{
	float a = 1;
	int n = 1;

	cout << "Vvedite chislo: ";
	cin >> a;
	cout << "Vvedite stepen: ";
	cin >> n;

    float a2 = a;
	for (int i = 1; i < n; i++)
	{
		a2 = a2 * a;
	}

	cout << "a v stepeni n: " << a2;


	return 0;
}