#include <iostream>
using namespace std;

template< class T > // Шаблон
pyramideSort(T a[], int length, int k) // Функция(массив, длина массива, просеиваемый элемент)
{
	int newelement = a[k]; // Запоминаем просеиваемый элемент
	int child;
	while (k <= (length / 2)) // Сортируем первую половину пирамиды
	{
		child = 2 * k;
		if ((child < length) && (a[child + 1] > a[child])) // Ищем номер наибольшего ребенка
		{
			child++;
		}
		if (newelement >= a[child])
		{
			break;
		}
		a[k] = a[child]; // Меняем местами наибольшего ребенка и текущий элемент
		k = child;
	}
	a[k] = newelement; // Переносим просеиваемый элемент на новое место

}

int main ()
{
	int size = 6;
	int a[6] = {0, 8, 4, 6, 2, 7}; // ИСХОДНЫЙ МАССИВ
	cout << "Array: ";
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	
	
	for (i = size / 2; i >= 0; --i) // Построение пирамиды (стоим только первую часть, вторая уже на месте)
	{
		pyramideSort(a, 4, i);
	}
	
	for (i = size - 1; i > 0; --i) // Просеиваем каждый элемент
	{
		int temp = a[i];
		a[i] = a[0];
		a[0] = temp;
		pyramideSort(a, i - 1, 0);

	}

	cout << endl << "New array: "; // НОВЫЙ МАССИВ

		for (i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}


	return 0;
}