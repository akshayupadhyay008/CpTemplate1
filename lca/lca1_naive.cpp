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
vector <ill> adj[N];
// int vis[N];
ill par[N];


void dfs1(ill root,ill parent1){
    // vis[root]=1;
    par[root]=parent1;

    for(auto x: adj[root]){
        // if (!vis[x]){
        if (x!=parent1) { // for trees 
            dfs1(x,root);
        }
    }
}


ill lca1(ill x,ill y){
    vector <ill> pathx;
    vector <ill> pathy;


    ill t1=x;
    pathx.pb(t1);
    while(1) {
        if (t1==-1) {
            break;
        }
        else {
            t1=par[t1];
            pathx.pb(t1);
        }
    }

    ill t2=y;
    pathy.pb(t2);
    while(1) {
        if (t2==-1) {
            break;
        }
        else {
            t2=par[t2];
            pathy.pb(t2);
        }
    }

    reverse(all(pathx));
    reverse(all(pathy));

    ill ans=-1;

    ill i=0;
    ill j=0;
    while(1){
        if (i>=pathx.size() || j>=pathy.size()) {
            break;
        }
        if (pathx[i]==pathy[j]) {
            ans=pathx[i];
            i++;
            j++;
        }
        else {
            break;
        }
    }

    return ans;
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

    // for parent store 
    // considering 1 as root (will be given in ques)
    dfs1(1,-1); // parent[1]=-1 

    ill a,b; // nodes whose lca we want 
    cin>>a>>b;

    ill ans1=lca1(a,b);
    cout<<ans1<<endl;

    return 0;
}