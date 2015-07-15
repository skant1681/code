#include <stdio.h>
#include <stdlib.h>

struct node
{
	/* data */
	int data;
	struct node* next;
};
typedef struct node node;

node* createlist(node* head, int n)
{
	node* p = NULL;
	node* q = NULL;
	int iter;

	if(n <= 0)
		return;
	else
	{
		p = (node* )malloc(sizeof(node*));
		p->data = n + 10;
		head = p;
	

		for(iter = 1; iter < n; iter++)
		{
			q = (node* )malloc(sizeof(node*));
			q->data = iter + 10;
			p->next = q;
			p = p->next;
		}
		p->next = NULL;
	}
	return head;
}

void printlist(node* head)
{
	
	while(head != NULL)
	{
		printf("%d\n", head->data);
		head = head->next;
	}
}

int main(int argc, char const *argv[])
{
	node* head = NULL;
	int numofnodes;

	printf("how many number of nodes ? \n");
	scanf("%d",&numofnodes);

	head = createlist(head,numofnodes);

	printlist(head);

	return 0;
}