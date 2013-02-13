#include <iostream>
#include "stack.h"
using namespace std;

int main()
{
	Stack stack1; // Стек для знаков и (

	cout << "Infix: ";
	char str[100] = "1+(2*3-4/5)*6-7+8"; // Выражение
	cout << str << endl;
	cout << "Postfix: ";

	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		switch(str[i])
		{
		case ')':
			{
				while (!(stack1.top() == '(')) // Вытесняем все знаки из строки до ( и удаляем (
				{
					cout << stack1.top();
					stack1.pop();
				}
				stack1.pop();
				break;
			}
		case '(':
			{
				stack1.push(str[i]); // Добавляем ( в стек
				break;
			}
		case '*':
		case '/':
			{
				if (stack1.empty()) // Если стек пуст, добавляем знак в стек
				{
					stack1.push(str[i]);
				}
				else if ((stack1.top() == '+') || (stack1.top() == '-') || (stack1.top() == '(')) 
				{
					stack1.push(str[i]);// Если наверху в стеке операции меньшие по приоритету - добавляем знак в стек
				}
				else
				{
					while((stack1.top() == '*') || (stack1.top() == '/')) // Вытесняем из стека все операции с равным приоритетом
					{
						cout << stack1.top();
						stack1.pop();
						if (stack1.empty())
						{
							break;
						}
					}
					stack1.push(str[i]);
				}
				break;
			}
		case '+':
		case '-':
			{
				if (stack1.empty()) // Если стек пуст, добавляем знак в стек
				{
					stack1.push(str[i]);
				}
				else if (stack1.top() == '(')
				{
					stack1.push(str[i]); // Если наверху в стеке операции меньшие по приоритету - добавляем знак в стек
				}
				else
				{
					while((stack1.top() == '+') || (stack1.top() == '-') ||(stack1.top() == '*') || (stack1.top() == '/'))
					{
						cout << stack1.top(); // Вытесняем из стека все операции с большим или равным приоритетом
						stack1.pop();
						if (stack1.empty())
						{
							break;
						}
					}
					stack1.push(str[i]);
				}
				break;

			}
		default:
			{
				cout << str[i]; // Цифры - на вывод
				break;
			}
		}
	}

while (!stack1.empty()) // Вытесняем из стека оставшиеся знаки
{
	cout << stack1.top();
	stack1.pop();
}
	return 0;
}