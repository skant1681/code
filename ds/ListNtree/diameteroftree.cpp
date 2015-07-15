#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

struct bstnode
{
	int data;
	struct bstnode* right;
	struct bstnode* left;
	struct bstnode* parent;
};

typedef struct bstnode bstnode;

 bstnode* GetNewNode(int data)
{
	bstnode* newnode = new bstnode();
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->parent = NULL;
	return newnode;
}


 bstnode* insert(bstnode* root, int data)
{
	if (root == NULL)
		root = GetNewNode(data);

	else if (data >= root->data)
	{
		root->right = insert(root->right,data);
		root->right->parent = root;
	}

	else if (data < root->data)
	{
		root->left = insert(root->left, data);
		root->left->parent = root;
	}

	return root;
}

 void preorder(bstnode* root)
{
	if(root == NULL)
		return;
	printf("%d\n",root->data);
	/*if (root->parent != NULL)
		printf("%d\n",root->parent->data );*/
	preorder(root->left);
	preorder(root->right);
}

int FindHeight(bstnode* root)
{
	int leftTreeHeight = 0, rightTreeHeight = 0;

	if (root == NULL)
		return -1;

	leftTreeHeight = FindHeight(root->left);
	rightTreeHeight = FindHeight(root->right);

	if (leftTreeHeight >= rightTreeHeight)
		return leftTreeHeight + 1;
	else
		return rightTreeHeight + 1;
}

int Finddiameter(bstnode* root)
{
	int leftTreeHeight, rightTreeHeight;
	int leftdiameter = 0, rightdiameter = 0;

	if(root == NULL)
		return 0;

	leftTreeHeight = FindHeight(root->left);
	rightTreeHeight = FindHeight(root->right);

	leftdiameter = Finddiameter(root->left);
	rightdiameter = Finddiameter(root->right);

	if(leftdiameter > rightdiameter && leftdiameter > (leftTreeHeight + rightTreeHeight + 3))
		return leftdiameter;
	else if(rightdiameter > leftdiameter && rightdiameter > (leftTreeHeight + rightTreeHeight + 3))
		return rightdiameter;
	else
		return leftTreeHeight + rightTreeHeight + 3;

}


int main(int argc, char const *argv[])
{
	bstnode* root = NULL;
	int numofnodes, data, iter;
	int diameter;
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

	diameter = Finddiameter(root);

	cout << "Diameter of tree: " << diameter << endl;

	free(root);

	return 0;
}