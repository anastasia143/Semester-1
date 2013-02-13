#pragma once

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
    List hashArray[30];
};

List* createList();
ListElement* createListElement(char str[]);
int wordKey(char str[]);
Table* hashCreator(FILE* file);
void pushWordInTable(char word[], Table* table);
void printWord(Table* table);
void deleteFunction(Table* table);
