#include<bits/stdc++.h>
using namespace std;

/*
MST --> minimum spanning tree can be found by 2 methods 
Convert Undirected Graph into Tree with minimum Sum of weights 

1. Prims 
2. Kruskals 


Why can't Prim's or Kruskal's algorithms be used on a directed graph?

https://stackoverflow.com/questions/22649416/why-cant-prims-or-kruskals-algorithms-be-used-on-a-directed-graph

Prim's and Kruskal's algorithms are used to find the minimum spanning tree of a graph that is connected and undirected. 
Why can't they be used on a graph that is directed?

Prim's and Kruskal's algorithms output a minimum spanning tree for connected and "undirected" graphs. If the graph is not connected, 
we can tweak the algorithms to output minimum spanning forests.

In Prim's algorithm, we divide the graph in two sets of vertices. One set of the explored vertices which have already formed a MST (Set 1) 
and another set of unexplored vertices which will eventually join the first set to complete "spanning" (Set 2). At each instant, 
we select a minimum weighted edge in the cut joining the two disjoint sets. If there is no directed edge from explored nodes of the MST to the remaining unexplored nodes,
the algorithm gets stuck even though there are edges from unexplored nodes to explored nodes in the MST.

In Kruskal's algorithm, the idea is to sort the edges in ascending order by their weight and pick them up in order and include them 
in the MST of explored nodes/edges if they do not already form a cycle with any explored nodes. This is done using the Union-Find data structure. 
But detection of cycles for directed graphs fails with this method. For example, a graph containing edges [1->2] [2->3] [1->3] will be reported to contain a cycle with the Union-Find method.

So Prim's fails because it assumes every node is reachable from every node which, though valid for undirected graphs, may not be true for digraphs. 
Kruskal's fails because of failure to detect cycles and sometimes it is essential to add edges making cycles to satisfy the "minimum" weighted property of MST.

Also, in case of digraphs, MST doesn't make complete sense. Its equivalent for digraphs is "minimum spanning arborescence" which will produce a tree where every vertex can be reached from a single vertex.

*/

/*
This is 1st implementation of Prims --> brute Force ( > O(N^2) )
*/

int main(){

	int N,m;
	cin >> N >> m;
	vector<pair<int,int> > adj[N]; 

	int a,b,wt;
	for(int i = 0; i<m ; i++){
		cin >> a >> b >> wt;
		adj[a].push_back(make_pair(b,wt));
		adj[b].push_back(make_pair(a,wt));
	}	
	
    // taking the input --> 
    // undirected graph (connected here -->  if not connected then find MST for each component)


	int parent[N]; // store the answer MST (because using the parent only we can represent the tree ) 
      
    int key[N]; // the array which will be used to find the next edge of the MST 
    // (there has to N-1 edges of the MST ) --> so we run the loop N-1 times to get 1 edge each time --> (N-1) egdes 
      
    bool mstSet[N]; // used to tell which nodes are processed and which are not (the processed nodes will not be considered again )
  
    for (int i = 0; i < N; i++) 
        key[i] = INT_MAX, mstSet[i] = false; // parent[i]=-1; initially (No inpact,keeping default will also do) 
  

    key[0] = 0; // taking any node as the starting node say 0 
    parent[0] = -1; 
    int ansWeight = 0;

    for (int count = 0; count < N - 1; count++) // just loop running for N-1 times for N-1 edges 
    { 
        
        int mini = INT_MAX, u; 
  
        for (int v = 0; v < N; v++)  // finding the minimum in the key array which has not been visisted 
            if (mstSet[v] == false && key[v] < mini)  
                mini = key[v], u = v; 
                
        mstSet[u] = true; // making that minimum as visited 
        
        for (auto it : adj[u]) { // doing through the adjacent 
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v]) 
                parent[v] = u, key[v] = weight;  // parent and key updata(relax/decrease)
        }
            
    } 
    
    
    for (int i = 1; i < N; i++) 
        cout << parent[i] << " - " << i <<" \n"; // printing the tree 
	return 0;
}