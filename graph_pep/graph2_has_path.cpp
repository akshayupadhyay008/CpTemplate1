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

int dfs(ill root,ill node2){
    vis[root]=1;

    if (root==node2) {
        return 1;
    }

    for(auto x: adj[root]) {
        if (!vis[x]) {
            int ch=dfs(x,node2);
            if (ch==1){
                return 1;
            }
        }
    }

    return 0;
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
        ill x,y; // x -- y
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    ill node1,node2;
    cin>>node1>>node2;

    // has path 

    f1(i,1,num){
        vis[i]=0;
    }

    int has_path=dfs(node1,node2);

    if (has_path==1) {
        cout<<"Has path - yes"<<endl;
    }
    else {
        cout<<"No"<<endl;
    }


    return 0;
};