#include<iostream>
#include<cstdlib>
#include<climits>
#include<queue>
using namespace std;
// Structure for Binary tree
struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};
// Function to Allocate New Node
struct TreeNode *newNode(int data)
{
    struct TreeNode *new_node=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}
// Function to Add Sum of Left Subtree
int left_sum(struct TreeNode *root)
{
    // Bottom Up Approach
    if(root==NULL)
        return 0;
    // If it is a Leaf Node
    if(root->left==NULL && root->right==NULL)
        return root->data;
    // Then Consecutive Recursion for Bottom up
    int left=left_sum(root->left);
    int right=left_sum(root->right);
    // Add Root Data To Left
    root->data+=left;
    return root->data+right;
}
// tree Order Level Traversal
void bfs(struct TreeNode *root)
{
    queue<struct TreeNode *> que;
    que.push(root);
    struct TreeNode *pCrawl;
    while(!que.empty())
    {
        pCrawl=que.front();
        cout<<pCrawl->data<<" ";
        que.pop();
        // Push Elements
        if(pCrawl->left!=NULL)
            que.push(pCrawl->left);
        if(pCrawl->right!=NULL)
            que.push(pCrawl->right);
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
    root->right->left=newNode(6);
    root->right->right=newNode(7);
    left_sum(root);
    // tree Traversal Level Order
    bfs(root);
    return 0;
}
