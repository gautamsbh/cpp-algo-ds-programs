#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#define ALPHABET_LOWER (26)
#define ARRAY_SIZE(arr) sizeof(arr)/sizeof(arr[0])
#define CHAR_TO_INDEX(CH) ((int)CH-(int)'a')
using namespace std;
struct TrieNode
{
    struct TrieNode *children[ALPHABET_LOWER];
    bool isleaf;
};
// Function to Add Node to Trie tree
struct TrieNode *getNode(void)
{
    struct TrieNode *newNode=NULL;
    newNode=(struct TrieNode  *)malloc(sizeof(struct TrieNode));
    // Set Leaf as False
    if(newNode)
    newNode->isleaf=false;
    for(int i=0;i<ALPHABET_LOWER;i++)
    {
            // Initialize all children of the newNode point to Nothing
            newNode->children[i]=NULL;
    }
    return newNode;
};
// function to insert key if there is no key present
void insert(struct TrieNode *root,const char *key)
{
    int length=strlen(key);
    int index,level;
    struct TrieNode *pCrawl=root;
    for(level=0;level<length;level++)
    {
        index=CHAR_TO_INDEX(key[level]);
        if(!pCrawl->children[index])
        {
            pCrawl->children[index]=getNode();
        }
         pCrawl=pCrawl->children[index];
    }
     // Mark it as Leaf Node
     pCrawl->isleaf=true;
}
bool search(struct TrieNode *root,const char *key)
{
    int length=strlen(key);
    int index,level;
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
    return (pCrawl!=NULL && pCrawl->isleaf);
}
// Driver Program
int main()
{
    char key[][8] = {"the", "a", "there", "answer", "any","by", "bye", "their"};
    char output[][32] = {"Not present in trie", "Present in trie"};
    struct TrieNode *root=getNode();
    for(int i=0;i<ARRAY_SIZE(key);i++)
    {
        insert(root,key[i]);
    }
    cout<<output[search(root,"th")]<<endl;
    cout<<output[search(root,"these")]<<endl;
    cout<<output[search(root,"their")]<<endl;
    free(root);
    return 0;
}
