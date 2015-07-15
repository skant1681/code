#include <iostream>
#include <stdio.h>

using namespace std;

struct Treenode
{
	int data;
	struct Treenode* left;
	struct Treenode* right;
};

typedef struct Treenode Treenode;

Treenode* getnewnode(int data)
{
	Treenode* newnode = new Treenode();
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

Treenode* MirrorTree(Treenode* root)
{
	Treenode* temp = NULL;

	if (root == NULL)
		return root;

	temp = root->right;
	root->right = root->left;
	root->left = temp;
	MirrorTree(root->left);
	MirrorTree(root->right);

	return root;
}

void printInorder(Treenode* root)
{
	if(root == NULL)
		return;
	printInorder(root->left);
	cout << root->data << endl;
	printInorder(root->right);
}

int main(int argc, char const *argv[])
{
	Treenode* root = NULL;

	root = getnewnode(1);
	root->left = getnewnode(2);
	root->left->left = getnewnode(3);
	root->left->left->left = getnewnode(4);
	root->right = getnewnode(5);
	root->right->right = getnewnode(6);
	root->right->right->left = getnewnode(7);
	root->right->right->left->left = getnewnode(8);

	printf("Input Tree.\n");
	printInorder(root);

	root = MirrorTree(root);

	printf("Mirror Tree.\n");
	printInorder(root);

	return 0;
}