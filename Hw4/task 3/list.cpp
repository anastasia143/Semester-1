#include "list.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

List *createList()
{
    List *result = new List;
    result->head = NULL;
    result->tail = NULL;
    result->size = 0;
    return result;
}

ListElement *createElement(int a, ListElement *pemp)
{
    ListElement *temp = new ListElement;
    temp->value = a;
    temp->next = pemp;
    return temp;
}

void add(int a, List *list)
{
    if ((list->size) == 0)
    {
        ListElement *temp = createElement(a, list->head);
        list->head = temp;
        list->tail = temp;
    }
    else
    {
        if (a <= list->head->value)
        {
            ListElement *temp = createElement(a, list->head);
            list->head = temp;
        }
        else if (a >= list->tail->value)
        {
            ListElement *temp = createElement(a, NULL);
            list->tail->next = temp;
            list->tail = temp;
        }
        else
        {
            ListElement *temp = list->head;
            while((temp->next->value < a))
            {
                temp = temp->next;
            }
            ListElement *pemp = createElement(a, temp->next);
            temp->next = pemp;
            temp = pemp->next;
        }

    }
    (list->size)++;
    cout << "You added the element" << endl;
}

void remove(int b, List *list)
{
    if ((list->size) == 0)
    {
        cout << "List is empty" << endl;
        return;
    }
    while (list->head->value == b)
    {
        if (list->size != 1)
        {
            ListElement *pemp = list->head;
            list->head = list->head->next;
            delete pemp;
            (list->size)--;
        }
        else
        {
            ListElement *pemp = list->head;
            list->head = NULL;
            delete pemp;
            list->size = 0;
            break;
        }
    }
    if (list->size != 0)
    {
        ListElement *temp = list->head;///
        if (list->size != 1)
        {
            while (temp->next != NULL)
            {
                if (temp->next->value == b)
                {
                    if (temp->next == list->tail)
                    {
                        list->tail = temp;
                    }
                    ListElement *pemp = temp->next;
                    temp->next = temp->next->next;
                    delete pemp;
                    (list->size)--;
                }
                else
                {
                        temp = temp->next;
                }
            }
        }
    }
    cout << "You removed the element" << endl;
}

void print(List *list)
{
    if (list->size == 0)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        ListElement *temp = list->head;
        while (temp != NULL)
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

void destroy(List *list)
{
    ListElement *temp = list->head;
    while(temp != NULL)
    {
        temp = list->head->next;
        delete list->head;
        list->head = temp;
    }
    delete list;
}
