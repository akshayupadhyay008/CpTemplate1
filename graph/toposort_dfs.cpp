#include <bits/stdc++.h>
using namespace std;

class Solution{
    void findTopoSort(int node, vector<int> &vis, stack<int> &st, vector<int> adj[]) {
        vis[node] = 1; 
        
        for(auto it : adj[node]) {
            if(!vis[it]) {
                findTopoSort(it, vis, st, adj); 
            }
        }
        st.push(node); 
    }
	public:
	vector<int> topoSort(int N, vector<int> adj[]) {
	    stack<int> st; 
	    vector<int> vis(N, 0); 
	    for(int i = 0;i<N;i++) {
	        if(vis[i] == 0) {
	            findTopoSort(i, vis, st, adj); 
	        }
	    }
	    vector<int> topo;
	    while(!st.empty()) {
	        topo.push_back(st.top()); 
	        st.pop(); 
	    }
	    return topo; 
	    
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/

// topo sort --> only possible in DAG (directed acyclic(NO cycle) graph)
// topo sort --> the order of dfs ending (out time) --> outtime more(dfs end early) later in topo sort 
// topo sort --> parent should be before child for all parent and child relationships 

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
            // topo sort --> parent should be before child for all parent and child relationships 
            // we are checking this here --> definition of topo is valid or not for every child and parent 
            
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends