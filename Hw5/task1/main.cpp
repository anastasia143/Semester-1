#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;


int main()
{
    bool repeat[200];
    char slovo[1000];
    for (int c = 0; c < 200; c++)
    {
        repeat[c] = 0;
    }
    for (int c = 0; c <= 1000; c++)
    {
        slovo[c] = '\0';
    }
    char str[1000] = "wood home mission razzor www";
    cout << "String: " << str;

    cout << endl << "Words: ";
    int len = strlen(str);
    int i = 0;
    while (i < len)
    {
        while ((str[i] != ' ') && (i < len))
        {
            if (repeat[(int)(str[i])] == 0)
            {
                cout << str[i];
            }
            repeat[(int)(str[i])]++;
            i++;
        }
        cout << " ";
        i++;
        for (int c = 0; c < 200; c++)
        {
            repeat[c] = 0;
        }
    }
    return 0;
}
