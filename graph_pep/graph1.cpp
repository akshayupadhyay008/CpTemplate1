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



int main() {

    // garph --> 
    // adjacency matrix 
    // adjacency list 

    ill num;
    cin>>num;

    ill m;
    cin>>m;

    vector <ill> adj[num];
    
    // undirected 
    f0(i,0,m){
        ill x,y; // x -- y
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    
    // directed 
    f0(i,0,m){
        ill x,y; // x --> y
        cin>>x>>y;
        adj[x].pb(y);
    }


    // with weight undirected 
    vector <pii> adj1[num]; 

    f0(i,0,m){
        ill x,y,wt; // x -- y
        cin>>x>>y>>wt;
        adj1[x].pb({y,wt});
        adj1[y].pb({x,wt});
    }

    
    // directed 
    f0(i,0,m){
        ill x,y,wt; // x --> y
        cin>>x>>y>>wt;
        adj1[x].pb({y,wt});
    }



    return 0;
};