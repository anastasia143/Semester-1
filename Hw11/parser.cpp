#include "parser.h"
#include <iostream>
#include <stdio.h>
using namespace std;

bool parser(FILE *file)
{
    char c = fgetc(file);
    return (addition(file, c) && ((c == '\n') || ((int)c == -1)));
}

// �������� � ���������

bool addition(FILE* file, char& c) // E->TE'
{
    return (multiplication(file, c) && additionHelp(file, c));
}

bool additionHelp(FILE* file, char& c) // E'->+TE'|e
{
    if ((c =='+') || (c == '-'))
    {
        c = fgetc(file);
        if (multiplication(file, c) && (additionHelp(file, c)))
            return true;
        else
        {
            ungetc(c, file);
            return false;
        }
    }
    else
        return true; // �������
}

// ��������� � �������

bool multiplication(FILE* file, char& c) // T->�T'
{
    return(bracketsAndTokens(file, c) && multiplicationHelp(file, c));
}

bool multiplicationHelp(FILE* file, char& c)// T'->*�T'|e
{
    if ((c =='*') || (c == '/'))
    {
        c = fgetc(file);
        if (bracketsAndTokens(file, c) && (multiplicationHelp(file, c)))
            return true;
        else
        {
            ungetc(c,file);
            return false;
        }
    }
    else
        return true; // �������
}

// ������ � ������

bool bracketsAndTokens(FILE* file, char& c) // F->(E)|id
{
    if (c == '(')
    {
        c = fgetc(file);

        if (addition(file, c) && c == ')')
        {
            c = fgetc(file);
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return floatAutomatic(file, c);
    }
}

// ������� ��� ����� � ��������� �������

bool floatAutomatic(FILE* file, char& c)
{
    if (c == '-')
        c = fgetc(file);
    if (!((c >= '0') && (c <= '9')))
        return false;

    enum Position{numberBeforePoint, point, eNumber, numberAfterPoint, signAfterE, degree};
    Position position = numberBeforePoint;

    while((!feof(file) && (c != '/') && (c != '*') && (c != '(') && (c != ')') &&
           (c != '+') && (c != '-')) || ((position == signAfterE) && ((c == '+')||(c == '-'))))
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
            else if ((c != '\n') && ((int)c != -1) && (c != '+') && (c != '-') && (c != '/')
                     && (c != '*') && (c != '(') && (c != ')'))
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
            else if ((c != '\n') && ((int)c != -1) && (c != '+') && (c != '-') && (c != '/')
                     && (c != '*') && (c != '(') && (c != ')'))
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
            if (!((c >= '0') && (c <= '9')) && (c != '\n') && ((int)c != -1) && (c != '+')
                    && (c != '-') && (c != '/') && (c != '*') && (c != '(') && (c != ')'))
                return false;
            break;
        }
        }
    }

    return true;
}
