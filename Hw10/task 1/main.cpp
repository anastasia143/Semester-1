#include <iostream>
#include "stdio.h"
#include "list.h"

int main()
{
    List* polynomialOne = createList();
    List* polynomialTwo = createList();

    cout << "Enter with gap degrees and factors for polynom ONE: " << endl <<  "(enter '0 0' for exit)" << endl;
    fillingList(polynomialOne);
    cout << endl << "Enter with gap degrees and factors for polynom TWO: " << endl <<  "(enter '0 0' for exit)" << endl;
    fillingList(polynomialTwo);

    cout << endl << endl << "THE COMMANDS: " << endl;
    cout << "1 - equality test" << endl;
    cout << "2 - value of polynomial at the point" << endl;
    cout << "3 - sum of polymials" << endl;
    cout << "0 - exit" << endl << endl;

    enum Commands{exit = 0, equalTest = 1, valueInPoint = 2, sumOfPol = 3};
    Commands command;

    while(command != exit)
    {
        cout << "Enter command: ";
        int n;
        cin >> n;
        if ((n >= 0) && (n <=3))
                command  = static_cast <Commands>(n);
        else command = exit;
        switch(command)
        {
        case equalTest:
        {
            if (equal(polynomialOne, polynomialTwo))
                cout << "Polynomials are equal" << endl;
            else
                cout << "Polynomials are NOT equal" << endl;
            cout << endl;
            break;
        }
        case valueInPoint:
        {
            int number;
            int x;
            cout << "Enter number of polynomial (1 or 2): ";
            cin >> number;
            cout  << "Enter x: ";
            cin >> x;

            cout << "Value of polynomial " << number << " in point " << x << ": ";
            if (number == 1)
                cout << value(polynomialOne, x);
            else
                cout << value(polynomialTwo, x);
            cout << endl << endl;
            break;
        }
        case sumOfPol:
        {
            cout << "Sum of polynomails: ";
            List* sumOfPol = sum(polynomialOne, polynomialTwo);
            printSum(sumOfPol);
            break;
        }
        default:
        {
            command = exit;
            break;
        }
        }
    }

    destroy(polynomialOne);
    destroy(polynomialTwo);

    return 0;
}
