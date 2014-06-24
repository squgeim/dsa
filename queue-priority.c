#include <stdio.h>

#define MAXSIZE 100

typedef struct
{
	int q[MAXSIZE];
	int head;
	int tail;
} queue;

void sort(queue *q)
{
	int i,j,k;

	for(i=0;i<q->tail+1;i++) {
		for(j=0;j<q->tail;j++) {
			if(q->q[j]>q->q[j+1]) {
				k=q->q[j];
				q->q[j]=q->q[j+1];
				q->q[j+1]=k;
			}
		}
	}
}

int enque(queue *q,int n)
{
	if(q->tail>=MAXSIZE-1) {
		printf("Queue Overflow\n");
		return -1;
	}

	q->q[++q->tail] = n;
	sort(q);
	return 1;
}

int deque(queue *q)
{
	int i,item;
	if(q->tail<q->head) {
		printf("Queue Underflow\n");
		return -1;
	}
	
	item=q->q[q->head];
	for(i=0;i<q->tail;i++) {
		q->q[i]=q->q[i+1];
	}
	q->tail--;
	sort(q);	
	return item;
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
