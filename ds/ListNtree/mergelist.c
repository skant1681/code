//merging two sorted linked list
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


void push(node** head, int value)
{
	node* temp = (node* )malloc(sizeof(node* ));
	temp->data = value;
	temp->next = *head;
	*head = temp;
}

node* mergelist(node* head1, node* head2, node* head)
{
	node* ptrtolist1 = head1;
	node* ptrtolist2 = head2;
	node* ptrtosortedlist = head;
	node* temp;

	if (ptrtolist1 == NULL)
		return ptrtolist2;
	else if (ptrtolist2 == NULL)
		return ptrtolist1;
	else
	{

		if (ptrtolist1->data <= ptrtolist2->data)
		{
			ptrtosortedlist = ptrtolist1;
			ptrtolist1 = ptrtolist1->next;
			head = ptrtosortedlist;
		}
		else
		{
			ptrtosortedlist = ptrtolist2;
			ptrtolist2 = ptrtolist2->next;
			head = ptrtosortedlist;
		}
	}

	while(ptrtolist1 != NULL && ptrtolist2 != NULL)
	{
		if(ptrtolist1->data <= ptrtolist2->data)
		{
			//printf("1\n");
			ptrtosortedlist->next = ptrtolist1;
			ptrtolist1 = ptrtolist1->next;
		}
		else
		{
			//printf("2\n");
			ptrtosortedlist->next = ptrtolist2;
			ptrtolist2 = ptrtolist2->next;	
		}
		ptrtosortedlist = ptrtosortedlist->next;
	}

	while(ptrtolist1 != NULL)
	{
		//printf("3\n");
		ptrtosortedlist->next = ptrtolist1;
		ptrtolist1 = ptrtolist1->next;
	}

	while(ptrtolist2 != NULL)
	{
		//printf("4\n");
		ptrtosortedlist->next = ptrtolist2;
		ptrtolist2 = ptrtolist2->next;
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
	node* head1 = NULL;
	node* head2 = NULL;
	node* head = NULL;

	push(&head1,211);
	push(&head1,10);
	push(&head1,4);
	push(&head2,320);
	push(&head2,221);
	push(&head2,18);
	push(&head2,9);
	push(&head2,1);

	printf("First sorted list:\n");
	printlist(head1);
	printf("Second sorted list:\n");
	printlist(head2);

	head = mergelist(head1, head2, head);
	printf("sorted list after merging:\n");
	printlist(head);

	return 0;
}