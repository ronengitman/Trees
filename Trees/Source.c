#include <stdio.h>
#include "BST.h"
#include "TreePrintLibrary.h"

void main() {
	BST bst;
	initBST(&bst);
	insertBST(&bst, 5);
	insertBST(&bst, 7);
	insertBST(&bst, 9);
	insertBST(&bst, 11);
	insertBST(&bst, 8);
	insertBST(&bst, 2);
	insertBST(&bst, 1);
	insertBST(&bst, 0);
	//insertBST(&bst, 3);

	print_ascii_tree(bst.root);
	printTreeInorder(bst.root);
	printf("\n");
	//printf("  %d", findIndexNFromLast(bst.root, 2));
	printf("sameHeightLeaves:  %d", sameHeightLeaves(bst.root));
	destroyBST(bst.root);
}