#include <iostream>
using namespace std;

int main()
{
	struct Array // Создание структуры
	{
		int value;
		Array *next;
	};

	Array *head = new Array; // Начало массива
	Array *temp = head; // Указатель для следующего элемента, в начале программы находится в начале массива

	temp->value = 9; // Создаем массив из 4 элементов
	int max = temp->value; // MAX = первый элемент массива
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
	bool flag = false; // Флаг для определения, встретилось ли max число больше 1 раза
	while (!flag)
	{
		temp = head; // Начинаем просмотр массива с начала
		while (temp != NULL) // В массиве ищем максимальный, но меньший уже просмотренных максимальных
		{
			
			if (((temp->value) > max) && ((temp->value) < max2)) // Встретили новый max элемент - обнулили счетчик
			{
				max = temp->value;
				count = 0;
			}
			
			if ((temp->value) == max) // Инкремент счетчика
			{
				count++;
			}
			temp = temp->next; // Ссылка на следующий элемент массива
		}

		if (count > 1) // Если встретили max элемент больше 1 раза - завершаем цикл
		{
			flag = true;
		}
		else // Если нет - продолжаем 
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
