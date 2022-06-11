#include<bits/stdc++.h>
using namespace std;

/*
for a cyclic directed graph we are unable to generate the toposort 
so we use this reverse property to find whether there is a cycle or not 
--> if we are unable to generate the toposort then the graph has a cycle 
// toposort is the order of the vertices so it contains all the vertices of the graph 
--> so if at the end our topo vector has size of N then yes else NO

also in case of a cycle you will reach a point when you will be left will putting all the nodes in the queue
and the loop will break before only 
because in the cycle there is no node having indegree 0 --> so the cycle will never enter into the queue
*/

class Solution {
public:
	bool isCyclic(int N, vector<int> adj[]) {
        queue<int> q; 
		
	    vector<int> indegree(N, 0); 
	    for(int i = 0;i<N;i++) {
	        for(auto it: adj[i]) {
	            indegree[it]++; 
	        }
	    }
	    
	    for(int i = 0;i<N;i++) {
	        if(indegree[i] == 0) {
	            q.push(i); 
	        }
	    }
		
	    int cnt = 0;
	    while(!q.empty()) {
	        int node = q.front(); 
	        q.pop(); 
	        cnt++; 
	        for(auto it : adj[node]) {
	            indegree[it]--;
	            if(indegree[it] == 0) {
	                q.push(it); 
	            }
	        }
	    }
	    if(cnt == N) return false; 
	    return true; 
	}
};



int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
