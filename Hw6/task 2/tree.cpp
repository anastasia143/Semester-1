#include "tree.h"
#include <iostream>
using namespace std;

#include "tree.h"
#include "stdlib.h"
#include <iostream>
#include <cstring>

using namespace std;


Tree *createTree()
{
    Tree *tree = new Tree;
    tree->root = NULL;
    return tree;
}

TreeNode *createTreeNode(char value)
{
    TreeNode *node = new TreeNode;
    node->left = NULL;
    node->right = NULL;
    node->value = value;
    return node;

}

void collectingTree (Tree *&tree, FILE *file)
{
    collectingTree (tree->root, file);
}

void collectingTree (TreeNode *&node, FILE *file)
{
    char c;
    if (!feof(file))
    {

       c = fgetc(file);
    }
    else
    {
        return;
    }

    while (((c == '(') || (c == ')')) && (!feof(file)))
    {
        c = fgetc(file);

    }

    if ((c == '*') || (c == '/') || (c == '+') || (c == '-'))
    {
        node = createTreeNode(c);

        collectingTree(node->left, file);
        collectingTree(node->right, file);
    }
    else
    {
        node = createTreeNode(c);
    }

}

void deleteFunction(TreeNode* temp)
{
    TreeNode *node = temp;
    if (node != NULL)
    {
        deleteFunction(node->left);
        deleteFunction(node->right);
        delete node;
    }

}

void printPrefixTree(Tree *tree)
{
    printPrefixTree(tree->root);
}

void printPrefixTree(TreeNode *node)
{
    if (node != NULL)
    {
        cout << node->value << " ";
        printPrefixTree(node->left);
        printPrefixTree(node->right);
    }
}

void printPostfixTree(Tree *tree)
{
    printPostfixTree(tree->root);
}

void printPostfixTree(TreeNode *node)
{
    if (node != NULL)
    {
        printPostfixTree(node->right);
        printPostfixTree(node->left);
        cout << node->value << " ";
    }

}

int calculate(Tree* tree)
{

    return calculate(tree->root);
}

int calculate(TreeNode* node)
{
    switch(node->value)
    {
    case '+':
    {
        return calculate(node->left) + calculate(node->right);
        break;
    }
    case '-':
    {
        return calculate(node->left)- calculate(node->right);
        break;
    }
    case '/':
    {
        return calculate(node->left) / calculate(node->right);
        break;
    }
    case '*':
    {
        return calculate(node->left) * calculate(node->right);
        break;
    }
    default:
    {
        return ((int)node->value - 48);
        break;
    }
    }
}

