#include <stdio.h>
#include "../list/slist.h"

#define MAX 100

struct nodetype node[MAX];

struct queue {
	int front, rear;
};

int empty(struct queue q)
{
	if(q.front==-1)
		return 1;
	else
		return 0;
}

void enque(struct queue *q,int x)
{
	int p;
	
	p = getnode(node);
	node[p].info = x;
	node[p].next = -1;

	if(q->rear == -1)
		q->front = p;
	else
		node[q->rear].next = p;
	q->rear = p;
}

int dequeue(struct queue *q)
{
	int p;
	if(empty(*q)) {
		printf("Underflow\n");
		return -1;
	}

	p = q->front;
	q->front = node[p].next;
	if(q->front == -1)
		q->rear = -1;
	freenode(node,p);
	return node[p].info;
}

int main()
{
	int i,x;
	struct queue q;
	
	q.front = -1, q.rear = -1;
	
	avail = 0;
	for(i=0;i<MAX-1;i++)
		node[i].next = i+1;
	node[MAX-1].next = -1;

	printf("enter 4 items: ");
	for(i=0;i<4;i++) {
		scanf("%d",&x);
		enque(&q,x);
	}
	printf("you entered: ");
	for(i=0;i<4;i++) {
		printf("%d ",dequeue(&q));
	}

	return 0;
}
