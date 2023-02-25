#include<iostream>
#include<typeinfo>
#include<vector>
#include<memory>
#include<utility>
#include<queue>

using namespace std;

void bfs(vector<pair<int, int>> graph[], int vertices, int start) {
    // Now traverse through the array in Bread First Search Fashion
    // Or Level order traversal in tree structures
    // First initialize the queue and set the visited vertex as true
    vector<bool>  visited(vertices, false); // vector of type boolean with size as vertices and default as false
    // Now push the first element to std::queue<int> name;
    queue<pair<int, int>> que;
    que.push(make_pair(start, 0));  // Initial
    while(!que.empty()) {
        // Print the item and Push the connected vertices
        auto element = que.front();
        que.pop();
        visited[element.first] = true;
        cout<<element.first<<" Weight : "<<element.second<<endl;
        for(auto it=graph[element.first].begin(); it!= graph[element.first].end(); it++) {
            if(!visited[it->first]) {
                visited[it->first] = true;
                que.push(*it);
            }
        }
    }
}




auto main(int argc, char *argv[]) -> int {
    // Creating the graph instance
    // Get input of the number of vertices
    int vertices;
    cout<<"Enter the number of vertices or order of Graph"<<endl;
    cin>>vertices;

    // Node get the information of the vertices
    int edges, u, v, weight;
    cout<<"Enter the number of Edges or size of Graph"<<endl;
    cin>>edges;
    vector<pair<int, int>> graph[vertices];
    for(int i =0; i<edges; i++) {
        cout<<"Enter the source and Destination of the vertex"<<endl;
        cin>>u>>v>>weight;
        // If graph is undirected then
        // Push the data on both the vertices
        graph[u].push_back(make_pair(v, weight));
        graph[v].push_back(make_pair(u, weight));
    }

    bfs(graph, vertices, 0);
    // Now graph is constructed and call the traverse function
    // This can be done by DFS, BFS or IDDFS
    return 0;
}
