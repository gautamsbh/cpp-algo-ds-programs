#include<bits/stdc++.h>

using namespace std;

void addEdge(vector<int> Graph[], int src, int dest) {
  Graph[src].push_back(dest);
  Graph[dest].push_back(src);
}

/** Driver Program */
int main(int argc, char *argv[]) {
  int nodes, edges, src, dest;
  cin>>nodes>>edges;
  vector<int> Graph[nodes+1];
  for(int i=0;i<edges;i++) {
    cin>>src>>dest;
    addEdge(Graph, src, dest);
  }

}
