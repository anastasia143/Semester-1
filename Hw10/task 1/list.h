#pragma once
#include <iostream>
using namespace std;

struct ListElement
{
    int degree;
    int factor;
    ListElement *next;
};

struct List
{
    int size;
    ListElement *head;
    ListElement *tail;
};

List *createList();
void add(int degree, int factor, List *list);
ListElement *createElement(int degree, int factor, ListElement *pemp);
void fillingList(List *list);
void print(List *list);
void destroy(List *list);

bool equal(List* polynomialOne, List* polynomialTwo);
int value(List* polynomial, int x);
List* sum(List* polynomialOne, List* polynomialTwo);
void printSum(List* sum);
