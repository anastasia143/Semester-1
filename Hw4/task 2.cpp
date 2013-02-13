#include <iostream>
using namespace std;

int main()
{
	int n = 2;
	while (n % 2 == 0)
	{
		cout << "Enter n: ";
		cin >> n;
		if (n % 2 == 0)
		{
			cout << "You entered even number. Try again." << endl;
		}
	}


	int a[100][100];

	int i;
	int j;
	int k = 0;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
		{
			k++;
			a[i][j] = k;
		}



	int count = 0; // ѕеременна€ дл€ количества поворотов
	int coutNumbers = 0; // ѕеременна€ дл€ количества выводимых чисел за раз

	i = n / 2 + 1; // —ередина массива
	j = n / 2 + 1;


	cout << a[i][j] << " ";
	while (count < n*2 - 1)
	{
		if (coutNumbers != n - 1) // ”величиваем через раз, если это не последние 3 прохода
		{
			if (count % 2 == 0)
			{
				coutNumbers++;
			}
		}
		count++;
		int direction = count % 4; // „ередование направлений

		switch(direction) // ћен€ем координаты, учитыва€ направление
	{
	case 0:
		{
			
			for (int k = 1; k <= coutNumbers; k++)
			{
				cout << a[--i][j] << " ";

			}
			break;
		}
	case 1:
		{
			for (int k = 1; k <= coutNumbers; k++)
			{
				cout << a[i][++j] << " ";
			}
			break;
		}
	case 2:
		{
			for (int k = 1; k <= coutNumbers; k++)
			{
				cout << a[++i][j] << " ";
			}
			break;
		}
	case 3:
		{
			for (int k = 1; k <= coutNumbers; k++)
			{
				cout << a[i][--j] << " ";
			}
			break;
		}
	}

	}

	return 0;
}