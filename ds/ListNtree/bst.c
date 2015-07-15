//binary search tree, creation, searching, height of tree are implemented

#include <stdio.h>
#include <stdlib.h>

struct bstnode
{
	int data;
	struct bstnode* right;
	struct bstnode* left;
};

typedef struct bstnode bstnode;

bstnode* GetNewNode(int data)
{
	bstnode* newnode = NULL;
	newnode = (bstnode* )malloc(sizeof(bstnode ));
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

int FindHeight(bstnode* root)
{
	int leftTreeHeight = 0, rightTreeHeight = 0;

	if (root == NULL)
		return -1;

	leftTreeHeight = FindHeight(root->left);
	rightTreeHeight = FindHeight(root->right);

	//return (1+ max(leftTreeHeight,rightTreeHeight));

	if (leftTreeHeight >= rightTreeHeight)
		return leftTreeHeight + 1;
	else
		return rightTreeHeight + 1;
}

int searchnode(bstnode* root, int data)
{
	if (root == NULL)
	{
		printf("Not Found\n");
		return;
	}

	else if (data == root->data)
	{
		printf("Found\n");
		return;
	}
	else if (data >= root->data)
		searchnode(root->right, data);

	else if (data < root->data)
		searchnode(root->left, data);
}

void preorder(bstnode* root)
{
	if(root == NULL)
		return;
	printf("%d\n",root->data);
	preorder(root->left);
	preorder(root->right);
}

int main()
{
	/* code */
	bstnode* root = NULL;
	int numofnodes, data, iter;
	int Height;

	printf("Number of nodes in Binary Search Tree:\n"); 
	scanf("%d",&numofnodes);
	
	for (iter = 0; iter < numofnodes; ++iter)
	{
		printf("Enter data of %dth node:\n",iter + 1);
		scanf("%d",&data);
		root = insert(root,data);
	}

	Height = FindHeight(root);
	printf("Height of tree is %d\n",Height);

	printf("Enter data to search:\n");
	scanf("%d",&data);

	searchnode(root,data);

	printf("preorder traversal of tree\n");
	preorder(root);

	free(root);

	return 0;
}