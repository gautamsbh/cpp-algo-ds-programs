#include<iostream>
#include<vector>
#include<cstdlib>
#include<cstring>
#define ALPHABET (26)
#define CHAR_TO_INDEX(CH) ((int)CH-(int)'a')
#define FREE(PO) free(PO); PO=NULL;
#define ARRAYSIZE(ARRAY) sizeof(ARRAY)/sizeof(ARRAY[0])
using namespace std;
// Structure of Trie
struct TrieNode
{
    struct TrieNode *children[ALPHABET];
    int count;
    bool isleaf;
    int value;
};
// Function to allocate Trie Node
struct TrieNode *getNode(void)
{
    struct TrieNode *newNode=NULL;
    newNode=(struct TrieNode *)malloc(sizeof(struct TrieNode));
    // Check if Memory is Allocated other throw error
    // As malloc on failure returns NULL pointer
    newNode->value=0;
    if(newNode)
    {   //Initialize variable
        newNode->isleaf=false;
        newNode->count=0;
        // Initialize all values with NULL for its child pointers
        for(int i=0;i<ALPHABET;i++)
        {
        newNode->children[i]=NULL;
        }
    }
    return newNode;
};
// Function to Insert Trie Nodes
void insert(struct TrieNode *root,char key[])
{
    int length=strlen(key);
    int index,level;
    struct TrieNode *pCrawl=root;
    root->count++;
    for(level=0;level<length;level++)
    {
        index=CHAR_TO_INDEX(key[level]);
        if(!pCrawl->children[index])
        {
            // Allocate New Node for pCrawl->children[index]
            pCrawl->children[index]=getNode();
        }
        pCrawl=pCrawl->children[index];
        pCrawl->count=+1;
        pCrawl->value+=1;
    }
    pCrawl->isleaf=true;
    pCrawl->value=root->count;
}
// Function to Search for word
bool search(struct TrieNode *root,char key[])
{
    int length=strlen(key);
    int index,level;
    struct TrieNode *pCrawl=root;
    for(level=0;level<length;level++)
    {
        index=CHAR_TO_INDEX(key[level]);
        if(!pCrawl->children[index])
        {
            return false;
        }
        pCrawl=pCrawl->children[index];
    }
    return (pCrawl!=NULL && pCrawl->isleaf);
}
// Deletion on Trie
// Few Cases to Consider while performing delete operation on trie
// 1) If Key is Not found then no modify in trie
// 2) If key is found and its a prefix of another key then unmask it leaf node
// 3) if Key is unique and no prefix then recursively delete that node
// 4) if key is found, and having at least one other key as prefix key then Delete nodes from end of key until first leaf node of longest prefix key.

// Some Utility function to Help Deletion
int leafNode(struct TrieNode *root)
{
    return (root->value!=0);
}
int IsItFreeNode(struct TrieNode *root)
{
    struct TrieNode *pCrawl=root;
    for(int i=0;i<ALPHABET;i++)
    {
        if(pCrawl->children[i])
        {
            return 0;
        }
    }
    return 1;
}
bool deleteHelper(struct TrieNode *root,char key[], int level,int length)
{
    struct TrieNode *pCrawl=root;
    if(pCrawl)
    {
        // Base Case
        if(level==length)
        {
            if(pCrawl->value)
            {
                // Unmark the leaf Node
                pCrawl->value=0;
                // If empty Node is deleted
                if(IsItFreeNode(pCrawl))
                {
                    return true;
                }
                return false;
            }
        }
        else // Recursive case
        {
            int index=CHAR_TO_INDEX(key[level]);
            if(deleteHelper(pCrawl->children[index],key,level+1,length))
            {
                // Last Node Marked Delete it
                FREE(pCrawl->children[index]);
                // Recursively Climb up and Delete Eligible Node
                return (!leafNode(pCrawl) && IsItFreeNode(pCrawl));
            }
        }
    }
    return false;
}
void deletekey(struct TrieNode *root,char key[])
{
    int length=strlen(key);
    if(length>0)
    {
            deleteHelper(root,key,0,length);
    }
}
// Driver Program
int main()
{
    char key[][8]={"ans","answer","ansper","pigeon","world","notso","fly","sky"};
    // Create Trie Root Having Null Values
    struct TrieNode *root=getNode();
    root->count=0;
    for(int i=0;i<ARRAYSIZE(key);i++)
    {
        insert(root,key[i]);
    }
    // Search for Keys on Trie
    deletekey(root,"answer");
    deletekey(root,"ansper");
    cout<<(search(root,"answer")==0?"Not Found":"Found Key")<<endl;
    cout<<(search(root,"ansy")==0?"Not Found":"Found Key")<<endl;
    cout<<(search(root,"world")==0?"Not Found":"Found Key")<<endl;
    cout<<(search(root,"notse")==0?"Not Found":"Found Key")<<endl;
    return 0;
}
