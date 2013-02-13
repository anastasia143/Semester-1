#include "tree.h"
#include "stdlib.h"
#include <iostream>

using namespace std;

Tree *createTree()
{
    Tree *tree = new Tree;
    tree->root = NULL;
    tree->count = 0;
    return tree;
}

TreeNode *createTreeNode(int value)
{
    TreeNode *node = new TreeNode;
    node->left = NULL;
    node->right = NULL;
    node->value = value;
    return node;
}

void add(Tree *tree, int value)
{
    add(tree, tree->root, value);
    tree->count++;
}

void add(Tree *tree, TreeNode *&node, int value)
{
    if (node == NULL)
    {
        node = createTreeNode(value);
        return;
    }
    if (value < node->value)
    {
        add(tree, node->left, value);
    }
    else if (value > node->value)
    {
        add(tree, node->right, value);
    }
    else
    {
        tree->count--;
        return;
    }
}


void printDescending(Tree *tree)
{
    if (tree->count == 0)
    {
        cout << "Tree is empty";
        return;
    }
    if (tree->count == 1)
    {
        cout << tree->root->value << endl;
        return;
    }
    printDescending(tree->root);
}

void printDescending(TreeNode *node)
{
    if (node != NULL)
    {
        printDescending(node->right);
        cout << node->value << " ";
        printDescending(node->left);
    }

}

void printAscending(Tree *tree)
{
    if (tree->count == 0)
    {
        cout << "Tree is empty";
        return;
    }
    if (tree->count == 1)
    {
        cout << tree->root->value << endl;
        return;
    }
    printAscending(tree->root);
}

void printAscending(TreeNode *node)
{
    if (node != NULL)
    {
        printAscending(node->left);
        cout << node->value << " ";
        printAscending(node->right);
    }
}
bool exist(Tree *tree, int value)
{
    if ((tree->count) == 0)
    {
        return false;
    }
    if (tree->root->value == value)
    {
        return true;
    }
    return exist(tree->root, value);
}

bool exist(TreeNode *node, int value)
{
    if (node == NULL)
    {
        return false;
    }
    if (node->value == value)
    {
        return true;
    }
    if (value < node->value)
    {
        return exist(node->left, value);
    }
    else
    {
        return exist(node->right, value);
    }
}

void remove(Tree *tree, int value)
{
    if (exist(tree, value))
    { 
        tree->count--;
        {
            remove(tree->root, value);
        }
        cout << "You removed the element." << endl;
    }
    else
    {
        cout << "There is no this element in the tree." << endl;
    }

}

void remove(TreeNode *&node, int value)
{

    if (value < node->value)
    {
        remove(node->left, value);
    }
    else if (value > node->value)
    {
        remove(node->right, value);
    }
    else if (hasNoChild(node))
    {
        delete node;
        node = NULL;
        return;
    }
    else if (hasOneChild(node))
    {
        if (node->left != NULL)
        {
            TreeNode *temp = node->left;
            delete node;
            node = temp;
        }
        if (node->right != NULL)
        {
            TreeNode *temp = node->right;
            delete node;
            node = temp;
        }
    }
    else
    {
        TreeNode *temp = leftMostChild(node->right);
        node->value = temp->value;
        node->right = temp->right;

        if (hasNoChild(temp))
        {
            delete temp;
            temp = NULL;
            return;
        }
        else
        {
            TreeNode *pemp = temp->right;
            delete temp;
            temp = pemp;
        }
    }

}

TreeNode *leftMostChild(TreeNode *node)
{
    while (node->left != NULL)
    {
        node = node->left;
    }
    return node;
}

bool hasNoChild(TreeNode *node)
{
    return (node->left == NULL) && (node->right == NULL);
}

bool hasOneChild(TreeNode *node)
{
    return ((node->left == NULL) && (node->right != NULL)) ||
            ((node->left != NULL) && (node->right == NULL));
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
