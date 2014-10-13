#ifndef _llist_h_
#define _llist_h_

struct Nodetype {
	int info;
	struct Nodetype *next;
};
typedef Nodetype Node;

Node *head;

Node* getnode()
{
	Node *temp;
	temp = malloc(sizeof(Node));
	return temp;
}

void addbeg(int x)
{
	Node p;
	p=getnode();
	p->info = x;
	p->next = head;
	head = p;
}

void addend(int x)
{
	Node p,temp;
	p=getnode();
	temp=head;
	while(temp.next!=NULL) {
		temp=temp.next;
	}
	p.info=x;
	p.next=NULL;
	temp.next=p;
}

//void addafter(Node* p,int x)
//{


#endif
	
