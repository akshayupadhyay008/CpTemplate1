#include<bits/stdc++.h>
using namespace std;

const int N=100005;
int parent[N];
int rank1[N];

void makeSet(int num){
    for(int i=0;i<=num;i++){
        parent[i]=i;
        rank1[i]=0;
    }
}

int findPar(int u, vector<int> &parent) {
    if(u == parent[u]) return u; 
    return parent[u] = findPar(parent[u], parent); 
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findPar(u, parent);
    v = findPar(v, parent);
    if(rank[u] < rank[v]) {
    	parent[u] = v;
    }
    else if(rank[v] < rank[u]) {
    	parent[v] = u; 
    }
    else {
    	parent[v] = u;
    	rank[u]++; 
    }
}

int main(){

    return 0;
}