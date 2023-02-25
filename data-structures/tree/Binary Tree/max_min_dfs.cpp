// Now Finding max and Min Element using DFS
// The Complexity Remains Sam
#include<iostream>
#include<cstdlib>
#include<stack>
#include<climits>
using namespace std;
// Structure For binary tree
struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};
// Function to Create New Node
struct TreeNode *newNode(int data)
{
    struct TreeNode *new_node=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}
// Function To Find Max
int Max(struct TreeNode *root)
{
    if(root==NULL)
        return INT_MIN;
    int res=root->data;
    int lres=Max(root->left);
    int rres=Max(root->right);
    if(lres>res)
        res=lres;
    if(rres>res)
        res=rres;
    return res;
}
int Min(struct TreeNode *root)
{
    if(root==NULL)
        return INT_MAX;
    int res=root->data;
    int lres=Min(root->left);
    int rres=Min(root->right);
    if(lres<res)
        res=lres;
    if(rres<res)
        res=rres;
    return res;
}
// Driver Program
int main(void)
{
   struct TreeNode *root=newNode(1);
   root->left=newNode(2);
   root->right=newNode(3);
   root->left->right=newNode(4);
   root->left->right=newNode(5);
   root->right->right=newNode(0);
   // Call Max and Min Function
   cout<<"Max Element Find is "<<Max(root)<<endl;
   cout<<"Min Element Find is "<<Min(root)<<endl;
return 0;
}
