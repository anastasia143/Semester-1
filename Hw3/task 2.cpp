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
	
	List *head = new List; // Новая структура
	List *temp = head;
	
	for (int r = 1; r < cycle; r++) // Заполнение структуры от 1 до последнего номера
	{
		temp->value = r;
		temp->next = new List;
		temp = temp->next;
	}

	temp->value = cycle;
	temp->next = head; // Обеспечиваем цикличность

	temp = head; // Идем в начало списка

	int count = cycle; // Счетчик оставшихся элементов


	while (count > 1) // Удаляем элементы, пока не останется 1
	{
		if (i != 2) // Перемещение на элемент, стоящий до k-ого
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

	if ((temp->value) == place) // Вывод на экран значения оставшегося элемента, если оно совпадает с нашим местом
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
	int cycle = 10; // Вводим количество элементов в списке
	cout << "Enter number of cycle elements: ";
	cin >> cycle;

	int place = 1; // Вводим место, на котором стоим
	cout << "Enter your place: ";
	cin >> place;

	cout << "YOU NEED k =";

	for (int t = 2; t <= cycle; t++) // Функция возможных вариантов для k
	{
		cycleFunction(t, cycle, place);
	}

	if (flag == false) // Если k не нашлось
	{
		cout << " There is no k :(";
	}

	return 0;
}