#include "list.h"
#include <iostream>
using namespace std;

int main()
{
    cout << "0 - Exit" << endl;
    cout << "1 - add value" << endl;
    cout << "2 - remove value" << endl;
    cout << "3 - print list" << endl;
    List *list = createList(); // Создание листа

    int command = 1;
    cout << "Enter command: ";
    cin >> command;
    while (command != 0)
    {
        switch (command)
        {
        case 1:
            {
                int a;
                cout << "Enter element for add: ";
                cin >> a;
                add(a, list);
                break;
            }
        case 2:
            {
                int b;
                cout << "Enter element for remove: ";
                cin >> b;
                remove(b, list);
                break;
            }
        case 3:
            {
                print(list);
                break;
            }

        }

        cout << "Enter command: ";
        cin >> command;
    }

    cout << "GOODBYE!!!";
    destroy(list);

    return 0;
}
