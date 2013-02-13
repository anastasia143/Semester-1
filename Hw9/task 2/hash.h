#pragma once
#include <iostream>

void rabinCarp(char str[], char pattern[]);
unsigned long long int hash(char str[], int count);
unsigned long long int rehash(char str[], int start, int count, int previousHash);
bool compare(char sample [], char pattern[]);
