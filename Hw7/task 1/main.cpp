#include <iostream>
using namespace std;

int main()
{
    cout << "Enter students and written-off variant with gap." << endl <<
            "If student does`t pass off a work, enter 0 after his number.";
    cout << endl << "Enter 0 0 for exit." << endl;

    bool flag = true;

    int *array = new int[50];
    int *deduction = new int[50];

    int i;
    for (i = 0; i < 50; i++)
    {
        array[i] = -1;
    }
    array[1] = 1;
    array[2] = 2;
    array[3] = 3;

    while (flag == true)
    {
        int student = -1;
        int work = -1;
        cin >> student;
        cin >> work;
        if (student == 0)
        {
            flag = false;
        }
        else
        {
            array[student] = work;
        }
    }

    int deductionCount = -1;

    cout << endl << "Students and their variants: " << endl;
    for (i = 1; i < 50; i++)
    {
        if (array[i] == 0)
        {
            deductionCount++;
            deduction[deductionCount] = i;
        }
        else
        {
            if (array[i] != -1)
            {
                cout << i << " ";
                int k = i;
                while ((k != 1) && (k != 2) && (k != 3))
                {
                    k = array[k];
                }
                cout << k << endl;
            }
        }
    }

    cout << "Students for deduction: ";
    for (i = 0; i <= deductionCount; i++)
    {
        cout << deduction[i] << " ";
    }
    delete []array;
    delete []deduction;
    return 0;
}
