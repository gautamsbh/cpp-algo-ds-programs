/**
* Weighted Graph Representaton
*
*@author        gautam-singh<gautam.bhadauria@crownstack.com>
*@program       Weighted Graph
*@description   Weighted graph for both directed and undirected graph
 */
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void addEdge(vector<pair<int, int>> graph[], int weight, int start, int end) {
      graph[start].push_back(make_pair(end, weight));
}

/** Breadth First Search Alogirtihm  */
void BFS(vector<pair<int, int>> graph[], int nodes, int start, int weight) {
  vector<bool> visited(nodes, false);
  queue<pair<int, int>> que;
  que.push(make_pair(start, weight)); visited[start] = true;
  while(!que.empty()) {
    pair<int, int> iter = que.front(); que.pop();
    cout<<iter.first<<"(weight:"<<iter.second<<")"<<" => ";
    for(auto it = graph[iter.first].begin(); it != graph[iter.first].end(); it++) {
      if(visited[it->first] ==false) {
        visited[it->first] = true;
        que.push(make_pair(it->first, it->second));
      }
    }
  }
 }

/**   Driver Program  */
int main(int argc, char *argv[]) {
      int nodes, edges;
      cin>>nodes>>edges;
      vector<pair<int, int>> graph[100];
      int start, end, weight;
      for(int i=0;i<edges;i++) {
          cin>>start>>end>>weight;
          addEdge(graph, weight, start, end);
      }
      BFS(graph, nodes, 0, 0);
}
