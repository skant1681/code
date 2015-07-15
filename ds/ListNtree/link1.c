//traversing a linked list

#include <stdio.h>
#include <stdlib.h>
 
 struct node
 {
 	int data;
 	struct node* next;
 };

 

 typedef struct node node; 	//node can be used as datatype instead of struct node 

 void insert(struct node* head)
 {
 	struct node* p = NULL;
 	struct node* q = NULL;

 	p = head;
 	while(p != NULL)
 	{
 		if(p->data == 200)
 		{
 			struct node* temp = NULL;
 			temp = (struct node* )malloc(sizeof(struct node* )); 

 			if(p->next == NULL)
 			{
 				p->next = temp;
 				temp->next = NULL;
 				temp->data = 250;
 				p = temp;
 			}

 			else
 			{
 				q = p->next;
 				p->next = temp;
 				temp->next = q;
 				temp->data = 250;
 				p = q;
 			}
 		}
 		else 
 			p = p->next;
 			
 		}
 	} 	 
 
 node *deletefirstnode(node* head)
 {
 	if(head == NULL)
 		return;
 	else
 	{
 		node* temp = head;
 		head = head->next;
 		free(temp);
 	}
 	return head;
 }

void printlist(struct node* n)
{
	while(n != NULL)
	{
		printf("%d\n",n->data);
		n = n->next;
	}
}

int main()
 {
 	/* code */
 	struct node* first = NULL;
 	struct node* second = NULL;
 	struct node* third = NULL;
 	
 	struct node** p;

 	struct node* head;
 	

 	first = (struct node* )malloc(sizeof(struct node* )); 
 	second = (struct node* )malloc(sizeof(struct node* ));
 	third = (struct node* )malloc(sizeof(struct node* ));

 	head = first;

 	first->data = 200;
 	first->next = second;

 	second->data = 200;
 	second->next = third;

 	third->data = 23;
 	third->next = NULL;

 	p = &head;

 	printf("%d\n",(*p)->data );
 	printf("before inserting\n");

 	printlist(head);

 	insert(head);
 	printf("%p\n", head );
 	printf("after inserting\n");
 	printf("%p\n", first );
 	printlist(first);

 	printf("after deleting first node \n");
 	head = deletefirstnode(head);
 	printlist(head);

 	return 0;
 }