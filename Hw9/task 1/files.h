#pragma once
#include <stdio.h>

void filesProcessing(FILE* file1, FILE* file2, FILE* file3);
int wordKey(char str[]);

struct ListElement
{
    char value[100];
    ListElement* next;
    int count;
};

struct List
{
    ListElement* head;
    int count;
};

struct Table
{
    List hashArray[3559];
};

void pushStringInTable(char word[], Table *table);
void deleteFunction(Table *table);
Table* hashCreator(FILE* file1);
List* createList();
ListElement* createListElement(char str[]);
bool stringSearch(Table* table, char str[]);
