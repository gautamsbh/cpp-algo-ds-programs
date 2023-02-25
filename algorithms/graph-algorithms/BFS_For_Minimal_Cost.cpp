#include<bits/stdc++.h>

using namespace std;

/** Add Edges to Graph */
void addEdge(vector<pair<int,int>> Graph[], int src, int dest, int weight) {
    // Create a pair and Push to src and dest. Undirected Graph
    Graph[src].push_back(make_pair(dest, weight));
    Graph[dest].push_back(make_pair(src, weight));
}

/** finding minimum cost path. Optimal Path from source to destnation*/
void optimalPath(vector<pair<int, int>> Graph[], int nodes, int edges, int src, int dest) {
  // Create a bool array for tracking the nodes with weights
  bool visited[nodes+1][1024] = {false};
  queue<int> que;
  que.push(src);
  queue<int> cost_que;
  cost_que.push(0);
  while(!que.empty()) {
    int front = que.front();
    int cost_front = cost_que.front();
    for(pair<int,int> B: Graph[front])
      if(!visited[B.first][cost_front | B.second]) {
        visited[B.first][cost_front | B.second] = true;
        que.push(B.first);
        cost_que.push(B.second);
      }
  }
  for(int i=0;i<1024;i++) {
    if(visited[dest][i]) {
      cout<<i;
      return;
    }
  }
  cout<<-1;
  return;

}

/** Driver program. Entry point */
int main(int argc, char *argv[]) {
  int nodes, edges, src, dest, weight;
  cin>>nodes>>edges;
  vector<pair<int,int>> Graph[nodes+1];
  for(int i=0;i<nodes;i++) {
    cin>>src>>dest>>weight;
    addEdge(Graph, src, dest, weight);
  }
  cin>>src>>dest;
  // Graph built now iterate for OptimaPath
  optimalPath(Graph, nodes, edges, src, dest);
  return 0;
}
