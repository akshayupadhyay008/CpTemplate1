#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int src;
    int nbr;
    int wt;

    Edge(int src, int nbr, int wt) {
        this->src = src;
        this->nbr = nbr;
        this->wt = wt;
    }
};

void dfs(vector<Edge> graph[], int src, vector<bool> &visited) {
    visited[src] = true;

    for (Edge ed : graph[src]) {
        if (visited[ed.nbr] == true)
            continue;
        dfs(graph, ed.nbr, visited);
    }
}

int main() {
    int vtces;
    cin >> vtces;
    vector<Edge> graph[vtces];

    int edges;
    cin >> edges;

    for (int i = 0; i < edges; i++) {
        int v1;
        int v2;
        int wt;
        cin >> v1 >> v2 >> wt;
        graph[v1].push_back(Edge(v1, v2, wt));
        graph[v2].push_back(Edge(v2, v1, wt));
    }

    int src;
    cin >> src;
    int dest;
    cin >> dest;

    vector<bool> vis(vtces, false);

    dfs(graph, 0, vis);

    for (int i = 0; i < vtces; i++) {
        if (!vis[i]) {
            cout << "false";
            return 0;
        }
    }

    cout << "true";
    
}