#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<deque>
#include<process.h>
#include<fstream>
#define ALPHA (26)
#define CHAR_TO_INDEX(CH) ((int)CH- (int)'a')
#define FREE(ptr) free(ptr); ptr=NULL;
#define ARRAY_SIZE(array) sizeof(array)/sizeof(array[0])
using namespace std;
// Structure for TrieNode
struct TrieNode
{
    struct TrieNode *children[ALPHA];   // Trie Children Node Contain Pointer to Point Other Children key
    long long contact;
    int value;
    int count;
    bool isLeaf;
};
// Function to Allocate Trie Node
struct TrieNode *getNode()
{
    struct TrieNode *newNode=(struct TrieNode *)malloc(sizeof(struct TrieNode));
    newNode->isLeaf=false;
    newNode->value=0;
    newNode->count=0;
    // Initialize all children to NULL Pointer
    for(int i=0;i<ALPHA;i++)
        newNode->children[i]=NULL;
    // Return The NewNode
    return newNode;
};
// Function to Insert Key in Trie
void insert(struct TrieNode *root,char key[],long long contact)
{
    // Input Values until keys are Reached
    int length=strlen(key);
    int index,level;
    root->count++;
    // Crawl the Trie Node
    struct TrieNode *pCrawl=root;
    for(int level=0;level<length;level++)
    {
        index=CHAR_TO_INDEX(key[level]);
        if(!pCrawl->children[index])
        {
            // If There is No Index Available Create New TrieNode
            pCrawl->children[index]=getNode();
        }
        pCrawl=pCrawl->children[index];
        pCrawl->value+=1;
        pCrawl->count+=1;
    }
    pCrawl->isLeaf=true;
    pCrawl->value=pCrawl->count;
    pCrawl->contact=contact;
    return;
}
// Search Function to Find Keys for a Particular key
bool find(struct TrieNode *root,char key[])
{
    int length=strlen(key);
    int level,index;
    struct TrieNode *pCrawl=root;
    for(int level=0;level<length;level++)
    {
        index=CHAR_TO_INDEX(key[level]);
        if(!pCrawl->children[index])
        {
            return false;
        }
        pCrawl=pCrawl->children[index];
    }
    return (pCrawl!=NULL && pCrawl->isLeaf);
}
// Function Traverse Trie
void traverse_trie(struct TrieNode *node,string prefix)
{
    if(node->isLeaf==true)
    {
        cout<<"Contact : "<<prefix<<" : "<<node->contact<<"\n\n";
    }
    for(int index=0;index<ALPHA;index++)
    {
        char next='a'+index;
        if(node->children[index]!=NULL)
        {
            prefix.push_back(next);
            traverse_trie(node->children[index],prefix);
            prefix.pop_back();
        }
    }
}
// Function to Print All Contact with the Prefix
void common_prefix(struct TrieNode *root,char key[])
{
    // We Have to traverse all prefix thus Using Graph traversal Algorithm
    int length=strlen(key);
    int level,index;
    struct TrieNode *pCrawl=root;
    for(level=0;level<length;level++)
    {
        index=CHAR_TO_INDEX(key[level]);
        if(!pCrawl->children[index])
        {
            cout<<"Sorry No Such Key is Found\n\n";
            return;
        }
        pCrawl=pCrawl->children[index];
    }
    // If Prefix is Key Print Contact
    if(pCrawl->isLeaf==true)
    {
        cout<<"Key Contact : "<<key<<" : "<<pCrawl->contact<<"\n\n";
    }
    // Print All Suggestions
    traverse_trie(pCrawl,key);
    return;
}
// function to Verify its Leaf Node
int leafNode(struct TrieNode *root)
{
    return (root->value!=0);
}
// Function For Finding for free Node
int IsItFreeNode(struct TrieNode *root)
{
    struct TrieNode *pCrawl=root;
    for(int i=0;i<ALPHA;i++)
    {
        if(pCrawl->children[i])
        {
            return 0;
        }
    }
    return 1;
}
// function DeleteHelper
bool deleteHelper(struct TrieNode *root,string key,int level,int length)
{
    struct TrieNode *pCrawl=root;
    if(pCrawl)
    {
        //Base Case
        if(level==length)
        {
            if(pCrawl->value)
            {
                // Unmark the Leaf Node
                pCrawl->value=0;
                if(IsItFreeNode(pCrawl))
                {
                    return true;
                }
                return false;
            }
        }
    else
    {
        int index=CHAR_TO_INDEX(key[level]);
        if(deleteHelper(pCrawl->children[index],key,level+1,length))
        {
            FREE(pCrawl->children[index]);
            return (!leafNode(pCrawl) && IsItFreeNode(pCrawl));
        }
    }
  }
    return false;
}
// Function to Delete the Keys of Trie
void delete_trie(struct TrieNode *root, string key)
{
    // There are Four Cases to be Considered while Deleting Keys
    // 1) If Key is Not Found. No Modification on Trie
    // 2) If key is Present and is prefix of Other key. then unmask it
    // 3) If key is unique key no such prefix exist. Then recursively delete key
    // 4) 4) if key is found, and having at least one other key as prefix key then Delete nodes from end of key until first leaf node of longest prefix key.
    int length=key.size();
    if(length>0)
    {
        deleteHelper(root,key,0,length);
    }
}
// Function Children Count
int childrenCount(struct TrieNode *node,int *index)
{
    int count=0;
    for(int i=0;i<ALPHA;i++)
    {
        if(node->children[i]!=NULL)
        {
            count++;
            *index=i;
        }
    }
    return (count);
}
// Function to Print Longest Common Prefix
void longest_common_prefix(struct TrieNode *root,string prefix)
{
    struct TrieNode *pCrawl=root;
    int index=0;
    while(childrenCount(pCrawl,&index)==1 && pCrawl->isLeaf==false)
    {
        char next='a'+index;
        prefix.push_back(next);
        pCrawl=pCrawl->children[index];
    }
    if(prefix.size()>0)
    {
        cout<<"Longest Prefix is "<<prefix<<"\n\n";
    }
    else
    {
        cout<<"No Prefix Found "<<endl;
    }
    return;
}
int main(int argc,char **argv)
{
    char keys[][10]={"rihana","ricky","rihanb","rion","rinswer","rihan","rifiserv","rinucleus"};
    long long contact[]={9988776655,9078657890,8976566558,9867540972,8967564534,3998871223,8908908888,9089909801};
    // Build Trie with Keys & Contacts
    // Allocate Trie Root
    struct TrieNode *root=getNode();
    root->count=0;
    for(int i=0;i<ARRAY_SIZE(keys);i++)
    {
        insert(root,keys[i],contact[i]);
    }
    // Now its Time to fire Query
    char output[][32]={"Key Not Found\n","Hurrah! Key found\t"};
    cout<<output[find(root,"rihana")];
    // Delete Keys Of Trie
    delete_trie(root,"rion");
    delete_trie(root,"ricky");
    // Show All Contact with Prefixes
    common_prefix(root,"ri");
    // Find Longest Common Prefix
    string long_pre="";
    longest_common_prefix(root,long_pre);
    // Good Bye
    return 0;
}
