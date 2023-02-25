#include<iostream>
#include<cstdlib>
using namespace std;
// Structure for TreeNode
struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};
// Function to Allocate new node
struct TreeNode *newNode(int data)
{
    struct TreeNode *new_node=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;
    return  new_node;
}
// Function For in-Order Traversal by Morris method
void inorder_morris(struct TreeNode *root)
{
    if(root==NULL)
        return;
    struct TreeNode *current=root,*pre;
    while(current!=NULL)
    {
        if(current->left==NULL)
           {
               cout<<current->data<<" ";
               current=current->right;
           }
        else
            {
                pre=current->left;
                while(pre->right!=NULL && pre->right==current)
                    pre=pre->right;
          if(pre->right==NULL)
            {
                    pre->right=current;
                    current=current->left;
            }
           else
            {
                    pre->right=NULL;
                    cout<<current->data<<" ";
                    current=current->left;
             }
         }
     }
}
// Drive Program
int main(void)
{
    struct TreeNode *root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    // function call for In order Traversal
    inorder_morris(root);
    return 0;
}
