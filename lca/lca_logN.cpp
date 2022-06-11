#include <bits/stdc++.h>
using namespace std;

// #pragma GCC target ("avx2")
// #pragma GCC optimize ("O3")
// #pragma GCC optimize ("unroll-loops")
 
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
#define pi 3.141592653589
#define mod 1000000007
// 998244353
// #define mod 998244353
#define endl '\n'

const ill N=100005;
const ill lg=20; // should be gerater than log N + 1 
vector <ill> adj[N];
ill par[N][lg];
// int vis[N];

ill intime[N];
ill outtime[N];
ill timer;

void dfs_precal(ill root,ill parent1){
    // par[root][i] stores the 2^i th ancestor of the root
    par[root][0]=parent1; // root ka 2^0 ancestor is parent1

    intime[root]=timer;
    timer++;

    for(int i=1;i<lg;i++){
        if (par[root][i-1] == -1) {  // if (2^ i-1 )th ancestor of node do not exist then before it will automatically not exist
            par[root][i]=-1; // non existing nodes are -1 (above the root) (2^i becomes greater then depth from here)
        }
        else {
            par[root][i]=par[par[root][i-1]][i-1];
        }
    }

    for(auto x: adj[root]){
        // if (!vis[x]) {
        if (x!=parent1){
            dfs_precal(x,root);
        }
    }

    outtime[root]=timer;
    timer++;
}

bool is_ancestor(ill x,ill y) {
    // x is an ancestor of y or not 
    return (intime[x]<intime[y] && outtime[x]>outtime[y]);
}


ill lca(ill a,ill b){
    if (is_ancestor(a,b)) return a;
    if (is_ancestor(b,a)) return b;

    for(int i=lg-1;i>=0;i--){
        if (  par[a][i]!=-1  && (!is_ancestor(par[a][i],b))  )  {
            // par[a][i]!=-1 --> if the 2^i th parent exists 
            // !is_ancestor(par[a][i],b)  --> that node (2^i th parent) is not the ancestor of this --> we can jump to that safely 
            a=par[a][i]; // safely jumping to that 
        }
    }

    // by doing soo we will reach the just below node of LCA 
    // so we return its parent which will be the LCA.
    return par[a][0]; 
}

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ill num;
    cin>>num;

    ill x,y;
    f0(i,0,num-1)  {
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    // f0(i,0,num+3){
    //     vis[i]=0;
    // }

    timer=0;
    dfs_precal(1,-1); // here with intime and outtime  REST remains same  


    ill q;
    cin>>q;

    while(q--) {
        ill a,b;
        cin>>a>>b;
        
        ill ans=lca(a,b);

        cout<<ans<<endl;
    }


    return 0;
}