// Program:- Find In Degree of All Vertex
// And Find the Root of tree or Graph vertex having Zero In Degree
#include<iostream>
#include<vector>
#include<cstdlib>
#include<list>
using namespace std;
// Create Class Graph with v Vertex and Adjacency list vector
class Graph
{
    int V;
    list<int> *adj;
    vector<int> indegree;
public:
Graph(int V);
void addEdge(int v1,int v2);
void printIndegree();
~Graph();
};
Graph::Graph(int V)
{
    // Allocate Memory for this Graph
    adj=new list<int>[V];
}
// Edge module Definition
void Graph::addEdge(int v1,int v2)
{
    adj[v1].push_back(v2);
    indegree.push_back(v2);
}
void Graph::printIndegree()
{   int found=0;
    for(int i=0;i<V;i++)
      {
        for(auto x:indegree)
    {
        if(i==x) { found=1; }
    }
    if(!found) { cout<<i<<endl;}
  }
}
Graph::~Graph()
{
    delete [] adj;
}
int main()
{
 //   ios_base::sync_with_stdio(false);
 //   cin.tie(NULL);
    Graph cross(7);
    cross.addEdge(0,1);
    cross.addEdge(1,2);
    cross.addEdge(4,3);
    cross.addEdge(2,5);
    cross.addEdge(3,5);
    cross.addEdge(4,0);
    cross.addEdge(2,3);
    cross.printIndegree();
    return 0;
}
