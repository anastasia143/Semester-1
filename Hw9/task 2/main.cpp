#include <iostream>
#include "hash.h"
using namespace std;

int main()
{

    char str[100];
    for(int i = 0; i < 100; i++)
    {
        str[i] = '\0';
    }

    cout << "Enter str: ";
    cin >> str;

    char pattern[100];
    for (int i = 0; i < 100; i++)
    {
        pattern[i] = '\0';
    }
    cout << "Enter pattern: ";
    cin >> pattern;
    cout << endl;

    rabinCarp(str, pattern);
    
    return 0;
}
