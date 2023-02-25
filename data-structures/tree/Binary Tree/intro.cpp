#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;
// Structure for tree Node
struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};
// Function to Allocate New node
struct TreeNode *newNode(int data)
{
    struct TreeNode *new_node=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}
// Traversal Pre Order
void preorder(struct TreeNode *root)
{
    if(root!=NULL)
       {    cout<<root->data<<" ";
            preorder(root->left);
            preorder(root->right);
       }
}
// In Order tree Traversal
void inorder(struct TreeNode *root)
{
    if(root!=NULL)
        { inorder(root->left);
          cout<<root->data<<" ";
          inorder(root->right);
        }
}
// Function for Post Order Traversal
void postorder(struct TreeNode *root)
{
    if(root!=NULL)
     {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
     }
}
// Driver Program
int main(void)
{
    struct TreeNode *root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    // Calling Traversal Function
    cout<<"\n\n";
    preorder(root);
    cout<<"\n\n";
    inorder(root);
    cout<<"\n\n";
    postorder(root);
    cout<<"\n\n";
}
