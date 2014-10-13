#ifndef _BST_H_
#define _BST_H_

#include <stdlib.h>

struct Node {
	int isp;
	int info;
	struct Node* left;
	struct Node* right;
};

struct Node* getnode() {
	struct Node *temp;
	temp = (struct Node*) malloc(sizeof(struct Node));
	temp->isp = -1;
	temp->right = NULL;
	temp->left = NULL;
	return temp;
}

void bst_ins(struct Node *root, int item) {
	if(root->isp==-1) {
		root->info = item;
		root->isp = 1;
		return;
	}
	else {
		if(item > root->info) {
			printf("to the right\n");
			if(root->right==NULL)
				root->right = getnode();
			bst_ins(root->right,item);
			return;
		}
		else {
			printf("to the left\n");
			if(root->left==NULL)
				root->left = getnode();
			bst_ins(root->left,item);
			return;
		}
	}
}

void bst_traverse(struct Node *root) {
	if(!root) return;

	bst_traverse(root->left);
	printf(" %d ",root->info);
	bst_traverse(root->right);
}


#endif
