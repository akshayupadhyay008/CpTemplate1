#include<bits/stdc++.h>
using namespace std;

const int N=100005;
int parent[N];
int size[N];

void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
}

int find_set(int v) {
    if (v == parent[v]) {
        return v;
    }
    return parent[v] = find_set(parent[v]);
}

void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b]) {
            swap(a, b);
        }
        parent[b] = a;
        size[a] += size[b]; // updating the size of b is of no use because we will not use it anyway now 
        // as when we will be asked to do sth with b we will operate on its parent b 
    }
}


int main(){

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    return 0;
}