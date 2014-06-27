#include <stdio.h>

#define MAXSIZE 100

typedef struct
{
	int q[MAXSIZE];
	int head;
	int tail;
} queue;

int enque(queue *q,int n)
{
	if(q->head==(q->tail+1)%MAXSIZE) {
		printf("Queue Overflow\n");
		return -1;
	}

	q->q[q->tail]=n;
	q->tail=(q->tail+1)%MAXSIZE;
	return 1;
}

int deque(queue *q)
{
	int item;
	if(q->head==q->tail) {
		printf("Queue Underflow\n");
		return -1;
	}

	item=q->q[q->head];
	q->head=(q->head+1)%MAXSIZE;
	return item;
}

int main()
{
	int n,c,end=0;
	queue q;
	q.head=0;
	q.tail=0;

	do {
		printf("What do you want to do?\n(1) Enque\n(2) Deque\n(0) Exit\nChoose:");
		scanf("%d",&c);
		switch(c) {
			case 1:
				printf("Enter the number: ");
				scanf("%d",&n);
				enque(&q,n);
				break;
			case 2:
				n=deque(&q);
				if(n==-1) break;
				printf("The item is %d\n",n);
				break;
			default:
				end=1;
				break;
		}
	} while(!end);

	return 0;
}
