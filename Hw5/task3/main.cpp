#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
    cout << "Comments in file.txt: " << endl;
    FILE* out = fopen("file.txt", "r");
    if (out == NULL)
    {
        cout << "File is empty" << endl;

    }
    char c;
    int count = 2;
    c = fgetc(out);
    while (!feof(out))
    {
        c = fgetc(out);
        if (c == '"')
        {
            count++;
        }
        if (c == '/')
        {
            c = fgetc(out);
            if ((c == '/') & (count % 2 == 0))
            {
                cout << "//";
                while ((c != '\n') && (!feof(out)))
                {
                    c = fgetc(out);
                    cout << c;

                }
            }
            else if (c == '*')
            {
                bool flag = false;
                while (flag == false)
                {
                    while (c =! '*')
                    {
                        c = fgetc(out);
                    }
                    c = fgetc(out);
                    if (c == '/')
                    {
                        flag = true;
                    }
                }
            }

        }
    }
    fclose(out);

    return 0;
}
