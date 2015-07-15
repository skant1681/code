//Removing duplicates from unsorted linked list

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
		printf("enter node->data\n");
		scanf("%d",&p->data);
		head = p;
	

		for(iter = 1; iter < n; iter++)
		{
			q = (node* )malloc(sizeof(node*));
			printf("enter node->data\n");
			scanf("%d",&q->data);
			//q->data = iter + 10;
			p->next = q;
			p = p->next;
		}
		p->next = NULL;
	}
	return head;
}

node* removedup(node* head)
{
	node* p = head;
	node* q = p->next;
	node* temp;
	head = p;

	while(q != NULL)
	{
		temp = head;
		while(temp != q )
		{
			if(temp->data == q->data && q != NULL)
			{
				p->next = q->next;
				free(q);
				q = p->next;
				temp = head;
			}
			else
				temp = temp->next;
			if (q == NULL)
					break;	
		}

		if (temp == q)
		{

			p = p->next;
			q = q->next;
		}

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
	printf("Before removing duplicates\n");
	printlist(head);

	head = removedup(head);

	printf("After removing duplicates\n");
	printlist(head);

	return 0;
}