/**
@author         gautam-singh<gautam.bhadauria@crownstack.com>
@program        Directed Graph Rrepresentation using STL
@description    Directed Graph has a unidirection edge.
 */
#include<iostream>
#include<vector>

using namespace std;

/*
* Add Edge to the Graph data-structures
*
*@function   addEdge
*@param      vector, int, int
*@return     void
 */
void addEdge(vector<int> adj[], int s_node, int e_node) {
    adj[s_node].push_back(e_node);
}

/**
* Graph traversal Function
*@function    traversal
*@param       vector, int, int
*@return      void
 */
void traversal(vector<int> adj[], int vertices) {
  for(int i=0;i<vertices; i++) {
    cout<<i<<" Connected With : ";
    for(auto it=adj[i].begin(); it != adj[i].end(); it++) {
        cout<<*it<<" ";
    } cout<<endl;
  }
}

/** Driver Program */
int main(int argc, char *argv[]) {
  int nodes, edges;
  cin>>nodes>>edges;
  vector<int> adj[100];
  int s_node, e_node;
  for(int i=0;i<edges;i++) {
    cin>>s_node>>e_node;
    addEdge(adj, s_node, e_node);
  }
  traversal(adj, nodes);

  return 0;
}
