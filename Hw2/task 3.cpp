#include <iostream>
using namespace std;

int a[10000];
void sumFunction(int n, int b, int pos) // n - число, которое разбиваем; b - наибольшее в сумме; pos - позиция в массиве
{
	int choise; // Обеспечиваем равнозначность вариантов 2+1+2 и 2+2+1
	int i = 1;
	if (n > 0) // РЕКУРСИЯ до тех пор, пока можем уменьшать n на новых позициях
	{
		for (i = 1; i <= b; i++)
		{
			a[pos] = i;
			if ((n - i) < i)
			{
				choise = n - i; // Выбераем меньшее значение для верхней границы, чтобы слагаемые выводились в порядке убывания
			} // Иначе получим все варианты сумм с разной расстановкой слагаемых
			else
			{
				choise = i;
			}
			sumFunction(n - i, choise, pos + 1);
		}
	}
	else // Как только закончили разбиение - выводим массив на экран до заполненной позиции
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

	sumFunction(n, n - 1, 1); // Вход в функцию
	return 0;
}