#include<iostream>
#include<vector>
#include<cstdlib>
#include<time.h>
using namespace std;
// Structure For tree
struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};
// Function to add newNode
struct TreeNode *newNode(int data)
{
    struct TreeNode *new_node=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;
}
// Function to Find max
int max(int first,int second)
{
    return((first>=second)?first:second);
}
// Function to Calculate Height
// For Diameter max
int height(struct TreeNode *root)
{
    if(root==NULL)
        return 0;
    return(1+max(height(root->left),height(root->right)));
}
// Function to calculate Diameter
int diameter(struct TreeNode *root)
{
    if(root==NULL)
        return 0;
    int lh=height(root->left);
    int rh=height(root->right);
    // Calculate the diameter
    int ldiameter=diameter(root->left);
    int rdiameter=diameter(root->right);
    cout<<lh<<" "<<rh<<" "<<ldiameter<<" "<<rdiameter<<endl;
    return max(lh+rh+1,max(ldiameter,rdiameter));
}
// Optimized code
// Calling both at Once
/***
int diameter(struct TreeNode *root,int *height)
{
    int lh=0,rh=0;
    int ldiameter=0,rdiameter=0;
    if(root==NULL)
       *height=0, return 0;
    int ldiameter=diameter(root->left,&lh);
    int rdiameter=diameter(root->height,&rh);
    int *height=max(lr,rb)+1;
    return(lh+rh+1,max(ldiameter,rdiameter));
}
***/
// Driver Program
int main(void)
{
    clock_t __start=clock();
    struct TreeNode *root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    // Function calling
    cout<<"Diameter is : "<<diameter(root);
    clock_t __end=clock();
    double val=(double)(__end - __start)/CLOCKS_PER_SEC;
    cout<<"\nTime Consumed by Processor : "<<val;
    return 0;
}
