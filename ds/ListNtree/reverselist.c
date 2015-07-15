//reversing a linked list

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

node *reverselist(node* head, int k)
{
	node* p = head;
	node* q = NULL;
	node* temp = NULL;
	int count = 0;


	while(p != NULL && count < k)
	{
		temp = p->next;
		p->next = q;
		q = p;
		p = temp;
		count++;
	}
	
	if(temp != NULL)
		head->next = reverselist(temp,k);
		
	return q;
}


int main(int argc, char const *argv[])
{
	/* code */

	node* head = NULL;
	
	push(&head,3);
	push(&head,99);
	push(&head,32);
	push(&head,13);
	push(&head,30);
	
	printf("before reversing the list \n");
	printlist(head);

	int k;
	printf("enter value of k:\n");
	scanf("%d",&k);
	
	printf("after reversing the list\n");
	head = reverselist(head,k);
	printlist(head);

	return 0;
}