#include <iostream>
using namespace std;

int main()
{
	struct Array // �������� ���������
	{
		int value;
		Array *next;
	};

	Array *head = new Array; // ������ �������
	Array *temp = head; // ��������� ��� ���������� ��������, � ������ ��������� ��������� � ������ �������

	temp->value = 9; // ������� ������ �� 4 ���������
	int max = temp->value; // MAX = ������ ������� �������
	temp->next = new Array;
	temp = temp->next;

	temp->value = 8;
	temp->next = new Array;
	temp = temp->next;

	temp->value = 8;
	temp->next = new Array;
	temp = temp->next;

	temp->value = 1;
	temp->next = NULL;


	int max2 = 100000000;
	int count = 0;
	bool flag = false; // ���� ��� �����������, ����������� �� max ����� ������ 1 ����
	while (!flag)
	{
		temp = head; // �������� �������� ������� � ������
		while (temp != NULL) // � ������� ���� ������������, �� ������� ��� ������������� ������������
		{
			
			if (((temp->value) > max) && ((temp->value) < max2)) // ��������� ����� max ������� - �������� �������
			{
				max = temp->value;
				count = 0;
			}
			
			if ((temp->value) == max) // ��������� ��������
			{
				count++;
			}
			temp = temp->next; // ������ �� ��������� ������� �������
		}

		if (count > 1) // ���� ��������� max ������� ������ 1 ���� - ��������� ����
		{
			flag = true;
		}
		else // ���� ��� - ���������� 
		{
			flag = false;
			max2 = max;
			max = -1000000;
		}
	}

	cout << "Max repeat element: " << max << endl;

	temp = head;
	while (temp != NULL)
	{
		temp = head->next;
		delete head;
		head = temp;
	}




	return 0;
}
