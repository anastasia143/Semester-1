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


bool Stack::empty() // Если количество элементов в стеке = 0 - возвращаем true
{
	return (count == 0);
}

void Stack::pop() // Обнуляем последний элемент массива, -1 к количеству элементов
{
	array[count] = NULL;
	count--;
}

char Stack::top() // Возвращаем значение последнего элемента
{
	return array[count];
}

void Stack::push(char k) // +1 к количеству элементов, записываем новый элемент в массив
{
	count++;
	array[count] = k;
}

