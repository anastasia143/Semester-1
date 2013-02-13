#include "hash.h"
#include <iostream>
#include <string.h>
using namespace std;

unsigned long long int hash(char str[], int count)
{
    unsigned long long int result = 0;
    unsigned long long int degree = 1;

    for (int i = count - 1; i >= 0; i--)
    {
        result = (result + (int)str[i] * degree);
        degree = (degree * 2) % 2593;
    }
    return result;
}

unsigned long long int rehash(char str[], int start, int count, int previousHash)
{
    unsigned long long int degree = 1;
    for (int i = 0; i < count - 1; i++)
        degree = (degree * 2) % 2593;
    return (((previousHash - (int)str[start - 1] * degree)) * 2  + (int)str[count + start - 1]);
}

bool compare(char sample [], char pattern[])
{
    int patternLen = strlen(pattern);
    int sampleLen = strlen(sample);

    if (sampleLen != patternLen)
        return false;

    for(int k = 0; k < patternLen; k++)
    {
        if (sample[k] != pattern[k])
            {
                return false;
            }
    }
    return true;
}

void rabinCarp(char str[], char pattern[])
{
    int strLen = strlen(str);
    int patternLen = strlen(pattern);
    unsigned long long int patternKey = hash(pattern, strlen(pattern));
    if (strLen < patternLen)
    {
        cout << "Occurance is impossible - pattern has more symbols than string.";
        return;
    }
    cout << "A pattern begins with the symbols: ";

    bool flag = true;
    int count = 0;

    char sample[100];
    int j;
    for (j = 0; j < 100; j++)
    {
        sample[j] = '\0';
    }
    for(j = 0; j < patternLen; j++)
    {
        sample[j] = str[j];
    }
    unsigned long long int sampleKey = hash(sample, strlen(sample));

    if (sampleKey == patternKey)
    {
        if (compare(sample, pattern))
        {
            cout << 1 << " ";
            count++;
        }
    }

    for(int i = 1; i <= strLen - patternLen; i++)
    {
        for (j = 0; j < 100; j++)
        {
            sample[j] = '\0';
        }

        for(j = 0; j < patternLen; j++)
        {
            sample[j] = str[i + j];
        }

        sampleKey = rehash(str, i, patternLen, sampleKey);

        if (sampleKey == patternKey)
        {
            if (compare(sample, pattern))
            {
                cout << i + 1 << " ";
                count++;
            }
        }
    }
    if (count == 0)
    {
        cout << "There is no pattern in the string.";
    }
    else
    {
        cout << endl << "Count of occurances: " << count; // Количество вхождений
    }
}

