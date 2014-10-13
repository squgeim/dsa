#ifndef _slist_h_
#define _slist_h_

struct nodetype 
{
	int info, next;
};

int avail;

int getnode(struct nodetype node[])
{
	int q;
	if(avail==-1)
		printf("Error\n");
	q = avail;
	avail = node[q].next;
	return q;
}

void freenode(struct nodetype node[], int p)
{
	node[p].next = avail;
	avail = p;
}

void insafter(struct nodetype node[], int p, int x)
{
	int q;
	if(node[p].next==-1)
		printf("Error\n");
	q=getnode(node);
	node[q].info = x;
	node[q].next = node[p].next;
	node[p].next = q;
}

void delafter(struct nodetype node[], int p, int *x)
{
	int q;
	if(node[p].next == -1)
		printf("Error\n");
	q = node[p].next;
	node[p].next = node[q].next;
	*x = node[q].info;
	freenode(node,q);
}

#endif
