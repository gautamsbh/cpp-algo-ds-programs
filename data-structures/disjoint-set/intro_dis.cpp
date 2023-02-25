#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
// Structure to Represent an Edge
struct Edge
{
    int src,dest;
};
// Structure to Represent an Graph
struct Graph
{
    int V,E; // Number of Vertex & Edges
    struct Edge *edge;
    // Graph is an array of adjacency list and also of array of edges
};
// Function to Create a graph
struct Graph *createGraph(int V, int E)
{
    // Allocate Memory for Graph
    struct Graph *graph=(struct Graph *)malloc(sizeof(struct Graph));
    // Initialize all members
    graph->V=V;
    graph->E=E;
    // Now Allocate Memory for Edges
    graph->edge=(struct Edge *)malloc(graph->E * sizeof(struct Edge));
    return graph;
};
// Function to Find an Element in Subset
int find(int parent[], int i)
{
    if(parent[i]==-1)
        return i;
    return find(parent,parent[i]);
}
// Function to find union of to Subsets
void union_dis(int parent[],int x,int y)
{
    int xset=find(parent,x);
    int yset=find(parent,y);
    parent[xset]=yset;
}
// Function to Find Cycle if Exists
int isCycle(struct Graph *graph)
{
    // Allocate Memory for Disjoint Set
    int *parent=(int *)malloc(sizeof(int)*graph->V);
    // Initialize all values with -1
    memset(parent,-1,sizeof(int)*graph->V);
    // Now Traverse Edges and Fill the Disjoint Set Linear Array
    for(int i=0;i<graph->E;i++)
    {
        int x=find(parent,graph->edge[i].src);
        int y=find(parent,graph->edge[i].dest);
        if(x==y)
            return 1; // This Shows it is Already Present
        union_dis(parent,x,y);
    }
    return 0;
}
// Driver Program
int main(void)
{
    int V=3,E=3;
    // Allocate Source Vertex of Graph
    struct Graph *graph=createGraph(V,E);
    // Add Edges to these Graph
    graph->edge[0].src=0;
    graph->edge[0].dest=1;
    // Add Edge 1-2
    graph->edge[1].src=1;
    graph->edge[1].dest=2;
    // Add Edge 0-2
    graph->edge[2].src=0;
    graph->edge[2].dest=2;
    // Call isCycle function  and check return value
    if(isCycle(graph))
    {
        // Remember this graph don not have Self-Loops
        cout<<"Graph has Cycles\n";
    }
    else
    {
        cout<<"Graph Do not Have Cycles\n";
    }
    return 0;
}
