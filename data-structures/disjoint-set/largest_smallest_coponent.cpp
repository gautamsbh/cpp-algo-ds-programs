#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<cstdlib>
#include<cstring>
using namespace std;
// Structure for Edge
struct Edge
{
        int src,dest; // Edges in Graph Contains Source -> Destination and may contain weight also
};
// Structure for Graph
struct Graph
{
    int V,E; // Numbers of Nodes & edges in Graph
    struct Edge *edge; // Graph is an Array of Edges
};
// Function To create Graph
struct Graph *createGraph(int V,int E)
{
    // Allocate Memeory for Graph
    struct Graph *graph=(struct Graph *)malloc(sizeof(struct Graph));
    // Initialize the member of Structure Graph
    graph->V=V;
    graph->E=E;
    // Allocate Memory for Edges
    graph->edge=(struct Edge *)malloc(graph->E*sizeof(struct Edge));
    return graph;
}
// Function to Find an Element
int find(int parent[],int i)
{
    if(parent[i]==-1)
        return i;
    return find(parent,parent[i]);
}
// Function to Find Union
void union_dis(int parent[],int x,int y)
{
    parent[x]=y;
}
// Function Hasmap to Count Connected Components
void hashmap(struct Graph *graph,int parent[])
{
    vector<int> hash(graph->V,1);
    for(int i=0;i<graph->V;i++)
    {
        if(parent[i]==-1)
        {
            continue;
        }
        int x=find(parent,parent[i]);
        hash[x]++;
    }
    // Find Max
    int max=0; int min=16000;
    for(int i=0;i<hash.size();i++)
    {
        if(hash[i]>max) { max=hash[i]; }
        if(hash[i]<min && hash[i]>1) { min=hash[i]; }
    }
    // Print result
    cout<<min<<" "<<max<<endl;
}
// Function to fill disjoint-set
void fill_disjoint(struct Graph *graph)
{
    // Allocate the Disjpoint array Memory
    int *parent=(int *)malloc(graph->V * sizeof(int));
    // Intialize all menmory with -1
    memset(parent,-1,sizeof(int)*graph->V);
    // Now fill Up Values Loop Through All Edges
    for(int i=0;i<graph->E;i++)
        {
            int x=find(parent,graph->edge[i].src);
            int y=find(parent,graph->edge[i].dest);
           union_dis(parent,x,y);
        }
    // HashMap Keys with Connected Components
    hashmap(graph,parent);
}
int main() {
    int V;
    int E; cin>>E;
    V=(2*E);
    int edge1,edge2;
    // Allocate Graph Instance
    struct Graph *graph=createGraph(V,E);
 //   Input All Edges
    for(int i=0;i<E;i++)
    {
         cin>>edge1>>edge2;
         graph->edge[i].src=edge1;
         graph->edge[i].dest=edge2;
    }
    // Fill the Disjoint Array
    fill_disjoint(graph);
    return 0;
}
