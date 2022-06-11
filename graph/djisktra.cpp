#include<bits/stdc++.h>
using namespace std;

/*
Djisktra's Algo
Greedy algo
*/

/*

Use :
Q1. Is Dijkstra's algorithm for directed or undirected graphs?
https://stackoverflow.com/questions/38190592/is-dijkstras-algorithm-for-directed-or-undirected-graphs

It can be applied to both. Here is why:
An undirected graph is basically the same as a directed graph with bidirectional connections (= two connections in opposite directions) between the connected nodes.
So you don't really have to do anything to make it work for an undirected graph. You only need to know all of the nodes that can be reached from every given node through e.g. an adjacency list.

Djikstras algorithm is typically for Positive weighted graphs.
Perhaps you are confusing it with the breadth first search (BFS) algorithm, which is essentially Djikstras for unweighted graphs. The difference (between Djikstras and BFS), is when you are dealing with weighted paths, 
we must now consider the path costs adjustments (weights) & the decisions on which nodes to visit after the current.

You can use Dijkstra's algorithm in both directed and undirected graphs, because you simply add edges nodes into the PriorityQueue when you have an edge to travel to from your adjacency list. For example, 
if one of my nodes has an edge from A to B of weight 3, then if it's directed from B I won't be able to add the edge back into A, while from A I could add it to B.
Like the other answers, make sure you do not confuse it with weights. Dijkstra's algorithm runs on positive weighed graphs, otherwise the priority queue would be useless.
In your example, Dijkstra's algorithm would work because the graph is both weighed (positively) and has directed edges.

A graph being directed just means that the edges connecting vertices are able to connect one way, but not the other. This means that one vertex can be adjacent to another, but that other vertex may not be adjacent to the first vertex.
In the context of Dijkstra's algorithm, whether the graph is directed or undirected does not matter. Dijkstra's algorithm simply references the adjacent vertices of a vertex. It is this adjacency list that you would have to modify 
if you were changing a graph from directed to undirected.

Yes Dijkstra work for both directed & undirected graph but all edge weight should me +ve . Because if any weight is -ve then it may be fail to give correct answer. It works on undirected graph 
because in Dijkstra we should always seen that minium edge wt. From its source vertex

Dijkstra can work for Cyclic graphs to. 
Which implies it can work for Undirected graphs. 
Coz an Undirected edge in a graph can simply be assumed to be bidirectional edge. A to B. And B to A. Dijkstra's works for this.



Q2. Why doesn't Dijkstra's algorithm work for negative weight edges?
https://stackoverflow.com/questions/13159337/why-doesnt-dijkstras-algorithm-work-for-negative-weight-edges

Can somebody tell me why Dijkstra's algorithm for single source shortest path assumes that the edges must be non-negative.
I am talking about only edges not the negative weight cycles.

Recall that in Dijkstra's algorithm, once a vertex is marked as "closed" (and out of the open set) - the algorithm found the shortest path to it, and will never have to develop this node again - it assumes the path developed to this path is the shortest.

But with negative weights - it might not be true. For example:

       A
      / \
     /   \
    /     \
   5       2
  /         \
  B--(-10)-->C

V={A,B,C} ; E = {(A,C,2), (A,B,5), (B,C,-10)}
Dijkstra from A will first develop C, and will later fail to find A->B->C

EDIT a bit deeper explanation:

Note that this is important, because in each relaxation step, the algorithm assumes the "cost" to the "closed" nodes is indeed minimal, and thus the node that will next be selected is also minimal.

The idea of it is: If we have a vertex in open such that its cost is minimal - by adding any positive number to any vertex - the minimality will never change.
Without the constraint on positive numbers - the above assumption is not true.

Since we do "know" each vertex which was "closed" is minimal - we can safely do the relaxation step - without "looking back". If we do need to "look back" - Bellman-Ford offers a recursive-like (DP) solution of doing so.


Dijkstra's algorithm assumes paths can only become 'heavier', so that if you have a path from A to B with a weight of 3, and a path from A to C with a weight of 3, there's no way you can add an edge and get from A to B through C with a weight of less than 3.

This assumption makes the algorithm faster than algorithms that have to take negative weights into account.

Correctness of Dijkstra's algorithm:

We have 2 sets of vertices at any step of the algorithm. Set A consists of the vertices to which we have computed the shortest paths. Set B consists of the remaining vertices.

Inductive Hypothesis: At each step we will assume that all previous iterations are correct.

Inductive Step: When we add a vertex V to the set A and set the distance to be dist[V], we must prove that this distance is optimal. If this is not optimal then there must be some other path to the vertex V that is of shorter length.

Suppose this some other path goes through some vertex X.

Now, since dist[V] <= dist[X] , therefore any other path to V will be atleast dist[V] length, unless the graph has negative edge lengths.

Thus for dijkstra's algorithm to work, the edge weights must be non negative.


*/


