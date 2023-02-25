#include<iostream>
#include<vector>
#include<cstdlib>
#include<stack>
using namespace std;
// Structure for TreeNode
struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};
// Function Allocate New Nodes
struct TreeNode *newNode(int data)
{
  struct TreeNode *new_node=(struct TreeNode *)malloc(sizeof(struct TreeNode));
  new_node->data=data;
  new_node->left=NULL;
  new_node->right=NULL;
return new_node;
}
// Function For In Order Non-Recursive Approach
void inorder(struct TreeNode *root)
{
    stack<struct TreeNode *> stack_in;
    // Input First element
    struct TreeNode *pCrawl=root;
    bool done=0;
    while(!done)
    {
        if(pCrawl!=NULL)
        {
            stack_in.push(pCrawl);
            pCrawl=pCrawl->left;
        }
        else
        {
            if(!stack_in.empty())
            {
                pCrawl=stack_in.top();
                stack_in.pop();
                cout<<pCrawl->data<<" ";
                pCrawl=pCrawl->right;
            }
            else
            {
                done=1;
            }
        }
    }

}
int main(void)
{
    struct TreeNode *root=newNode(1);
    root->right=newNode(2);
     root->right->right=newNode(4);
     root->right->right->right=newNode(5);
     inorder(root);
    cout<<"Inorder Traversal With Recursion Using Stack";
}
