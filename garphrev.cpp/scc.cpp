#include <bits/stdc++.h>
using namespace std;

vector<bool> vis;
vector<vector<int>> g, gr;
stack<int> st;
vector<int> component;
vector<vector<int>> sccs;

void dfs1(int i) {
    vis[i] = true;
    for (auto it : g[i]) {
        if (!vis[it]) {
            dfs1(it);
        }
    }
    st.push(i);
}

void dfs2(int i) {
    vis[i] = true;
    for (auto it : gr[i]) {
        if (!vis[it])
        {
            dfs2(it);
        }
    }
    component.push_back(i);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;
    g.resize(n);
    gr.resize(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; // to make u and v on 0-based indexing
        v--;
        g[u].push_back(v);
        gr[v].push_back(u);
    }

    vis.assign(n, false);
    
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs1(i);
        }
    }

    vis.assign(n, false);
    
    while (!st.empty()) {
        int t = st.top();
        st.pop();
        
        if (vis[t]) {
            continue;
        }

        component.clear();
        dfs2(t); // Run DFS in reverse graph
                 // in topological order of original graph
        sccs.push_back(component);
    }

    // You can also further convert graph
    // to SCC-condensed graph (DAG)
    // See practice problem 2 for my sample code
    
    return 0;
}
