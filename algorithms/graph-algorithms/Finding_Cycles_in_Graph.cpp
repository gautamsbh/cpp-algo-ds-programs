#include<iostream>
#include<vector>
#include<cmath>
/**
* Finding Cycles in Directed Acyclic Graph (DAG)
*
 */
using namespace std;

/**
* Add Edge to Graph.
 */
void addEdge(vector<int> Graph[], int start, int end) {
  Graph[start].push_back(end);
}

/**
* isCyclicUtil function
 */
bool isCyclicUtil(vector<int> Graph[], int i, vector<bool> visited, vector<bool> recStack) {
  if(visited[i] == false) {
      visited[i] = true;
      recStack[i] = true;
  for(auto it = Graph[i].begin(); it != Graph[i].end(); it++) {
      if(!visited[*it] && isCyclicUtil(Graph, *it, visited, recStack)) {
        return true;
      }
      else if(recStack[*it]) {
        return true;
      }
    }
  }
    recStack[i] = false;
    return false;
}

bool isCyclicGraph(vector<int> Graph[], int nodes) {
  vector<bool> visited(nodes, false);
  vector<bool> recStack(nodes, false);
  //Iterate over all nodes for visited
  for(int i=0; i<nodes; i++) {
    if(isCyclicUtil(Graph, i, visited, recStack))  {
      return true;
    }
  }
  return false;
}
/** Driver Program */
int main(int argc, char *argv[]) {
  int nodes, edges, start, end;
  cin>>nodes>>edges;
  vector<int> Graph[100];
  // Iterate over the loop to form Graph
  for(int i=0; i<edges; i++) {
    cin>>start>>end;
    addEdge(Graph, start, end);
  }
  if(isCyclicGraph(Graph, nodes)) {
    cout<<"Cycles in DAG Detected";
  } else {
    cout<<"No Cycles Found in DAG";
  }
}
