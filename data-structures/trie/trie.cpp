#include<iostream>
#include<cmath>
#include<memory>
#include<typeinfo>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;

typedef struct node {
    node* childrens[26]; // Array of Pointer of size 26, To store contact list
    bool endOfString;  // Store the iteration of the string
} node;

// Create a New Node of the Trie data-structures
node* instantiate() {
    // Create a New node
    auto newNode = new node;
    newNode -> endOfString = false;
    for(int i =0; i< 26; i++) {
        newNode -> childrens[i] = NULL;
    }
    return newNode;
}

//Trie Class (Abstract Data Type)
class Trie {
public:
    // Insert the new Element in the Trie
    node* insert(node *root, string str) {
        // First Traverse through the trie and check if the entry exists
        if(str.compare("") == 0) {
            fprintf(stderr, "%s\n", "Sorry! you cannot insert empty or Null String");
            return NULL; // If string is empty through an error message
        }
        // Temporary Travesal
        node* temp = root;
        // Itertate over the Trie structure and get deep in to Trie.
        // If not found then allocate the memory and intialize the same
        for(int i=0;i<str.size(); i++) {
            int now = str[i] - 'a';
            // check if the root has that node created
            if(! temp->childrens[now]) {
                // Create a New Instance
                temp -> childrens[now] = instantiate();
            }
            temp = temp -> childrens[now];
        }   temp -> endOfString = true;
    }
    // Search a Element in the Trie Datastructure
    bool search(node *root, string str) {
        if(str.compare("") == 0) {
            fprintf(stderr, "%s\n", "Sorry! you cannot insert empty or Null String");
            exit(0);
        }
        // Temporary Travesal
        node* temp = root;
        // Itertate over the Trie structure and get deep in to Trie.
        // If not found then allocate the memory and intialize the same
        for(int i=0;i<str.size(); i++) {
            int now = str[i] - 'a';
            // check if the root has that node created
            if(temp -> childrens[now] == NULL) {
                return false;
            }
            temp = temp -> childrens[now];
        }
        return (temp != NULL && temp->endOfString);
    }

    // Suggesting the right keyword
    void prefix(node* root, string str) {
        // Check the string if the search case is valid
        if(str.compare("") == 0) {
            fprintf(stderr, "%s\n", "Sorry! you cannot insert empty or Null String");
            exit(0);
        }

        // Temporary Travesal
        node* temp = root;
        // Itertate over the Trie structure and get deep in to Trie.
        // If not found then allocate the memory and intialize the same
        for(int i=0;i<str.size(); i++) {
            int now = str[i] - 'a';
            // check if the root has that node created
            if(temp -> childrens[now] == NULL) {
                return;
            }
            temp = temp -> childrens[now];
        }
        // If temp is not null, then traverse the sub TrieInstance
        traverse(*temp, str);
    }
    // Print the Whole Trie Structure
    void traverse(node const& root, string& str) {
        // Write a recusive function having a prefix and the vector of stored
        if(root.endOfString == true) {
            for(auto it = str.begin(); it != str.end(); it++) {
                cout<<*it;
            }
            cout<<endl;
        }
        auto temp = root;
        for(int i=0; i<26; i++) {
            // Store the prefix and call the traverse function
            if(temp.childrens[i] != NULL) {
                // push the character
                char ch = 'a' + i;
                str.push_back(ch);
                traverse(*(temp.childrens[i]), str);
                str.pop_back();
            }
        }
    }
};


// Driver Program
auto main() -> int {
    cout<<"Perform the Trie data-structures Oprtation"<<endl;
    // create a New Object of trie
    auto TrieInstance = new Trie();
    auto root = instantiate();
    TrieInstance->insert(root, "laravel");
    TrieInstance->insert(root, "falcon");
    TrieInstance->insert(root, "laravelio");
    TrieInstance->insert(root, "falconfighter");
    TrieInstance->insert(root, "laravellumen");
//    TrieInstance->search(root, "laraveli") ? cout<<"Element Found \n" : cout<<"Element not found\n";
    string prin;
//    TrieInstance->traverse(*root, prin);
//    TrieInstance->prefix(root, "lar");
    return 0;
}
