#include <iostream>
using namespace std;

class Stack
	{
		char array[1000];
		int count;
public:
	Stack()
	{
		count = 0;
	}
	bool empty();
	void pop();
	char top();
	void push(char k);
	};


bool Stack::empty() // ���� ���������� ��������� � ����� = 0 - ���������� true
{
	return (count == 0);
}

void Stack::pop() // �������� ��������� ������� �������, -1 � ���������� ���������
{
	array[count] = NULL;
	count--;
}

char Stack::top() // ���������� �������� ���������� ��������
{
	return array[count];
}

void Stack::push(char k) // +1 � ���������� ���������, ���������� ����� ������� � ������
{
	count++;
	array[count] = k;
}

