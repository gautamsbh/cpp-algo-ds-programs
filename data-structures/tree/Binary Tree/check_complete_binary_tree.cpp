#include<iostream>
#include<cstdlib>
#include<climits>
using namespace std;
// Structure to Create a TreeNode
struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};
// Function to add NewNode
struct TreeNode *newNode(int data)
{
    struct TreeNode *new_node=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;
}
// Function to count Nodes
unsigned int countNodes(struct TreeNode *root)
{
    if(root==NULL)
        return 0;
    return(1+ countNodes(root->left) + countNodes(root->right));
}
// Function to Find Complete Binary tree
bool isComplete(struct TreeNode *root,int indexes,unsigned int nodes)
{
    if(root==NULL)
        return true;
    // Check the Indexes
    if(indexes>=nodes)
        return false;
    return(isComplete(root->left,2*indexes+1,nodes) && isComplete(root->right,2*indexes+2,nodes));
}
// Driver Program
int main(void)
{
    // Allocate Root Node
    struct TreeNode *root=newNode(1);
    root->left=newNode(2);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    // Call the isComplete function and Hold Return Boolean Value
    unsigned int nodes=countNodes(root);
    if(isComplete(root,0,nodes))
    {
        cout<<"IT IS A COMPLETE BINARY TREE \n\n";
    }
    else
    {
        cout<<"IT IS NOT A COMPLETE BINARY TREE \n\n";
    }
    return 0;
}
