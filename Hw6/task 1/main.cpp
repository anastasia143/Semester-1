#include <iostream>
#include "tree.h"

using namespace std;

int main()
{
    Tree *tree = createTree();
    cout << "Commands: " << endl << "0 - exit";
    cout << endl << "1 - add an element";
    cout << endl << "2 - remove an element";
    cout << endl << "3 - check whether the element";
    cout << endl << "4 - print descending";
    cout << endl << "5 - print ascending" << endl;

    int command = 1;
    int value = 0;
    while (command != 0)
    {
        cout << endl << "Enter an command: ";
        cin >> command;

        switch(command)
        {
        case 1:
        {
            cout << "Element for add: ";
            cin >> value;
            add(tree, value);
            cout << "You added the element" << endl;
            break;
        }
        case 2:
        {
            cout << "Element for remove: ";
            cin >> value;
            remove(tree, value);
            break;
        }
        case 3:
        {
            cout << "Enter element for checking: ";
            cin >> value;
            if (exist(tree, value))
            {
                cout << "Yes, the element is in tree." << endl;
            }
            else
            {
                cout << "No, the element is not in tree." << endl;
            }

            break;
        }
        case 4:
        {
            printDescending(tree);
            cout << endl;
            break;
        }
        case 5:
        {
            printAscending(tree);
            cout << endl;
            break;
        }
        }
    }
    deleteFunction(tree->root);
    delete tree;
    return 0;
}
