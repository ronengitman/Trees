#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "BST.h"
#define CheckNULL(ptr)  ((ptr == NULL) ? 1 : 0) 

void insertNode(TreeNode* node, int data);
TreeNode* createNode(int data);
void printTree(TreeNode* node);
void destroy(TreeNode* node);
int treeHeight(TreeNode* node);


void initBST(BST* bst) {
	bst->root = NULL;
}

void insertBST(BST* bst, int data)
{
	if (CheckNULL(bst->root))
		bst->root = createNode(data);
	else
		insertNode(bst->root, data);
}

void insertNode(TreeNode* node, int data)
{
	if (data <= node->element)
	{
		if (CheckNULL(node->left))
			node->left = createNode(data);
		else
			insertNode(node->left, data);
	}
	else {
		if (CheckNULL(node->right))
			node->right = createNode(data);
		else
			insertNode(node->right, data);
	}
}

TreeNode* createNode(int data)
{
	TreeNode* temp = (TreeNode*)calloc(1 , sizeof(TreeNode));
	if (CheckNULL(temp))
	{
		printf("no memory");
		return;
	}
	temp->element = data;
	return temp;
}

void printTreeInorder(BST* bst) {
	if (!bst->root) {
		printf("The tree is empty");
		return;
	}
	printTree(bst);
}

void printTree(TreeNode* node) {
	if (!node) return;
	printTree(node->left);
	printf("%d, ", node->element);
	printTree(node->right);
}

void destroyBST(BST* bst) {
	if (bst->root) {
		destroy(bst);
	}
}

void destroy(TreeNode* node) {
	if (!node) return;
	destroy(node->left);
	destroy(node->right);
	free(node);
}

int findIndexNFromLast(BST* bst, int N) {
	if (!bst->root) {
		printf("The tree is empty");
		return -1;
	}

	return find(bst,N);
}

int count(TreeNode* node) {
	if (!node) return 1;
	return (count(node->left) + count(node->right));
}

int find(TreeNode* node, int N) {
	if (!node) return -1;
	if (1 + count(node) == N) return node->element;
	find(node->left,N);
	find(node->right,N);
}

int sameHeightLeaves(BST* bst) {
	if (!bst->root) {
		printf("The tree is empty");
		return -1;
	}
	return sameHeight(bst);
}

int treeHeight(TreeNode* node) {
	if (!node) return 0;
	return 1 + max(treeHeight(node->left), treeHeight(node->right));
}

int sameHeight(TreeNode* node) {
	if (!node) return 0;
	return (treeHeight(node->left) == treeHeight(node->right));
}




