#include <iostream>
using namespace std;

template< class T > // ������
pyramideSort(T a[], int length, int k) // �������(������, ����� �������, ������������ �������)
{
	int newelement = a[k]; // ���������� ������������ �������
	int child;
	while (k <= (length / 2)) // ��������� ������ �������� ��������
	{
		child = 2 * k;
		if ((child < length) && (a[child + 1] > a[child])) // ���� ����� ����������� �������
		{
			child++;
		}
		if (newelement >= a[child])
		{
			break;
		}
		a[k] = a[child]; // ������ ������� ����������� ������� � ������� �������
		k = child;
	}
	a[k] = newelement; // ��������� ������������ ������� �� ����� �����

}

int main ()
{
	int size = 6;
	int a[6] = {0, 8, 4, 6, 2, 7}; // �������� ������
	cout << "Array: ";
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	
	
	for (i = size / 2; i >= 0; --i) // ���������� �������� (����� ������ ������ �����, ������ ��� �� �����)
	{
		pyramideSort(a, 4, i);
	}
	
	for (i = size - 1; i > 0; --i) // ���������� ������ �������
	{
		int temp = a[i];
		a[i] = a[0];
		a[0] = temp;
		pyramideSort(a, i - 1, 0);

	}

	cout << endl << "New array: "; // ����� ������

		for (i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}


	return 0;
}