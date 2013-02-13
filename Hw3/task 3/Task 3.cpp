#include <iostream>
#include "stack.h"
using namespace std;

int main()
{
	Stack stack1; // ���� ��� ������ � (

	cout << "Infix: ";
	char str[100] = "1+(2*3-4/5)*6-7+8"; // ���������
	cout << str << endl;
	cout << "Postfix: ";

	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		switch(str[i])
		{
		case ')':
			{
				while (!(stack1.top() == '(')) // ��������� ��� ����� �� ������ �� ( � ������� (
				{
					cout << stack1.top();
					stack1.pop();
				}
				stack1.pop();
				break;
			}
		case '(':
			{
				stack1.push(str[i]); // ��������� ( � ����
				break;
			}
		case '*':
		case '/':
			{
				if (stack1.empty()) // ���� ���� ����, ��������� ���� � ����
				{
					stack1.push(str[i]);
				}
				else if ((stack1.top() == '+') || (stack1.top() == '-') || (stack1.top() == '(')) 
				{
					stack1.push(str[i]);// ���� ������� � ����� �������� ������� �� ���������� - ��������� ���� � ����
				}
				else
				{
					while((stack1.top() == '*') || (stack1.top() == '/')) // ��������� �� ����� ��� �������� � ������ �����������
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
				if (stack1.empty()) // ���� ���� ����, ��������� ���� � ����
				{
					stack1.push(str[i]);
				}
				else if (stack1.top() == '(')
				{
					stack1.push(str[i]); // ���� ������� � ����� �������� ������� �� ���������� - ��������� ���� � ����
				}
				else
				{
					while((stack1.top() == '+') || (stack1.top() == '-') ||(stack1.top() == '*') || (stack1.top() == '/'))
					{
						cout << stack1.top(); // ��������� �� ����� ��� �������� � ������� ��� ������ �����������
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
				cout << str[i]; // ����� - �� �����
				break;
			}
		}
	}

while (!stack1.empty()) // ��������� �� ����� ���������� �����
{
	cout << stack1.top();
	stack1.pop();
}
	return 0;
}