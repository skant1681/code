//finding nth node in an linked list

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* next;
};


typedef struct node node;

void push(node** head, int value)
{
	node* temp = (node* )malloc(sizeof(node* ));
	temp->data = value;
	temp->next = *head;
	*head = temp;
}

void printlist(struct node* head)
{
	while(head != NULL)
	{
		printf("%d\n",head->data);
		head = head->next;
	}
}

void nthnode(node* head, int nthvalue)
{
	node* p = head;
	int counter = 1;

	while(counter < nthvalue)
	{
		p = p->next;
		counter++;
	}

	if(counter == nthvalue)
		printf("%d\n",p->data );
	else
		printf("OOPS!!.\n");
}

int main(int argc, char const *argv[])
{
	node* head = NULL;
	int nthvalue;
	
	push(&head,3);
	push(&head,99);
	push(&head,32);
	push(&head,13);
	push(&head,30);
	printlist(head);
	
	printf("which node to find\n");
	scanf("%d",&nthvalue);
	nthnode(head,nthvalue);

	return 0;
}