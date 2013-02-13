#pragma once
using namespace std;


struct TreeNode
{
    int value;
    TreeNode *left;
    TreeNode *right;
};

struct Tree
{
    TreeNode *root;
    int count;
};

Tree *createTree();
TreeNode *createTreeNode(int value);

void add(Tree *tree, int value);
void add(Tree *tree, TreeNode *&node, int value);
void printAscending(Tree *tree);
void printAscending(TreeNode *node);
void printDescending(Tree *tree);
void printDescending(TreeNode *node);
bool exist(Tree *tree, int value);
bool exist(TreeNode *node, int value);
void remove(Tree *tree, int value);
void remove(TreeNode *&node, int value);
bool hasNoChild(TreeNode *node);
bool hasOneChild(TreeNode *node);
TreeNode *leftMostChild(TreeNode *node);
void deleteFunction(TreeNode *temp);
