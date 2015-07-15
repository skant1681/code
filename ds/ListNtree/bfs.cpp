#include <iostream>
#include <stdio.h>
#include <queue>

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

void levelOrder(bstnode* root)
{
	if(root == NULL)
		return;
	queue<bstnode*> myQ;
	myQ.push(root);

	while(!myQ.empty())
	{
		bstnode* current = myQ.front();
		cout << current->data << endl;
		if(current->left != NULL)
			myQ.push(current->left);
		if(current->right != NULL)
			myQ.push(current->right);
		myQ.pop();
	}
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

	cout << "Level order traversal. \n";
	levelOrder(root);

	return 0;
}