#pragma once
#include <iostream>
using namespace std;

struct ListElement
{
    int value;
    ListElement *next;
};

struct List
{
    int size;
    ListElement *head;
    ListElement *tail;
};

List *createList();
void add(int a, List *list);
void remove(int b, List *list);
void print(List *list);
void destroy(List *list);
ListElement *createElement (int a, ListElement *pemp);
