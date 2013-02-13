#include "stdio.h"
#include <string.h>
#include "files.h"
#include <iostream>
int wordKey(char str[]) // Хэш-ключ строки
{
    int len = strlen(str);
    int long long result = 29;
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
    int result2 = result % 3559;
    return (result2);
}

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

void filesProcessing(FILE* file1, FILE* file2, FILE* file3)
{
    Table *table = hashCreator(file1);
    char str[1000];
    while (!feof(file2))
    {
        for (int i = 0; i < 1000; i++)
        {
            str[i] = '\0';
        }
        fgets(str, 1000, file2);
        if (stringSearch(table, str))
        {
            int strLen = strlen(str);
            fwrite(str, sizeof(char), strLen, file3);
        }
    }
    deleteFunction(table);
    printf("Rows successfully added.");
}

void pushStringInTable(char word[], Table *table) // Занесение строки в таблицу
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

Table* hashCreator(FILE* file1) // Главная хэш-функция
{
    Table* table = new Table;
    for (int i = 0; i < 30; i++)
    {
        table->hashArray[i].count = 0;
        table->hashArray[i].head = NULL;
    }
    while (!feof(file1))
    {
        char str[1000];
        for (int i = 0; i < 1000; i++)
        {
            str[i] = '\0';
        }
        fgets(str, 1000, file1);
        pushStringInTable(str, table);
    }
    return table;
}

bool stringSearch(Table* table, char str[])
{
    int strKey = wordKey(str);
    if (table->hashArray[strKey].head != NULL)
    {
        ListElement* temp = table->hashArray[strKey].head;
        int strLen = strlen(str);
        while (temp != NULL)
        {
            int strArrayLen = strlen(temp->value);
            if (strLen == strArrayLen)
            {
                for(int i = 0; i < strLen; i++)
                {
                    if (str[i] != temp->value[i])
                    {
                        return false;
                    }
                    return true;
                }
            }
            temp = temp->next;
        }
    }
    return false;
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

