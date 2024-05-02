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
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second > p2.second; // Use greater for min heap
    }
};

// Function to find the Shortest Paths from a single source using Dijkstra's algorithm
vector<int> dijkstraSSSP(vector<vector<Edge>>& graph, int source) {
    int V = graph.size();

    vector<int> dist(V, INF); // Initialize distances to INF
    dist[source] = 0; // Distance from source to itself is 0

    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq; // Priority queue to store vertices and distances

    pq.push(make_pair(source, 0));

    while (!pq.empty()) {
        int u = pq.top().first;
        int du = pq.top().second;
        pq.pop();

        // If the popped vertex is already processed, skip it
        if (du != dist[u]) continue;

        // Visit all adjacent vertices of u
        for (Edge& e : graph[u]) {
            int v = e.to;
            int w = e.weight;

            // If a shorter path is found to v through u
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push(make_pair(v, dist[v]));
            }
        }
    }

    return dist;
}

// Utility function to add a directed edge to the graph
void addEdge(vector<vector<Edge>>& graph, int u, int v, int weight) {
    graph[u].push_back(Edge(v, weight));
}

int main() {
    int V = 6; // Number of vertices
    int E = 9; // Number of edges

    // Create a graph
    vector<vector<Edge>> graph(V);

    // Add edges to the graph (source, destination, weight)
    addEdge(graph, 0, 1, 5);
    addEdge(graph, 0, 2, 3);
    addEdge(graph, 1, 3, 6);
    addEdge(graph, 1, 2, 2);
    addEdge(graph, 2, 4, 4);
    addEdge(graph, 3, 4, 6);
    addEdge(graph, 3, 5, 3);
    addEdge(graph, 4, 5, 5);
    addEdge(graph, 5, 0, 1);

    int source = 0; // Source vertex for Shortest Paths

    // Find and output the Shortest Paths from the source vertex
    vector<int> shortestPaths = dijkstraSSSP(graph, source);
    cout << "Shortest Paths from vertex " << source << ":" << endl;
    for (int i = 0; i < V; ++i) {
        cout << "Vertex " << i << ": Distance = " << shortestPaths[i] << endl;
    }

    return 0;
}
