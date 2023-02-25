#include<iostream>
#include<vector>

using namespace std;
/**
@author   gautam-singh<gautam.bhadauria@crownstack.com>
@program  UndirectedGraph representation with adjacency list
@function addEdge
@return   void
@param    vector, int. int
 */
void addEdge(vector<int> adj[], int start, int end) {
  adj[start].push_back(end);
  adj[end].push_back(start);
}

/**
@program        Traverse
@description    Undirected Graph Traversal
@param          vector, vertices
@return         void
 */
 void traverse(vector<int> adj[], int vertices) {
   for(int i=0; i<vertices; i++) {
     cout<<i<<": Connected With : ";
     for(auto it=adj[i].begin(); it != adj[i].end(); it++) {
       cout<<*it<<" ";
     } cout<<endl;
   }
  }
/** Driver Program */
int main(int argc, char *argv[]) {
  int nodes, edges;
  cin>>nodes>>edges;
  vector<int> adj[1000];
  int start, end;
  for(int i=0;i<edges;i++) {
    cin>>start>>end;
    addEdge(adj, start, end);
  }
  /** Traverse of Undirected Graph */
  traverse(adj, nodes);

  return 0;
}
