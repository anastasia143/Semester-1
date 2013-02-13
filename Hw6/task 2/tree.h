#pragma once
#include <iostream>
#include "stdio.h"
using namespace std;


struct TreeNode
{
    char value;
    TreeNode *left;
    TreeNode *right;
};

struct Tree
{
    TreeNode *root;
    int count;
};

TreeNode *createTreeNode(char value);
Tree *createTree();


void deleteFunction(TreeNode* temp);
void collectingTree (TreeNode *&tree, FILE* file);
void collectingTree (Tree *&tree, FILE* file);
void printPrefixTree(TreeNode *node);
void printPrefixTree(Tree *tree);
void printPostfixTree(TreeNode *node);
void printPostfixTree(Tree *tree);
int calculate(Tree *tree);
int calculate(TreeNode* node);
