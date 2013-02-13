#include "floatAutomatic.h"
#include <iostream>
#include <stdio.h>
using namespace std;

bool floatAutomatic(FILE* file)
{
    char c;

    c = fgetc(file);
    if (c == '-')
        c = fgetc(file);
    if (!((c >= '0') && (c <= '9')))
        return false;

    enum Position{numberBeforePoint, point, eNumber, numberAfterPoint, signAfterE, degree};
    Position position = numberBeforePoint;


    while(!feof(file))
    {
        c = fgetc(file);

        switch(position)
        {
        case numberBeforePoint:
        {
            if ((c >= '0') && (c <= '9'))
                position = numberBeforePoint;
            else if (c == '.')
                position = point;
            else if (c == 'e')
                position = eNumber;
            else if ((c != '\n') && ((int)c != -1))
                return false;
            break;
        }
        case point:
        {
            if ((c >= '0') && (c <= '9'))
                position = numberAfterPoint;
            else
                return false;
            break;
        }
        case numberAfterPoint:
        {
            if ((c >= '0') && (c <= '9'))
                position = numberAfterPoint;
            else if (c == 'e')
                position = eNumber;
            else if ((c != '\n') && ((int)c != -1))
                return false;
            break;
        }
        case eNumber:
        {
            if ((c >= '0') && (c <= '9'))
                position = degree;
            else if ((c == '-') || (c == '+'))
                position = signAfterE;
            else
                return false;
            break;
        }
        case signAfterE:
        {
            if ((c >= '0') && (c <= '9'))
                position = degree;
            else
                return false;
            break;
        }
        case degree:
        {
            if (!((c >= '0') && (c <= '9')) && (c != '\n') && ((int)c != -1))
                return false;
            break;
        }
        }
    }

    return true;
}
