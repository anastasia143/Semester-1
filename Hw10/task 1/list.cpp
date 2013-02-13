#include "list.h"
#include <iostream>
#include <stdlib.h>
#include "stdio.h"

using namespace std;

List *createList()
{
    List *result = new List;
    result->head = NULL;
    result->tail = NULL;
    result->size = 0;
    return result;
}

ListElement *createElement(int degree, int factor, ListElement *pemp)
{
    ListElement *temp = new ListElement;
    temp->degree = degree;
    temp->factor = factor;
    temp->next = pemp;
    return temp;
}

void add(int degree, int factor, List *list)
{
    if ((list->size) == 0)
    {
        ListElement *temp = createElement(degree, factor, list->head);
        (list->size)++;
        list->head = temp;
        list->tail = temp;
    }
    else
    {
        if (degree > list->head->degree)
        {
            ListElement *temp = createElement(degree, factor, list->head);
            (list->size)++;
            list->head = temp;
        }
        else if (degree < list->tail->degree)
        {
            ListElement *temp = createElement(degree, factor, NULL);
            (list->size)++;
            list->tail->next = temp;
            list->tail = temp;
        }
        else if(degree == list->head->degree)
            list->head->factor = list->head->factor + factor;
        else if(degree == list->tail->degree)
            list->tail->factor = list->tail->factor + factor;
        else
        {
            ListElement *temp = list->head;
            while((temp->next->degree > degree))
            {
                temp = temp->next;
            }
            if(temp->next->degree == degree)
                temp->next->factor = temp->next->factor + factor;
            else
            {
                ListElement *pemp = createElement(degree, factor, temp->next);
                (list->size)++;
                temp->next = pemp;
                temp = pemp->next;
            }
        }
    }
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
            cout << temp->degree << " " << temp->factor << endl;
            temp = temp->next;
        }
        cout << endl;
    }
}

void fillingList(List *list)
{
    int degree = -1;
    int factor = -1;
    scanf("%d%d", &degree, &factor);
    while ((degree != 0) || (factor != 0))
    {
        add(degree, factor, list);
        scanf("%d%d", &degree, &factor);
    }
}

bool equal(List* polynomialOne, List* polynomialTwo)
{
    if ((polynomialOne->size) != (polynomialTwo->size))
        return false;
    ListElement* temp = polynomialOne->head;
    ListElement* pemp = polynomialTwo->head;
    while(temp != NULL)
    {
        if ((temp->degree != pemp->degree) || (temp->factor != pemp->factor))
            return false;
        temp = temp->next;
        pemp = pemp->next;
    }
    return true;
}

int value(List* polynomial, int x)
{
    int result = 0;
    int degree = 1;
    ListElement* temp = polynomial->head;
    while(temp != NULL)
    {
        degree = 1;
        for(int i = 1; i <= temp->degree; i++)
            degree = degree * x;

        result = result + degree * temp->factor;

        temp = temp->next;
    }
    return result;
}

List* sum(List* polynomialOne, List* polynomialTwo)
{
    List* sum = polynomialOne;
    ListElement* temp = polynomialTwo->head;
    while(temp != NULL)
    {
        add(temp->degree, temp->factor, sum);
        temp = temp->next;
    }
    return sum;
}

void printSum(List* sum)
{

    ListElement* temp = sum->head;
    bool flag = false;
    while(temp != NULL)
    {

        if (temp->factor != 0)
        {
            // Коэффициенты
            if (temp->factor == -1)
                cout << "-";
            else if ((temp->factor > 0) && (flag))
                cout << "+" << temp->factor;
            else if (temp->factor != 1)
                cout << temp->factor;

            flag = true;

            // Степени

            if (temp->degree != 0)
            {
                cout << "x";
                if (temp->degree != 1)
                    cout << "^" << temp->degree;
            }
        }

        temp = temp->next;
    }
    cout << endl << endl;
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


