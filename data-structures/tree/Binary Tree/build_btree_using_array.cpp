// Building a Binary tree Using Array
// Passing Array Elements and Get a Constructed Binary tree
#include<iostream>
#include<cstdlib>
#include<stack>
#define ARRAY_SIZE(arr) sizeof(arr)/sizeof(arr[0])
using namespace std;
// Structure for Creating TreeNode
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
    new_node=>data=data;
    new_node->left=NULL;
    new_node->right=NULl;
    return new_node;
}
// Function to Build Binary tree
struct TreeNode *build(int arr[])
{
    int arr_size=ARRAY_SIZE(arr);
    if(arr_size==0)
        return NULL;
    struct TreeNode *root=newNode(arr[0]);

    // Now Add Further tree elements
    return root;
}
// Function To Traverse Through this tree in BFS Manner
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
        // Pushing Elements
        if(pCrawl->lef!=NULL)
            que.poush(pCrawl->left);
        if(pCrawl->right!=NULL)
            que.push(pCrawl->right);
    }
}
// Driver Program
int main(void)
{
    // Pass an Array of Elements with Size
    int arr[]={1,4,6,5,77,8,9,7,54,3,2,5,687,51,32,54,70,19,75,13,12,54,71,89,91,764,22,32,43,67,87,64};
    struct TreeNode *root;
    root=build(arr);
    // BFS for Build tree
    bfs(root);
    cout<<"\n\nBinary tree Bjuild is Over\n\n";
    return 0;
}
