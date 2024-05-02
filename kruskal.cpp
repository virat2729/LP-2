#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define a structure to represent an edge
struct Edge {
    int src, dest, weight;
    Edge(int s, int d, int w) : src(s), dest(d), weight(w) {}
};

// Define a structure to represent a subset for Union-Find
struct Subset {
    int parent, rank;
};

// Find operation for Union-Find
int find(vector<Subset>& subsets, int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Union operation for Union-Find
void unionSets(vector<Subset>& subsets, int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Function to find the Minimal Spanning Tree (MST) using Kruskal's algorithm
vector<Edge> kruskalMST(vector<Edge>& edges, int V) {
    vector<Edge> result;
    vector<Subset> subsets(V);
    for (int i = 0; i < V; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    // Sort edges in non-decreasing order of their weight
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    int e = 0, i = 0;
    while (e < V - 1 && i < edges.size()) {
        Edge nextEdge = edges[i++];
        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);
        if (x != y) {
            result.push_back(nextEdge);
            unionSets(subsets, x, y);
            e++;
        }
    }
    return result;
}

int main() {
    int V = 4; // Number of vertices
    vector<Edge> edges = {Edge(0, 1, 10), Edge(0, 2, 6), Edge(0, 3, 5),
                          Edge(1, 3, 15), Edge(2, 3, 4)}; // Example edges

    // Find and output the edges of the Minimal Spanning Tree (MST)
    vector<Edge> mstEdges = kruskalMST(edges, V);
    cout << "Edges of MST:" << endl;
    for (const Edge& edge : mstEdges) {
        cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
    }

    return 0;
}