/*

1. Undirected Graph

graph type : Undirected Graph
cycle : may or may not be present (no condition on this)

edge weight : can be 0,+ve (NO -ve because undirected will not have negative weights anyways)
source : single 
destination : all

SINGLE SOURCE SHORTEST PATH TO ALL THE NODES IN UNDIRECTED GRAPH TO ALL THE NODES


2. Directed Graph 

graph type : Directed Graph
cycle : may or may not be present (no condition on this)

edge weight : can be 0,+ve ( -ve weights are not allowed )

source : single 
destination : all

SINGLE SOURCE SHORTEST PATH TO ALL THE NODES IN DIRECTED GRAPH (WITHOUT NEGATIVE WEIGHTS) TO ALL THE NODES

*/

/*

greedy algo
use a min priority queue    pair < distance, node >   -->  min by weight 
 0,src  push  and  relax all adjacent nodes and push them with the relaxed diatance into the priority queue
IMP -->  push only those which are relaxed because they only have the potential of relaxing others 
also in this algo  -->  A single node can be pushed with multiple value of  distance   but the only useful will be the minimum one 
 ( why multiple --> if we find lower than the prev then we insert the lower but the higher one also reamins in the priority queue)
// but you cannot delete/avoid multiple using priority queue
// you will need a set of pair instead for that --> but this will need more implementation and deletion will not affect the complexity much 
{ set < pair <distance , node> >   you will need to seach by distance also   and before inserting you have to search by node also
  so another data structure has to maintian    like use a freq array   0 not present     1 present     
  while inserting   check freq[i]==0  then push  if freq[i]==1  then psuh the one with lesser distance     
} 


*/


/*

In short :
Use 
All Undirected graph me use ho jayega (-ve to hote he nhi h undirected me)
All Directed graph with non-negative weights (No negative weight allowed )

*/

int main(){
	int n,m,source;
	cin >> n >> m;
	vector<pair<int,int> > g[n+1]; 	// 1-indexed adjacency list for of graph

	int a,b,wt;
	for(int i = 0; i<m ; i++){
		cin >> a >> b >> wt;
		g[a].push_back(make_pair(b,wt));
		g[b].push_back(make_pair(a,wt));
	}	
	
	cin >> source;
	
	// Dijkstra's algorithm begins from here
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;// min-heap ; In pair => (dist,from)
	vector<int> distTo(n+1,INT_MAX); 	// 1-indexed array for calculating shortest paths; 
	
	distTo[source] = 0;
	pq.push(make_pair(0,source));	// (dist,from)
	
	while( !pq.empty() ){
		int dist = pq.top().first;
		int prev = pq.top().second;
		pq.pop();
		
		vector<pair<int,int> >::iterator it;
		for( it = g[prev].begin() ; it != g[prev].end() ; it++){
			int next = it->first;
			int nextDist = it->second;
			if( distTo[next] > distTo[prev] + nextDist){
				distTo[next] = distTo[prev] + nextDist;
				pq.push(make_pair(distTo[next], next));
			}
		}
		
	}
	
	cout << "The distances from source, " << source << ", are : \n";
	for(int i = 1 ; i<=n ; i++)	cout << distTo[i] << " ";
	cout << "\n";
	
	return 0;
}