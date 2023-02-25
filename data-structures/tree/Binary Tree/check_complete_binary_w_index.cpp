#include<iostream>
#include<climits>
#include<cstdlib>
using namespace std;
// Structure for TreeNode
struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};
// Function to Add New Node
struct TreeNode *newNode(int data)
{
    struct TreeNode *new_node=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}
// Function to Calculate Height of LeftMost
int height(struct TreeNode *root)
{
    if(root==NULL)
        return 0;
    return(1 + height(root->left));
}
// Function to check Balance
bool check(int match,int height)
{
    if(((height-match)==0 || (height-match)==1 || (height-match)==-1))
         return true;
    else
        return false;
}
// Function for Complete Binary tree
bool isComplete(struct TreeNode *root,int match,int height)
{
    // Empty Null tree
    if(root==NULL)
    {
        return check(match,height);
    }
    if(root->left==NULL && root->right==NULL)
    {
            return check(match,height);
    }
    int lheight=height,rheight=height;
    if(root->left!=NULL)
        lheight++;
    if(root->right!=NULL)
        rheight++;
    return(isComplete(root->left,match,lheight) && isComplete(root->right,match,rheight));
}
// Driver program
int main(void)
{
    struct TreeNode *root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->right->left=newNode(9);
    root->right->right=newNode(6);
    root->left->left->left=newNode(7);
    root->right->right=newNode(8);
    // function call to isComplete
    int match=height(root);
    if(isComplete(root,match,1))
    {
        cout<<"IT IS A COMPLETE BINARY TREE \n\n";
    }
    else
    {
        cout<<"IT IS NOT A COMPLETE BINARY TREE \n\n";
    }
    return 0;
}
