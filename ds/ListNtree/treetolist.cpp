#include <iostream>
#include <stdio.h>

using namespace std;

struct bstnode
{
	int data;
	struct bstnode* right;
	struct bstnode* left;
};

typedef struct bstnode bstnode;

 bstnode* GetNewNode(int data)
{
	bstnode* newnode = new bstnode();
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}


 bstnode* insert(bstnode* root, int data)
{
	if (root == NULL)
		root = GetNewNode(data);

	else if (data >= root->data)
		root->right = insert(root->right,data);

	else if (data < root->data)
		root->left = insert(root->left, data);

	return root;
}

 void preorder(bstnode* root)
{
	if(root == NULL)
		return;
	printf("%d\n",root->data);
	preorder(root->left);
	preorder(root->right);
}

 bstnode* treetolist(bstnode* root)
{

	bstnode* alist, blist;

	if(root == NULL)
		return NULL;

	alist = treetolist(root->left);
	blist = treetolist(root->right);

	root->left = root;
	root->right = root;

	alist = append(alist, root);
	alist = append(alist, blist);

	return alist;
}

void join(bstnode* a, bstnode* b)
{
    a->right = b;
    b->left = a;
}

 bstnode* append(bstnode* a, bstnode* b)
{
	bstnode* aLast, bLast;

	if (a==NULL) return(b);
    if (b==NULL) return(a);
    
    aLast = a->left;
    bLast = b->left;
    
    join(aLast, b);
    join(bLast, a);
    
    return(a);

}


 void printlist(bstnode* head) {
    bstnode* current = head;
    
    while(current != NULL) {
        printf("%d ", current->data);
        current = current->right;
        if (current == head) break;
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
	bstnode* root = NULL;
	int numofnodes, data, iter;
	//int Height;

	printf("Number of nodes in Binary Search Tree:\n"); 
	scanf("%d",&numofnodes);
	
	for (iter = 0; iter < numofnodes; ++iter)
	{
		printf("Enter data of %dth node:\n",iter + 1);
		scanf("%d",&data);
		root = insert(root,data);
	}

	cout << "preorder traversal of BST.\n";
	preorder(root);

	root = treetolist(root);

	printf("List.\n");
	printlist(root);

	return 0;
}