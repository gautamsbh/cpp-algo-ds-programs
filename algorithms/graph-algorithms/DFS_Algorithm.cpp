#include<iostream>
#include<vector>

using namespace std;
/**
*@author      gautam-singh<gautam.bhadauria@crownstack.com>
*@program     Depth First Search for Both Directed and Undirected Graph
 */
void addEdge(vector<int> adj[], int start, int end) {
    adj[start].push_back(end);
    adj[end].push_back(start);
}

void DFSUtil(vector<int> adj[], int i, int nodes, vector<bool> &visited) {
  visited[i] = true;
  cout<<i<<" ";
  for(auto it = adj[i].begin(); it != adj[i].end(); it++) {
    if(visited[*it] == false) {
      DFSUtil(adj, *it, nodes, visited);
    }
  }
}
void DFS(vector<int> adj[], int nodes) {
    // Find the root node and traverse these nodes and set them as visited
    vector<bool> visited(nodes, false);
    for(int i=0;i<nodes;i++) {
      if(visited[i] == false) {
          DFSUtil(adj, i, nodes, visited);
      }
    }
}

/** Driver Program */
int main(int argc, char *argv[]) {
  int nodes, edges,start,end;
  cin>>nodes>>edges;
  vector<int> adj[100];
  for(int i=0;i<edges;i++) {
    cin>>start>>end;
    addEdge(adj, start, end);
  }
  cout<<"Depth First Search Traversal is : ";
  DFS(adj, nodes);
  return 0;
}
