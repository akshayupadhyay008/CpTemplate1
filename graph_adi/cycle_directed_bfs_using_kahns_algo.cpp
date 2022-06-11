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

bool bfs(vector<int> adj[],vector<int> &inDeg,int n){
    
    queue<int>q; 
    for(int i=1;i<=n;i++){
        if(inDeg[i]==0)q.push(i);
    }
    int cnt=0;
    while(q.size()){
        int node=q.front();
        q.pop();
        cnt++;
        for(auto i:adj[node]){
            inDeg[i]--;
            if(inDeg[i]==0){
                q.push(i);
            }
        }
    }
    if(cnt==n)return 0;
    return 1;
}
int main(){

    int n,m;
    cin>>n>>m;

    vector<int>adj[n+1];
    vector<bool>vis(n+1);
    vector<int>inDeg(n+1);

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        inDeg[b]++;
    }

    bool valid=bfs(adj,inDeg,n);
    if(valid)cout<<"Cyclic"<<endl;
    else cout<<"Acyclic"<<endl;
}