#include <bits/stdc++.h> 
#define INF INT_MAX 
using namespace std; 

/*

graph type : directed
cycle : not present 
(DAG)

edge weight : can be 0,+ve or -ve (no restriction here)
source : single 
destination : all

SINGLE SOURCE SHORTEST PATH TO ALL THE NODES IN DIRECTED ACYCLIC GRAPH (DAG) TO ALL THE NODES

Method : Toposort (why ? --> because if we have a DAG then we can find that which is to be visited first and then which is to be visited as they depend on already visisted --> toposort )
// so we visit them according to the toposort and try to reduce(compress) the distance of this node from all its previous dependencies(all the nodes in adjacency list which already have been visited
the adjacency list will contain all connected nodes out of which //some (WRONG) // all will be (because in TOPOSORT all parent are visited first then child comes ))
// so using the all parents path we will try to compress this distance 
weights can be 0 -ve +ve --> 0/+ve are usual but why do -ve has no effect here --> 
because 
A -->(+5) B -->(-3) C 
now here B-->C is a negative edge so first A will come say it is the root (distance = 0)
then B will come (dist=5) 
then C dist = ( 5 + (-3) = 2 ) so its distance will distance and subsequently all the nodes coming after C will be governed by 2 (will all have this negative effect) but B will never have this effect becasue it is 
its parent and we will be never be able to move there --> which is the reason it works 


NOTE 
ME 
Undirected graph : 
1. having negative weights in undirected graph makes no sense at all --> because you can continuosky move from that node in and out to reach the distnce to -infinity
so NO NEGATIVE WEIGHTS IN indirected graph 

So can you use this method in Undirected without negative weights 
: NO 
because it can have cycle also 
in case of Cycle you cannot reduce come nodes in a cycle coming from other path 
like 5 node cycle you reached 1 2 3 went to ( 7 8 .. other outgoing nodes ) then 4,5 
but if you would have choosen to move from 4 5 3 2 1 then the weights would have been different ( you will be able to reduce 4 but not 5 2 3 because they are not directly connected to the start) 
also consider a double cycle like .... not work also 

So in cyycles also not work 

if if NO NEGATIVE NO CYCLE 
then we can use this dependency method of first covering the parent then the child 
--> The way to achieve first parent and then child is BFS 
so use BFS here to reduce parent then childs (shortest_distance_with_unit_weights.cpp came method will work here )

*/


// DAG : this method 
// Undirected acyclic non-negative : BFS (shortest_distance_with_unit_weights.cpp) exact 

void findTopoSort(int node, int vis[], stack<int> &st, vector<pair<int,int>> adj[]) {
    vis[node] = 1; 
    for(auto it : adj[node]) {
        if(!vis[it.first]) {
            findTopoSort(it.first, vis, st, adj); 
        }
    }
    st.push(node);
}


void shortestPath(int src, int N, vector<pair<int,int>> adj[]) 
{ 
	int vis[N] = {0};
	stack<int> st; 
	for (int i = 0; i < N; i++) 
		if (!vis[i]) 
			findTopoSort(i, vis, st, adj); 
			
	int dist[N]; 
	for (int i = 0; i < N; i++) 
		dist[i] = 1e9; 
	dist[src] = 0; 

	while(!st.empty()) 
	{  
		int node = st.top(); 
		st.pop(); 
 
		if (dist[node] != INF) { 
        // which means that we have reached this node --> you will be able to reduce the adjacents from the reached nodes 
        // --> for eg. other components nodes are not reachable from source so they have the distance infinity and hence cannot reduce any 
		    for(auto it : adj[node]) {
		        if(dist[node] + it.second < dist[it.first]) {
		            dist[it.first] = dist[node] + it.second; 
		        }
		    }
		}
	} 

	for (int i = 0; i < N; i++) 
		(dist[i] == 1e9)? cout << "INF ": cout << dist[i] << " "; 
} 

int main() 
{ 
	int n, m;
	cin >> n >> m;
	vector<pair<int,int>> adj[n]; 
	for(int i = 0;i<m;i++) {
	    int u, v, wt;
	    cin >> u >> v >> wt; 
	    adj[u].push_back({v, wt}); 
	}
	
	shortestPath(0, n, adj); 

	return 0; 
} 