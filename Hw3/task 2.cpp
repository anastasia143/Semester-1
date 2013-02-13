#include <iostream>
using namespace std;

bool flag = false;
void cycleFunction(int i, int cycle, int place)
{
	struct List
	{
		int value;
		List *next;
	};
	
	List *head = new List; // ����� ���������
	List *temp = head;
	
	for (int r = 1; r < cycle; r++) // ���������� ��������� �� 1 �� ���������� ������
	{
		temp->value = r;
		temp->next = new List;
		temp = temp->next;
	}

	temp->value = cycle;
	temp->next = head; // ������������ �����������

	temp = head; // ���� � ������ ������

	int count = cycle; // ������� ���������� ���������


	while (count > 1) // ������� ��������, ���� �� ��������� 1
	{
		if (i != 2) // ����������� �� �������, ������� �� k-���
		{
			for (int k = 1; k <= i - 2; k++)
			{
				temp = temp->next;
			}
		}
		List *toDelete = temp->next;
		temp->next = (temp->next)->next;
		temp = temp->next;
		delete toDelete;
		count--;
		
	}

	if ((temp->value) == place) // ����� �� ����� �������� ����������� ��������, ���� ��� ��������� � ����� ������
	{
		if (flag) 
		{
			cout << ",";
		}
		flag = true;
		cout << " " << i;
	}

	
	delete temp;

	
}

int main()
{
	int cycle = 10; // ������ ���������� ��������� � ������
	cout << "Enter number of cycle elements: ";
	cin >> cycle;

	int place = 1; // ������ �����, �� ������� �����
	cout << "Enter your place: ";
	cin >> place;

	cout << "YOU NEED k =";

	for (int t = 2; t <= cycle; t++) // ������� ��������� ��������� ��� k
	{
		cycleFunction(t, cycle, place);
	}

	if (flag == false) // ���� k �� �������
	{
		cout << " There is no k :(";
	}

	return 0;
}