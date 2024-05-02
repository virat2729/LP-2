#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define INF INT_MAX

// Define a structure to represent an edge
struct Edge {
    int to;
    int weight;
    Edge(int t, int w) : to(t), weight(w) {}
};

// Define a custom comparator for the priority queue
struct Compare {
    bool operator()(const Edge& e1, const Edge& e2) {
        return e1.weight > e2.weight; // Use greater for min heap
    }
};

// Function to find the Minimum Spanning Tree (MST) using Prim's algorithm
vector<vector<Edge> > primMST(vector<vector<Edge> >& graph, int start) {
    int V = graph.size();

    vector<bool> visited(V, false); // Mark all vertices as not visited
    priority_queue<Edge, vector<Edge>, Compare> pq; // Priority queue to store edges

    // Start with the given vertex
    visited[start] = true;
    for (Edge& e : graph[start]) {
        pq.push(e);
    }

    vector<vector<Edge> > mst(V); // Initialize MST
    int totalWeight = 0;

    while (!pq.empty()) {
        Edge curr = pq.top();
        pq.pop();

        int u = curr.to;
        int w = curr.weight;

        // If the vertex is already visited, skip it
        if (visited[u]) continue;

        // Mark the vertex as visited and add the edge to MST
        visited[u] = true;
        mst[start].push_back(Edge(u, w));
        mst[u].push_back(Edge(start, w));
        totalWeight += w;

        // Add adjacent edges of the current vertex to the priority queue
        for (Edge& e : graph[u]) {
            if (!visited[e.to]) {
                pq.push(e);
            }
        }
    }

    // Output the total weight of the MST
    cout << "Total weight of MST: " << totalWeight << endl;

    return mst;
}

// Utility function to add an undirected edge to the graph
void addEdge(vector<vector<Edge> >& graph, int u, int v, int weight) {
    graph[u].push_back(Edge(v, weight));
    graph[v].push_back(Edge(u, weight));
}

int main() {
    int V = 5; // Number of vertices

    // Create a graph
    vector<vector<Edge> > graph(V);

    // Add edges to the graph
    addEdge(graph, 0, 1, 2);
    addEdge(graph, 0, 3, 6);
    addEdge(graph, 1, 2, 3);
    addEdge(graph, 1, 3, 8);
    addEdge(graph, 1, 4, 5);
    addEdge(graph, 2, 4, 7);
    addEdge(graph, 3, 4, 9);

    int startVertex = 0; // Starting vertex for MST

    // Find and output the Minimum Spanning Tree (MST)
    vector<vector<Edge> > mst = primMST(graph, startVertex);
    cout << "Minimum Spanning Tree (MST):" << endl;
    for (int i = 0; i < V; ++i) {
        for (Edge& e : mst[i]) {
            cout << i << " - " << e.to << " : " << e.weight << endl;
        }
    }

    return 0;
}
