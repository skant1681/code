#include <iostream>
#include <stdio.h>
#include <stack>

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

void spiralprint(bstnode* root)
{
	if(root == NULL)
		return;
	stack<bstnode*> stack1, stack2;
	bstnode* current;

	cout << root->data << endl;
	stack1.push(root->right);
	stack1.push(root->left);

	while(!stack1.empty())
	{
		while(!stack1.empty())
		{
			current = stack1.top();

			if(current->left != NULL)
				stack2.push(current->left);

			if(current->right != NULL)
				stack2.push(current->right);

			cout << current->data << endl;
			stack1.pop();
		}

		while(!stack2.empty())
		{
			current = stack2.top();

			if(current->left != NULL)
				stack1.push(current->left);

			if(current->right != NULL)
				stack1.push(current->right);

			cout << current->data << endl;
			stack2.pop();
		}
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

	cout << "spiral form of level order.\n";
	spiralprint(root);

	return 0;
}