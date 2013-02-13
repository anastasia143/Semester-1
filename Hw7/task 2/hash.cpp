#include <iostream>
#include <stdlib.h>
#include <cstring>
#include "stdio.h"
#include "hash.h"
using namespace std;

ListElement* createListElement(char str[])
{

    ListElement *temp = new ListElement;
    for (int i = 0; i < 100; i++)
    {
        temp->value[i] = '\0';
    }
    temp->next = NULL;
    int lenStr = strlen(str);
    for (int k = 0; k < lenStr; k++)
    {
        temp->value[k] = str[k];
    }
    temp->count = 1;

    return temp;
}

List* createList()
{
    List* temp = new List;
    temp->count = 0;
    temp->head = NULL;
    return temp;
}

int wordKey(char str[]) // Хэш-ключ слова
{
    int len = strlen(str);
    int long long result = 50;
    int long long degree = 31;
    for (int i = 0; i < len; i++)
    {
        degree = degree*degree;
        result = result + ((int)str[i])*degree;
    }
    if (result < 0)
    {
        result = -result;
    }
    int result2 = result % 29;
    return (result2);
}

Table* hashCreator(FILE* file) // Главная хэш-функция (выделение слов для занесения в таблицу, обнуление массива)
{
    Table* table = new Table;
    for (int i = 0; i < 30; i++)
    {
        table->hashArray[i].count = 0;
        table->hashArray[i].head = NULL;
    }
    while (!feof(file))
    {
        char c;
        char word[100];
        for (int i = 0; i < 100; i++)
        {
            word[i] = '\0';
        }
        int count = -1;
        c = fgetc(file);
        while ((c != ' ') && (c != '\t') && (c != '\n') && (!feof(file)) && (c != ',') && (c != '.') && (c != ';'))
        {
            count++;
            word[count] = c;
            c = fgetc(file);

        }
        pushWordInTable(word, table);
        int wordLen = strlen(word);
        for (int i = 0; i < wordLen; i++)
        {
            word[i] = '\0';
        }
    }
    return table;
}

void pushWordInTable(char word[], Table *table) // Занесение слова в таблицу
{
    int index = wordKey(word);
    if (table->hashArray[index].count == 0)
    {
        table->hashArray[index].count = 1;
        table->hashArray[index].head = createListElement(word);
    }
    else
    {
        table->hashArray[index].count++;
        ListElement *temp = table->hashArray[index].head;
        while (temp != NULL)
        {
            bool flag = false;

            int wordLen = strlen(word);
            int tempLen = strlen(temp->value);
            if (wordLen == tempLen)
            {
                flag = true;
                for (int k = 0; k < wordLen; k++)
                {
                    if (temp->value[k] != word[k])
                    {
                        flag = false;
                    }
                }
            }

            if (flag)
            {
                (temp->count)++;
                return;
            }
            if (temp->next != NULL)
            {
                temp = temp->next;
            }
            else
            {
                break;
            }
        }
        ListElement *pemp = createListElement(word);
        temp->next = pemp;
    }
}


void printWord(Table* table)
{
    for (int i = 0; i < 30; i++)
    {
        if (table->hashArray[i].head != NULL)
        {
            ListElement* temp = table->hashArray[i].head;
            while (temp->next != NULL)
            {
                int tempLen = strlen(temp->value);
                for (int i = 0; i < tempLen; i++)
                {
                    cout << temp->value[i];
                }

                cout << " " << temp->count << endl;
                temp = temp->next;
            }
            cout << temp->value << " " << temp->count << endl;
        }
    }
}

void deleteFunction(Table *table)
{
    for (int i = 0; i < 30; i++)
    {
        if (table->hashArray[i].head != NULL)
        {
            ListElement* temp = table->hashArray[i].head;
            ListElement* pemp = table->hashArray[i].head;
            while (temp->next != NULL)
            {
                temp = pemp;
                pemp = temp->next;
                delete temp;
            }
        }
    }
    delete table;
}
