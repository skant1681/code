// finding middle node of any linked list

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

void middleelement(node* head)
{
	node* p = head;
	node* q = head;

	while(p != NULL || p->next != NULL)
	{
		p = p->next;

		if(p == NULL || p->next == NULL)
			break;
		else
			p = p->next;
		q = q->next;
	}

	printf("------%d---------\n",q->data);
}

int main(int argc, char const *argv[])
{
	node* head = NULL;
	int nthvalue;

	push(&head,36);
	



	printlist(head);

	middleelement(head);

	return 0;
}