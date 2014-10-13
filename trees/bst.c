#include <stdio.h>

// Functions:
#include "bst.h"

// Main program:

int main(int argc, char **argv)
{
	struct Node *root;
	int item,i,n;

	root = getnode();

	printf("how many items do you have?");
	scanf("%d",&n);

	for(i=0;i<n;i++) {
		printf("Enter the item: ");
		scanf("%d",&item);
		bst_ins(root,item);
	}

	printf("Printing sorted list: ");
	bst_traverse(root);
	//printf("%d %d %d",(root.left)->info,root.info,(root.right)->info);

	return 0;
}
