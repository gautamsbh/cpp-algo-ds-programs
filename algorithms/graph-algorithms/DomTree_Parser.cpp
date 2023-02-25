#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>
using namespace std;

class DomNode {
    public:
        int tagName;
        int *next;
        vector<string> attributes;
        vector<string> split(string);
        DomNode(string tagLine) {
            // Trim the Tags
            string trimmed = tagLine.substr(1,tagLine.length-1);
            // Split the string
            vector<string> s_array = split(trimmed);
            this.tagName = s_array[0];
            for(int i=1; i< !s_array[i].empty(); i++) {
                this.attributes.push_back(s_array[i]);
            }
        }
}
vector<string> DomNode::split(string tagLine) {
    vector<string> result;
    vector<char> intermediate;
    if(tagLine.empty()) {
        return result;
    }
    for(int i=0;i<tagLine.size();i++) {
        if(tagLine[i] == ' ' && tagLine[i] == '\0') {
            result.push_back(intermediate);
        }
        intermediate.push_back(tagLine[i]);
    }
    return result;
}

class DomTree {
    public:
        int nodes;
        DomNode curr_node = Null;
        void insert(string tagLine);
        void remove(string tagLine);
        void traverse();
        DomNode find(string TagLine);
        DomTree() {
            this.nodes = 0;
        }
}
void DomTree::insert(string tagLine) {
        // Create a New DomNode and Insert them
        DomNode new_node(tagLine);
        if(this.DomNode == NULL) {
            this.DomNode = new_node;
        }

}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
