#include<bits/stdc++.h>
using namespace std;

// my --> eulerian graph --> all degrees even

// 1. You are given a graph and a src vertex.
// 2. You are required to find and print all hamiltonian paths and cycles starting from src. The cycles must end with "*" and paths with a "."

// Note -> A hamiltonian path is such which visits all vertices without visiting any twice. A hamiltonian path becomes a cycle if there is an edge between first and last vertex.
// Note -> Print in lexicographically increasing order.

class Edge{
public:
    int src = 0;
    int nbr = 0;
    int wt = 0;

    Edge(int src, int nbr, int wt) {
        this->src = src;
        this->nbr = nbr;
        this->wt = wt;
    }
};


int searchVrtx(vector<vector<Edge>> graph, int u, int v) {
    int idx = -1;
    for (int i = 0; i < graph[u].size(); i++) {
        Edge e = graph[u][i];
        if (e.nbr == v) {
            idx = i;
            break;
        }
    }

    return idx;
}

void hamiltonianPath(vector<vector<Edge>> graph, int src, int osrc, int noEdge, vector<bool> &vis, string path) {

    if (noEdge == graph.size() - 1) { // visit all means number of edges or number of calls  = num-1   also at this time   vis[x]=true for num edges  -->  that implies that all nodes are visited 
        int idx = searchVrtx(graph, src, osrc);
        path += to_string(src);
        if (idx != -1)
            cout << path << "*" << endl;
        else
            cout << path << "." << endl;
    }

    vis[src] = true;
    for (Edge e : graph[src]) {
        if (!vis[e.nbr])
            hamiltonianPath(graph, e.nbr, osrc, noEdge + 1, vis, path + to_string(src));
    }

    vis[src] = false;
}

int main() {

    int vtces;
    cin >> vtces;
    vector<vector<Edge>> graph(vtces, vector<Edge>());

    int edges;
    cin >> edges;

    for (int i = 0; i < edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].push_back(Edge(u, v, w));
        graph[v].push_back(Edge(v, u, w));
    }

    int src;
    cin >> src;

    vector<bool> vis(vtces, false);
    hamiltonianPath(graph, src, src, 0, vis, "");

    return 0;
}