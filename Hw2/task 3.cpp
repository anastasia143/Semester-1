#include <iostream>
using namespace std;

int a[10000];
void sumFunction(int n, int b, int pos) // n - �����, ������� ���������; b - ���������� � �����; pos - ������� � �������
{
	int choise; // ������������ �������������� ��������� 2+1+2 � 2+2+1
	int i = 1;
	if (n > 0) // �������� �� ��� ���, ���� ����� ��������� n �� ����� ��������
	{
		for (i = 1; i <= b; i++)
		{
			a[pos] = i;
			if ((n - i) < i)
			{
				choise = n - i; // �������� ������� �������� ��� ������� �������, ����� ��������� ���������� � ������� ��������
			} // ����� ������� ��� �������� ���� � ������ ������������ ���������
			else
			{
				choise = i;
			}
			sumFunction(n - i, choise, pos + 1);
		}
	}
	else // ��� ������ ��������� ��������� - ������� ������ �� ����� �� ����������� �������
	{
		for (i = 1; i < pos - 1; i++)
		{
			cout << a[i] << "+";
		}
		cout << a[pos - 1] << endl;
	}
}

int main()
{
	int n = 2;
	cout << "Enter n: ";
	cin >> n;

	sumFunction(n, n - 1, 1); // ���� � �������
	return 0;
}