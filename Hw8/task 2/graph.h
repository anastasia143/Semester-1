#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;


void searchDistancesToTowns(int **a, int  n);
int searchMinDistance(int  n, int *distancesToTowns, bool *visitedTowns);
void recalculationOfDistances(int start, int **a, int  n, int *distancesToTowns, string *way);
void printOrder(int *TownsInOrder, int n);
void printDistances(int *distancesToTowns, int n, string *way);
