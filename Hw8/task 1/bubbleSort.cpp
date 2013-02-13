#include "bubbleSort.h"
#include <iostream>
using namespace std;

void bubbleSort(int *a, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int k = 0; k < size - i; k++)
        {
            if (a[k] > a[k + 1])
            {
                int temp = a[k];
                a[k] = a [k + 1];
                a[k + 1] = temp;
            }
        }
    }

}
