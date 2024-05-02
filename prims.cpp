#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define INF INT_MAX

// Define a structure to represent an edge
struct Edge {
    int to;
    int weight;
    Edge(int t, int w) : to(t), weight(w) {}
};

// Function to find the Minimal Spanning Tree (MST) using Prim's algorithm
int primMST(vector<vector<Edge>>& graph) {
    int V = graph.size();

    vector<bool> visited(V, false); // Mark all vertices as not visited
    vector<int> minWeight(V, INF); // Initialize minWeight to INF

    minWeight[0] = 0; // Start with the first vertex
    int totalWeight = 0;

    for (int i = 0; i < V; ++i) {
        // Find the vertex with the minimum weight that has not been visited
        int minVertex = -1;
        for (int v = 0; v < V; ++v) {
            if (!visited[v] && (minVertex == -1 || minWeight[v] < minWeight[minVertex])) {
                minVertex = v;
            }
        }

        // Mark the selected vertex as visited
        visited[minVertex] = true;
        totalWeight += minWeight[minVertex];

        // Update the minimum weight of adjacent vertices
        for (Edge& e : graph[minVertex]) {
            if (!visited[e.to] && e.weight < minWeight[e.to]) {
                minWeight[e.to] = e.weight;
            }
        }
    }

    return totalWeight;
}

// Utility function to add an undirected edge to the graph
void addEdge(vector<vector<Edge>>& graph, int u, int v, int weight) {
    graph[u].push_back(Edge(v, weight));
    graph[v].push_back(Edge(u, weight));
}

int main() {
    int V = 5; // Number of vertices

    // Create a graph
    vector<vector<Edge>> graph(V);

    // Add edges to the graph
    addEdge(graph, 0, 1, 2);
    addEdge(graph, 0, 3, 6);
    addEdge(graph, 1, 2, 3);
    addEdge(graph, 1, 3, 8);
    addEdge(graph, 1, 4, 5);
    addEdge(graph, 2, 4, 7);
    addEdge(graph, 3, 4, 9);

    // Find and output the total weight of the Minimal Spanning Tree (MST)
    int totalWeight = primMST(graph);
    cout << "Total weight of MST: " << totalWeight << endl;

    return 0;
}
