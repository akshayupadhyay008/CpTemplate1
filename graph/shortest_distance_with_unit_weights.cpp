#include<bits/stdc++.h>
using namespace std;

/*

graph type : undirected , directed ( work in both ) --> the only condition is of unit(constant) weight 
cycle : may be may mot be present - work on both 
edge weight : 1 (or constant like k)
source : single 
destination : all

SINGLE SOURCE SHORTEST PATH TO ALL THE NODES IN UNDIRECTED/DIRECTED GRAPH OF UNIT WEIGHT TO ALL THE NODES

BFS : take the source as root and run bfs and mark level of each node wrt to this node (simple normal level calculation)
(can also be done using DFS level calculation --> exact same as marking levels --> no change )

Also this way of writing is also correct 

*/

void bfs(int v,vector<int> adj[],int n){

    vector<int>dist(n+1);
    for(int i=1;i<=n;i++)dist[i]=INT_MAX;

    queue<int>q;
    q.push(v);
    dist[v]=0;

    while(q.size()){
        int node=q.front();
        q.pop();
        for(auto i:adj[node]){
            if(dist[node]+1<dist[i]){
                q.push(i);
                dist[i]=1+dist[node];
            }
        }
    }
    for(int i=1;i<=n;i++)cout<<dist[i]<<' ';
}
int main()
{
    int n,m;
    cin>>n>>m;

    vector<int>adj[n+1];

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs(1,adj,n);
}