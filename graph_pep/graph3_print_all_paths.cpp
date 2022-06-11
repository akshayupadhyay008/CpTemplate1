#include <bits/stdc++.h>
using namespace std;
 
#define ill int long long
#define ld long double

#define fi first 
#define se second 
#define pb push_back 

#define MP make_pair

// #define fo(i,k,n) for(ill i=k;i<n;i++)
// #define fr(i,n,k) for(ill i=n;i>=k;i--)
 
#define f0(i,a,b) for(int i=a;i<b;i++)
#define f1(i,a,b) for(int i=a;i<=b;i++)
#define f2(i,a,b) for(int i=a;i>b;i--)
#define f3(i,a,b) for(int i=a;i>=b;i--)
 
#define all(a) a.begin(),a.end()
#define pii pair<ill,ill>

#define vi vector<ill>
#define mii map<ill,ill>

#define intmax 2147483647
#define intmin -2147483648

#define inf ( (1e18) + 10)
#define neginf (-1 * (1e18 + 10))
#define PI 3.141592653589
#define mod 1000000007
// 998244353
#define md 998244353
// #define endl '\n'

const ill N=1000;
vector <ill> adj[N];
int vis[N];

void dfs(ill root,ill node2,vector <ill>& paths){
    vis[root]=1;
    



    if (root==node2) {

        paths.pb(root);

        for(auto x:paths) {
            cout<<x<<" ";
        }
        cout<<endl;

        paths.pop_back();
        vis[root]=0;
        return;
    }
    

    paths.pb(root);

    for(auto x: adj[root]) {
        if (!vis[x]) {
            dfs(x,node2,paths);
        }
    }
    
    paths.pop_back();
    vis[root]=0;

    return;
}

int main() {

    // garph --> 
    // adjacency matrix 
    // adjacency list 

    ill num;
    cin>>num;

    ill m;
    cin>>m;
    
    f0(i,0,m){
        ill x,y,wt; // x -- y
        cin>>x>>y>>wt;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    ill node1,node2;
    cin>>node1>>node2;

    // print all paths 
    vector <ill> paths;

    f1(i,1,num){
        vis[i]=0;
    }

    dfs(node1,node2,paths);

    return 0;
};


// 7
// 8     
// 0 1 10
// 1 2 10
// 2 3 10
// 0 3 10
// 3 4 10
// 4 5 10
// 5 6 10
// 4 6 10
// 0
// 6

// 0 1 2 3 4 5 6 
// 0 1 2 3 4 6
// 0 3 4 5 6
// 0 3 4 6