//Implemented insertion in doubly linked list using passing by value

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* next;
	struct node* prev;
};


typedef struct node node;

void push(node** head, int value)
{
	node* p;
	if(*head == NULL)
	{
		node* temp = (node* )malloc(sizeof(node* ));
		temp->data = value;
		temp->next = *head;
		temp->prev = NULL;
		*head = temp;
		return;
	}
	else
	{
		p = *head;
		node* temp = (node* )malloc(sizeof(node* ));
		temp->data = value;
		temp->next = *head;
		temp->prev = NULL;
		p->prev = temp;
		*head = temp;
		return;
	}
}

node* insert(node* head, int n)
{
	node* temp;
	node* p;
	node *q;

	temp = head;
	while(temp != NULL)
	{
	if(temp->data == n && temp->prev == NULL)
	{
		temp = (node* )malloc(sizeof(node* ));
		temp->data = 132;
		temp->prev = NULL;
		temp->next = head;
		head->prev = temp;
		head = temp;
		temp = temp->next;
	}

	else if(temp->data == n && temp->next == NULL)
	{
		p = temp;
		temp = (node* )malloc(sizeof(node* ));
		temp->data = 132;
		temp->next = NULL;
		temp->prev = p;
		p->next = temp;
	}

	else if (temp->data == n && temp->next != NULL && temp->prev != NULL)
	{
		p = temp->prev;
		q = temp;
		temp = (node* )malloc(sizeof(node* ));
		temp->data = 132;
		temp->next = q;
		q->prev = temp;
		temp->prev = p;
		p->next = temp;
		temp = temp->next;
	}

	temp = temp->next;
}
	return head;
}

void printlist(struct node* head)
{
	while(head != NULL)
	{
		printf("%d\n",head->data);
		head = head->next;
	}
}


int main()
{
	node* head = NULL;
	int numtoinsert;

	push(&head,3);
	push(&head,99);
	push(&head,32);
	push(&head,13);
	push(&head,30);

	printf("before inserting....\n");
	printlist(head);

	printf("Enter number where you want to insert\n");
	scanf("%d",&numtoinsert);

	head = insert(head,numtoinsert);

	printf("after inserting\n");
	printlist(head);


	return 0;
}


/*

//Implemented insertion in doubly linked list using pointer to pointer(passing by refrence)

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* next;
	struct node* prev;
};


typedef struct node node;

void push(node** head, int value)
{
	node* p;
	if(*head == NULL)
	{
		node* temp = (node* )malloc(sizeof(node* ));
		temp->data = value;
		temp->next = *head;
		temp->prev = NULL;
		*head = temp;
		return;
	}
	else
	{
		p = *head;
		node* temp = (node* )malloc(sizeof(node* ));
		temp->data = value;
		temp->next = *head;
		temp->prev = NULL;
		p->prev = temp;
		*head = temp;
		return;
	}
}

void insert(node** head, int n)
{
	node* temp;
	node* p;
	node *q;

	temp = *head;
	while(temp != NULL)
	{
	if(temp->data == n && temp->prev == NULL)
	{
		temp = (node* )malloc(sizeof(node* ));
		temp->data = 132;
		temp->prev = NULL;
		temp->next = *head;
		(*head)->prev = temp;
		*head = temp;
		temp = temp->next;
	}

	else if(temp->data == n && temp->next == NULL)
	{
		p = temp;
		temp = (node* )malloc(sizeof(node* ));
		temp->data = 132;
		temp->next = NULL;
		temp->prev = p;
		p->next = temp;
	}

	else if (temp->data == n && temp->next != NULL && temp->prev != NULL)
	{
		p = temp->prev;
		q = temp;
		temp = (node* )malloc(sizeof(node* ));
		temp->data = 132;
		temp->next = q;
		q->prev = temp;
		temp->prev = p;
		p->next = temp;
		temp = temp->next;
	}

	temp = temp->next;
}
}

void printlist(struct node* head)
{
	while(head != NULL)
	{
		printf("%d\n",head->data);
		head = head->next;
	}
}


int main()
{
	node* head = NULL;
	int numtoinsert;

	push(&head,3);
	push(&head,99);
	push(&head,32);
	push(&head,13);
	push(&head,30);

	printf("before inserting....\n");
	printlist(head);

	printf("Enter number where you want to insert\n");
	scanf("%d",&numtoinsert);

	insert(&head,numtoinsert);

	printf("after inserting\n");
	printlist(head);


	return 0;
}
*/