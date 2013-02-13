#include "graph.h"
#include "stdio.h"

int main()
{
    FILE *file = fopen("file.txt", "r");

    int n = 0;
    fscanf(file, "%i", &n);

    int m = 0;
    fscanf(file, "%i", &m);

    cout << "There are " << n << " towns and " << m << " roads.";

    int **a = new int*[n]; // Матрица "а"
    int i;
    for(i = 0; i < n; i++)
    {
        a[i] = new int [n];
    }

    for(i = 0; i < n; i++)
    {
        for (int k = 0; k < n; k++)
        {
            a[i][k] = 0;
        }
    }

    int town1 = 0;
    int town2 = 0;
    int distance = 0;
    for(i = 0; i < m ; i++)
    {
        fscanf(file, "%i", &town1);
        fscanf(file, "%i", &town2);
        fscanf(file, "%i", &distance);
        a[town1][town2] = distance;
        a[town2][town1] = distance;
    }

    searchDistancesToTowns(a, n); // Поиск минимальных расстояний от города 0

    for(i = 0; i < n; i++)
    {
        delete []a[i];
    }
    delete []a;
    
    return 0;
}
