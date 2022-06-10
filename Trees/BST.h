#ifndef _BST_ADT_H
#define _BST_ADT_H

typedef struct TreeNode TreeNode;

struct TreeNode
{
    TreeNode* left;
    TreeNode* right;
    int element;
};

typedef struct BST
{
    TreeNode* root;
}BST;

void initBST(BST* bst);

void insertBST(BST* bst, int value);

void destroyBST(BST* bst);

void destroyBST(BST* bst);

int findIndexNFromLast(BST* bst, int N);

int sameHeightLeaves(BST* bst);

#endif // !_BST_ADT_H