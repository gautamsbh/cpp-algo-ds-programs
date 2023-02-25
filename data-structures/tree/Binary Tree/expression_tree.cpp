#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<stack>
using namespace std;
// Structure for TreeNode
struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};
// Function to Create a New Node
struct TreeNode *newNode(int data)
{
    struct TreeNode *new_node=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}
// Function to Check whether the character is operator
bool isOperator(char ch)
{
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
        return true;
    else
        return false;
}
// Function for Creating Expression tree
void expression_tree(struct TreeNode *root,char ch[],int size_exp)
{
    // tree is Null
    // First Start by allocating stack
    stack<struct TreeNode *> store;
    struct TreeNode *current,*pop,*poped;
    cout<<size_exp;

}
// Expression tree Traversal in infix fashion
void inorder(struct TreeNode *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
// Driver Program
int main(void)
{
    // input the Sequence
    char ch[50];
    scanf("%s",ch);
    int exp_size=strlen(ch);
    struct TreeNode *root=NULL;
    // Call the Expression tree
    expression_tree(root,ch,exp_size);
    return 0;
}
