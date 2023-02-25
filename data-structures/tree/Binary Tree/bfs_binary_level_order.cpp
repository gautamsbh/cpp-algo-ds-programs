#include<iostream>
#include<cstdlib>
#include<utility>
#include<algorithm>
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
}
// Function For Level Order Traversing
// Breadth First Search(BFS)
void bfs_binary(struct TreeNode *root)
{
    // For BFS You Need a Looping Structure only
    // Time Complexity is O(n) & Space Complexity is O(n)
    queue<struct TreeNode *> quetree;
    quetree.push(root);
    while(!quetree.empty())
    {
        struct TreeNode *pCrawl=quetree.front();
        cout<<pCrawl->data<<" ";
        if(pCrawl->left!=NULL)
            quetree.push(pCrawl->left);
        if(pCrawl->right!=NULL)
            quetree.push(pCrawl->right);
        quetree.pop();
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
    bfs_binary(root);
    return 0;
}
