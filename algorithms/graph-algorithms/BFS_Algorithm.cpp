#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int addEdge(vector<int> adj[], int start, int end) {
  adj[start].push_back(end);
  adj[end].push_back(start);
}

void BFS(vector<int> adj[], int nodes, int start) {
  vector<bool> visited(nodes, false);
  queue<int> que;
  que.push(start); visited[start] = true;
  while(!que.empty()) {
    int iter = que.front(); que.pop();
    cout<<iter<<" ";
    for(auto it = adj[iter].begin(); it != adj[iter].end(); it++) {
      if(visited[*it] ==false) {
        visited[*it] = true;
        que.push(*it);
      }
    }
  }
 }
/** Driver Program  */
int main(int argc, char *argv[]) {
  int nodes, edges, start, end;
  cin>>nodes>>edges;
  vector<int> adj[100];
  for(int i=0;i<edges;i++) {
    cin>>start>>end;
    addEdge(adj, start, end);
  }
  cout<<"Breadth First Search: ";
  BFS(adj, nodes, 0);
  return 0;
}
