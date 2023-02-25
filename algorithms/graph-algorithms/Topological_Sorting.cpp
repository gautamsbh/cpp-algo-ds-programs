/**
*
*
*@author          gautam-singh<gautam.bhadauria@crownstack.com>
*@program         Topological Sorting
*@description     Topological Sorting for the Directed Acyclic Graph
 */

#include<iostream>
#include<vector>
#include<stack>

using  namespace std;

/**
* Add Edges to directed Acyclic Graph
 */
void addEdges(vector<int> adj[], int start, int end) {
  adj[start].push_back(end);
}

/**
* topological sorting utility function
 */
void topologicalUtil(vector<int> adj[], int start, vector<bool> &visited, stack<int> &Stack) {
  visited[start] = true;
  for(auto it=adj[start].begin(); it != adj[start].end(); it++) {
    if(visited[*it] == false) {
        topologicalUtil(adj, *it, visited, Stack);
    }
  }
  Stack.push(start);
}

/**
* Topolocal Sorting Function
 */

void topological(vector<int> adj[], int nodes) {
    vector<bool> visited(nodes, false);
    stack<int> Stack;
    for(int i=0;i<nodes; i++) {
      if(visited[i] == false) {
            topologicalUtil(adj, i, visited, Stack);
      }
    }
    /** Print whole stack */
    while(Stack.empty() == false) {
      cout<<Stack.top()<<" ";
      Stack.pop();
    }
}

/**
* Driver Program
 */
int main(int argc, char *argv[]) {
  int nodes, edges, start, end;
  cin>>nodes>>edges;
  vector<int> adj[100];
  for(int i=0;i<edges;i++) {
    cin>>start>>end;
    addEdges(adj, start, end);
  }
  topological(adj, nodes);
  return 0;
}
