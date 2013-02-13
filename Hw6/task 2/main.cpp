#include <iostream>
#include "stdio.h"
#include "tree.h"
using namespace std;
#include <cstring>

int main()
{
    FILE* file = fopen("file.txt", "r+");
    Tree *tree = createTree();


    if (file == NULL)
    {
        cout << "File is empty" << endl;
    }
    else
    {
        collectingTree(tree, file);
    }


    cout << "Prefix: ";
    printPrefixTree(tree);

    cout << endl << "Postfix: ";
    printPostfixTree(tree);

    cout << endl << "Result: ";
    cout << calculate(tree);



    deleteFunction(tree->root);
    delete tree;
    fclose(file);
    return 0;
}
