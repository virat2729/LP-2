#include <iostream>
#include <vector>
#include <set>

using namespace std;

// Graph class representing an undirected graph using adjacency list
class Graph {
private:
    int V; // Number of vertices
    vector<vector<int> > adj; // Adjacency list

public:
    Graph(int V) : V(V), adj(V) {}

    // Function to add an edge between two vertices
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Recursive function for Depth First Search traversal
    void DFSUtil(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " "; // Print the current vertex

        // Recursively visit all adjacent vertices
        for (size_t i = 0; i < adj[v].size(); ++i) {
            int u = adj[v][i];
            if (!visited[u]) {
                DFSUtil(u, visited);
            }
        }
    }

    // DFS traversal starting from a given vertex
    void DFS(int startVertex) {
        vector<bool> visited(V, false); // Mark all vertices as not visited
        DFSUtil(startVertex, visited);
    }
};

int main() {
    int V, E; // Number of vertices and edges
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    Graph graph(V); // Create a graph with V vertices

    cout << "Enter the edges (format: vertex1 vertex2):\n";
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v); // Add each edge to the graph
    }

    int startVertex;
    cout << "Enter the starting vertex for DFS: ";
    cin >> startVertex;

    cout << "Depth First Search traversal starting from vertex " << startVertex << ":\n";
    graph.DFS(startVertex);

    return 0;
}
