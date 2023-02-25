#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;
// Structure for TreeNode
struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};
// Function to Add NewNode
struct TreeNode *newNode(int data)
{
        struct TreeNode *new_node=(struct TreeNode *)malloc(sizeof(struct TreeNode));
        new_node->data=data;
        new_node->left=NULL;
        new_node->right=NULL;
    return new_node;
}
// Function to Find Max
int max(int a,int b)
{
    return (a>=b)?a:b;
}
// Function to Find Max_Height with Time Complexity O(n)
int max_height(struct TreeNode *root)
{
    if(root==NULL)
        return 0;
    // Recursive
    int height=1+max(max_height(root->left),max_height(root->right));
    cout<<"Height is : "<<height<<endl;
    return(height);
}
// Driver Program
int main(void)
{
    struct TreeNode *root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    // Call max_height
    cout<<"Max Height Of Binary tree : "<<max_height(root);
    return 0;
}
