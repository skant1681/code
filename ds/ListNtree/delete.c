#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node* left;
    struct node* right;
};

int max(a,b)
{
(a>b) ? a:b;
} 
 
int height(struct node* node1) {
    int x;
    if(node1 == NULL)
    return -1 ;
    else 
    {
    int lheight = height(node1->left);
    int rheight = height(node1->right);
 
     x= (1+max(lheight,rheight));
    return x;
    }
} 
struct node* newNode(int data) 
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}
    
int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5); 
    root->left->right->left = newNode(41);
    root->left->right->right = newNode(87)
    printf("Hight of tree is %d", height(root));
    return 0;
}