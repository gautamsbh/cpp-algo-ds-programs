// In Binary tree Takes O(n) complexity to find Max or min Element
// As you have to Traverse every element
#include<iostream>
#include<cstdlib>>
#include<climits>
#include<queue>
using namespace std;
// Structure for TreeNode
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
// Function to Find max Element in Binary tree
int Max(struct TreeNode *root)
{
    // tree is empty
    if(root==NULL)
        return 0;
    int maxi=0;
    queue<struct TreeNode *> que;
    que.push(root);
    struct TreeNode *pCrawl;
    while(!que.empty())
    {
        pCrawl=que.front();
        que.pop();
        if(pCrawl->data > maxi )
            maxi=pCrawl->data;
        // Put Elements of Node
        if(pCrawl->left!=NULL)
          {
            que.push(pCrawl->left);
          }
        if(pCrawl->right!=NULL)
        {
            que.push(pCrawl->right);
        }
    }
    return maxi;
}
// Function to Find Min Element
int Min(struct TreeNode *root)
{
     // tree is empty
    if(root==NULL)
        return 0;
    int mini=INT_MAX;
    queue<struct TreeNode *> que;
    que.push(root);
    struct TreeNode *pCrawl;
    while(!que.empty())
    {
        pCrawl=que.front();
        que.pop();
        if(pCrawl->data < mini )
            mini=pCrawl->data;
        // Put Elements of Node
        if(pCrawl->left!=NULL)
          {
            que.push(pCrawl->left);
          }
        if(pCrawl->right!=NULL)
        {
            que.push(pCrawl->right);
        }
    }
    return mini;
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
    root->right->right=newNode(0);
    // Calling Max Function
    cout<<"Max Element in tree is "<<Max(root)<<" "<<endl;
    // Calling Min Function
    cout<<"Min Element in tree is "<<Min(root)<<" "<<endl;
    cout<<"\n\n Find max Min using BFS Traversal Algorithm";
}
