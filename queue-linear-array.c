#include <stdio.h>

#define MAXSIZE 100

typedef struct
{
	int q[MAXSIZE];
	int head;
	int tail;
} queue;

int enque(queue *q,int a)
{
	if(q->tail>=MAXSIZE-1) {
		printf("Queue Overflow\n");
		return -1;
	}
	
	q->q[++q->tail] = a;
	return 1;
}

int deque(queue *q)
{
	if(q->head>q->tail) {
		printf("Queue Undeflow\n");
		return -1;
	}

	return q->q[q->head++];
}

int main()
{
	int n,c,end=0;
	queue q;
	q.head=0;
	q.tail=-1;

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
