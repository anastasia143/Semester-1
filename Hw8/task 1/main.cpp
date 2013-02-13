#include <iostream>
#include "bubbleSort.h"
using namespace std;

void test()
{
    int *a = new int[10];
    int size = 10;
    a[0] = 5;
    a[1] = 6;
    a[2] = 3;
    a[3] = 0;
    a[4] = -1;
    a[5] = -100;
    a[6] = 3;
    a[7] = 384;
    a[8] = 88;
    a[9] = 42;


    cout << "Array before sort: ";
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    bubbleSort(a, size);
    cout << endl << "Array after sort: ";
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }

    delete [] a;
}

int main()
{
    test();
    return 0;
}
