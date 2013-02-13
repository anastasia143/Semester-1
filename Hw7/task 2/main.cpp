#include <iostream>
#include "hash.h"
#include "stdio.h"
#include <cstring>
using namespace std;

int main()
{
    char str[100];
    FILE* file = fopen("file.txt", "r+");
    Table* table = hashCreator(file);
    printWord(table);
    deleteFunction(table);

    return 0;
}
