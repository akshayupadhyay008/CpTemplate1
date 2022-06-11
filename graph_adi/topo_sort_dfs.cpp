#include<bits/stdc++.h>
using namespace std;

// topo sort --> only possible in DAG (directed acyclic(NO cycle) graph)
// topo sort --> the order of dfs ending (out time) --> outtime more(dfs end early) later in topo sort 
// topo sort --> parent should be before child for all parent and child relationships 

void dfs(int v,vector<int> adj[],vector<bool> &vis,stack<int> &stk){
    vis[v]=true;
    for(auto i:adj[v]){
        if(!vis[i]){
            dfs(i,adj,vis,stk);
        }
    }
    stk.push(v);
}
int main(){
    
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    vector<bool>vis(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    stack<int>stk;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,adj,vis,stk);
        }
    }
    vector<int>topo;
    while(stk.size()){
        topo.push_back(stk.top());
        stk.pop();
    }
    for(auto i:topo)cout<<i<<' ';

    return 0;
}