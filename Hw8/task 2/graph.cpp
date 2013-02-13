#include "graph.h"
#include "limits.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

int searchMinDistance(int  n, int *distancesToTowns, bool *visitedTowns)
{
    int minDistance = INT_MAX;
    bool flag = true;
    for(int i = 0; i < n; i++)
    {
        if (flag)
        {
            if(!visitedTowns[i])
            {
                minDistance = i;
                flag = false;
            }
        }
        else if ((distancesToTowns[i] != INT_MAX) && (visitedTowns[i] == false) && (distancesToTowns[i] < distancesToTowns[minDistance]))
        {
            minDistance = i;
        }
    }
    return minDistance;
}
void recalculationOfDistances(int start, int **a, int  n, int *distancesToTowns, string *way)
{
    for (int i = 0; i < n; i++)
    {
        if (a[start][i] != 0)
        {
            int distance = a[start][i] + distancesToTowns[start];
            if (distance < distancesToTowns[i])
            {
                distancesToTowns[i] = distance;

                way[i].clear();

                stringstream oss;
                oss << way[start];
                way[i].append(oss.str());
                oss.clear();
                oss.str("");

                oss << i;
                way[i].append(oss.str());
                way[i].append(" ");
                oss.clear();
                oss.str("");
            }
        }
    }
}

void printOrder(int *TownsInOrder, int n)
{
    cout << endl << endl << "Order of towns: ";
    for (int i = 0; i < n; i ++)
    {
        cout << TownsInOrder[i] << " ";
    }
    cout << endl;
}

void printDistances(int *distancesToTowns, int n, string *way)
{
    cout << endl << "Distances from town 0 to other towns: " << endl;
    cout << endl << setw(8) << "town " << setw(12) << "distance" << setw(7) << "way" << endl;
    for (int i = 1; i < n; i++)
    {
        cout << setw(6) << i << setw(12) << distancesToTowns[i] << "     " << way[i] << endl;

    }
}

void searchDistancesToTowns(int **a, int  n)
{
    int *distancesToTowns = new int[n];
    bool *visitedTowns = new bool[n];
    int *TownsInOrder = new int[n];
    int visitedCount = 0;

    int i;

    for(i = 0; i < n; i++)
    {
        distancesToTowns[i] = INT_MAX;
        visitedTowns[i] = false;
        TownsInOrder[i] = -1;
    }

    string *way = new string[n];

    visitedTowns[0] = true;
    for (i = 0; i < n; i++)
    {
        if (a[0][i] != 0)
        {
            distancesToTowns[i] = a[0][i];

            way[i].clear();

            stringstream oss;

            oss << 0;
            way[i].append(oss.str());
            way[i].append(" ");

            oss.clear();
            oss.str("");
            oss << i;
            way[i].append(oss.str());
            way[i].append(" ");
            oss.clear();
            oss.str("");
        }
    }

    int start = 0;
    for(i = 1; i < n; i++)
    {
        visitedTowns[start] = true;
        visitedCount++;
        TownsInOrder[visitedCount - 1] = start;
        start = searchMinDistance(n, distancesToTowns, visitedTowns);
        recalculationOfDistances(start, a, n, distancesToTowns, way);
    }
    visitedCount++;
    TownsInOrder[visitedCount - 1] = start;

    printOrder(TownsInOrder, n);
    printDistances(distancesToTowns, n, way);

    delete []distancesToTowns;
    delete []visitedTowns;
    delete []TownsInOrder;
    delete []way;
}
