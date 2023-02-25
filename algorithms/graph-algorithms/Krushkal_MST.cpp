#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<vector>
#include<utility>
using namespace std;

/**
* Kruskal Algorithm for Undirected Graph
*
*/

/** Structure for Graph Edges */
typedef struct {
  int src;
  int dest;
  int weight;
}Edge;
/** Structure for Subsets */
typedef struct {
  int parent;
  int rank;
}Subset;

/** Add Edge to the Edges array */
Edge addEdge(int src, int dest, int weight) {
  Edge new_edge;
  new_edge.src = src;
  new_edge.dest = dest;
  new_edge.weight = weight;
  return new_edge;
}
/** Disjoint set find function */
int find(Subset subsets[], int i) {
  if(subsets[i].parent != i) {
    subsets[i].parent = find(subsets, subsets[i].parent);
  }
  return subsets[i].parent;
}

/** Disjoint set union function */
void union_set(Subset subsets[], int x, int y) {
  int xroot = find(subsets, x);
  int yroot = find(subsets, y);
  if(subsets[xroot].rank < subsets[yroot].rank) {
    subsets[xroot].parent = yroot;
  } else if(subsets[xroot].rank > subsets[yroot].rank) {
    subsets[yroot].parent = xroot;
  } else {
    subsets[xroot].parent = yroot;
    subsets[xroot].rank++;
    }
}

int myComp(const void* a, const void* b)
{
    Edge* a1 = (Edge *)a;
    Edge* b1 = (Edge *)b;
    return a1->weight > b1->weight;
}
void kruskalMST(Edge Edges[], int nodes, int edges) {
    Edge *result = (Edge *)malloc(edges * sizeof(Edge));
    int e = 0;
    int i = 0;
    qsort(Edges, edges, sizeof(Edge), myComp);
    Subset *subsets = (Subset *)malloc(nodes * sizeof(Subset));
    for(int v=0;v<nodes;v++) {
      subsets[v].parent = v;
      subsets[v].rank = 0;
    }
    while(e < (nodes-1)) {
      Edge new_edge =  Edges[i++];
      int x = find(subsets, new_edge.src);
      int y = find(subsets, new_edge.dest);
      if(x!=y) {
        result[e++] = new_edge;
        union_set(subsets, x, y);
      }
    }
  int costs = 0;
  for(int i=0;i<e;i++) {
    costs += result[i].weight;
  }
    cout<<costs<<endl;
}

/** Driver Program */
int main(int argc, char *argv[]) {
  int nodes, edges, src, dest, weight;
  cin>>nodes>>edges;
  Edge *Edges = (Edge *)malloc(edges*sizeof(Edge));
  for(int i=0;i<edges;i++) {
    cin>>src>>dest>>weight;
    Edges[i] = addEdge(src, dest, weight);
  }
  kruskalMST(Edges, nodes, edges);
}
