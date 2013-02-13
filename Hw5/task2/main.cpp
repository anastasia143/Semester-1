#include <iostream>
using namespace std;

int main()
{
    unsigned char array[64];
    cout << "Enter value: ";
    double x = 0;
    cin >> x;
    unsigned char * b = (unsigned char*)&x;
    int i = 0;
    for (int byte = 7; byte >= 0; byte--)
        for (int bit = 7; bit >= 0; bit--)
        {
            i++;
            if ((b[byte] & (1 << bit)) > 0)
            {
                array[i] = '1';
            }
            else
            {
                array[i] = '0';
            }
        }

    char sign;
    if (array[1] == '1')
    {
        sign = '-';
    }
    else
    {
        sign = '+';
    }

    int stepen = 0;
    long double exponenta = 0;
    for (i = 12; i >= 2; i--)
    {
        if (array[i] == '1')
        {
            exponenta = exponenta + (long double)(1 << stepen);
        }
        stepen++;
    }
    exponenta = exponenta - 1023;

    long double mantissa = 1;
    stepen = 1;
    for (i = 13; i <= 64; i++)
    {
        if (array[i] == '1')
        {
            mantissa = mantissa + (1 / ((long double) (1 << stepen)));
        }
        stepen++;
    }


    cout << "Exponential form : " << sign << mantissa << " * 2^(" << exponenta << ")";
    return 0;
}

