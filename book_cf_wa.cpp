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

// google -->     cout<<"Case #"<<ic<<": "<<ans<<endl; 
// cout<<fixed<<setprecision(12)<<ans<<endl;

ill gcd(ill a, ill b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);     
}

ill binpow(ill a, ill b,ill m) {
    if (b == 0)
        return 1;

    ill res = binpow(a, b / 2,m);
    if (b % 2)
        return (res%m * res%m * a%m)%m;
    else
        return (res%m * res%m)%m;
}

ill be_rec(ill x,ill n) 
{
	if(n==0){
		return 1;
	}
	if(n%2==0){
		return be_rec((x*x),n/2);
	}
	return x*be_rec(x*x,(n-1)/2);
}


ill lcm(ill a,ill b) {
    return ((a/gcd(a,b))*b); // to avoid overflow 
}


// ill binExp(ill x,ill n,ill m)
// {
//     ill res=1;
//     while(n)
//     {
//         if(n&1) res=(res*x)%m;
//         x=(x*x)%m;
//         n>>=1;
//     }
//     return res;
// }


// ill binExp(ill x,ill n)
// {
//     ill res=1;
//     while(n)
//     {
//         if(n&1) res=(res*x);
//         x=(x*x);
//         n>>=1;
//     }
//     return res;
// }

// ill modInv(ill i, ill m) {return binExp(i,m-2,m);}

// ill fact[200005];
// ill ncr(ill n,ill r) {
//     return (n>=r?(fact[n]*modInv(fact[r],mod))%mod*modInv(fact[n-r],mod)%mod:0);
// }

// void initialise_fact(){
//     fact[0]=1;
//     fact[1]=1;
//     f0(i,2,200005) {
//         fact[i]=((fact[i-1]%mod)*(i%mod))%mod;
//     }
// }

// DSU ...

// const int N=10005;
// const int N=2005;
// int parent[N];
// int size[N];

// void make_set(int v) {
//     parent[v] = v;
//     size[v] = 1;
// }

// int find_set(int v) {
//     if (v == parent[v]) {
//         return v;
//     }
//     return parent[v] = find_set(parent[v]);
// }

// void union_set(int a, int b) {
//     a = find_set(a);
//     b = find_set(b);
//     if (a != b) {
//         if (size[a] < size[b]) {
//             swap(a, b);
//         }
//         parent[b] = a;
//         size[a] += size[b]; // updating the size of b is of no use because we will not use it anyway now 
//         // as when we will be asked to do sth with b we will operate on its parent b 
//     }
// }

const ill N=200005;
vector <ill> adj[N];
int vis[N];
stack <ill> s;
vector <ill> topo;

void dfs(ill root) {
    vis[root]=1;

    for(auto x: adj[root]) {
        if (!vis[x]) {
            dfs(x);
        }
    }

    s.push(root);
}

int dfsvis[N];

bool dfs2(ill root) {
    vis[root]=1;
    dfsvis[root]=1;

    for(auto x: adj[root]) {
        if (!vis[x]) {
            bool check=dfs2(x);
            if (check) {
                return true;
            }
        }
        else if (dfsvis[x]==1) {
            return true;
        }
    }

    dfsvis[root]=0;
    return false;
}

ill dp[N];


void dfs3(ill root ,ill par){
    vis[root]=1;

    if (par != -1) {
        if (root > par) {
            dp[root]=max(dp[root],dp[par]);
        }
        else {
            dp[root]=max(dp[root],dp[par]+1);
        }
    }
    
    for(auto x: adj[root]) {
        if (!vis[x]) {
            dfs3(x,root);
        }
    }
}

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif  

    // initialise_fact();

    ill t,ic;
	cin>>t;
    // t=1;

    f1(ic,1,t) {
        ill num;
        cin>>num;


        f1(i,1,num){
            adj[i].clear();
            vis[i]=0;
        }

        topo.clear();

        f1(i,1,num) {
            ill sz;
            cin>>sz;

            f0(j,0,sz){
                ill x;
                cin>>x;

                adj[x].pb(i);
            }

        }


        f1(i,1,num){
            vis[i]=0;
            dfsvis[i]=0;
        }

        // ill root=-1;

        // ill mn=intmin;

        // f0(i,1,num) {
        //     if (adj[i].size()>mn){
        //         mn=adj[i].size();
        //         root=i;
        //     }
        // }

        // if (root==-1) {
        //     cout<<1<<endl;
        //     continue;
        // }
        // // cout<<root<<endl;


        // directed graph cyclic 
        bool ch=false; 

        // bool k=dfs2(root);

        // if (k) {
        //             ch=true;
                 
        //         }

        f1(i,1,num){
            if (!vis[i]) {
                bool k=dfs2(i);
                if (k) {
                    ch=true;
                    break;
                }
            }
        }

        if (ch) {
            cout<<-1<<endl;
            continue;
        }


        f0(i,0,num+2){
            vis[i]=0;
        }

        // dfs(root);

        f1(i,1,num){
            if (!vis[i]) {
                dfs(i);
            }
        }

        while(1){
            if (s.empty()) {
                break;
            }

            topo.push_back(s.top());
            s.pop();

        }


        // for(auto x: topo){
        //     cout<<x<<"  ";
        // }
        // cout<<endl;


        f1(i,1,num){
            dp[i]=1;
            vis[i]=0;
        }

        // root=topo[0];


        // dp[root]=1;
        // dfs3(root,-1);

        // f1(i,1,num){
        //     if (!vis[i]) {
        //         dp[i]=1;
        //         dfs3(i,-1);
        //     }
        // }


        for(auto x: topo) {
            if (!vis[x]) {
                // dp[x]=1;
                dfs3(x,-1);
            }
        }

        ill ans=0;

        f1(i,1,num) {
            // cout<<dp[i]<< "  " ;
            ans=max(dp[i],ans);
        }

        // cout<<endl;

        cout<<ans<<endl;


    }       

    return 0;
}