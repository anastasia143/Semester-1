#include "floatAutomatic.h"
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    FILE* file = fopen("number.txt", "r");

    bool result = floatAutomatic(file);

    if (result)
        cout << endl << "String in file is a number.";
    else
        cout << endl << "String in file is NOT a number.";

    fclose(file);
    
    return 0;
}
