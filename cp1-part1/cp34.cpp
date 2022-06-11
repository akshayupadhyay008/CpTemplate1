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

bool comp(const pair<pii,pii> &a, const pair<pii,pii> &b) {
    ill val1=a.se.se;
    ill val2=b.se.se;
    // return (a.second < b.second);
    if (val1>val2) {
        return true;
    }
    else {
        return false;
    }
    // return (a.fi < a.fi);  // if not by second (second are equal ) then by first 
}


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


// ill lcm(ill a,ill b) {
//     return ((a/gcd(a,b))*b); // to avoid overflow 
// }


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


// const ill N=200005;
// ill par[N];
// ill root;
// ill level[N];
// int vis[N];
// vector <ill> adj[N];


// void dfs1(ill root,ill lev){
//     level[root]=lev;
//     vis[root]=1;

//     for(auto x:adj[root]){
//         if (!vis[x]) {
//             dfs1(x,lev+1);
//         }
//     }
// }

// ill value[N];

// ill dis[];

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif  

    // initialise_fact();
    // final_seive();

    ill t,ic;
	cin>>t;
    // t=1;

    f1(ic,1,t) {

        ill num;
        cin>>num;

        ill x;

        ill par[num+1];
        ill value[num+1];
        ill root;

        f1(i,1,num){
            cin>>x;
            if (x==i) {
                par[i]=-1;
                root=i;
            }
            else {
                par[i]=x;
            }
        }

        ill arr[num];

        f0(i,0,num){
            cin>>arr[i];
        }

    
        if (arr[0]!=root){
            cout<<-1<<endl;
            continue;
        }

        // cout<<root<<endl;

        // f1(i,1,num){
        //     cout<<par[i] <<"  ";
        // }
        // cout<<endl;

        value[root]=0;
        ill prev=root;

        // ill dist[num+1];
        vector <ill> dist(num,-1);

        dist[root]=0;

        ill check=1;

        f0(i,1,num){
            ill prev_val=dist[prev];
            ill par_val;
            // if (dist[par[arr[i]]] != -1) { 
                par_val=dist[par[arr[i]]]; 
            // }
            // else {
            //     check=0;
            //     break;
            // }

            // cout<<i <<"  " <<prev_val << "  "<<par_val <<endl;

            // if (prev_val-par_val+1 <= 0) {
            //     check=0;
            //     break;
            // }
            // else {
                value[arr[i]]=prev_val-par_val+2;
                dist[arr[i]]=value[arr[i]]+dist[par[arr[i]]];
                prev=arr[i];
            // }

        }

        if (check==0) {
            cout<<-1<<endl;
            continue;
        }

        f1(i,1,num){
            if (i!=root) {
                if (dist[i]<dist[par[i]]) {
                    check=0;
                }
            }
        }

        vector < pii > v;

        f1(i,1,num) {
            // cout<<dist[i]<<"  ";
            v.pb({dist[i],i});
        }
        // cout<<endl;

        sort(all(v));

        f0(i,0,num){
            // cout<<v[i] <<"  ";
            if (v[i].se!=arr[i]){
                check=0;
            }
        }
        // cout<<endl;

if (check) {


        f1(i,1,num){
            cout<<value[i]<<" ";
        }
        cout<<endl;
        }
        else {
            cout<<-1<<endl;
        }

        // f0(i,0,num+3){
        //     vis[i]=0;
        // }

        // dfs1(root,0);

        // map <ill,vector <ill> > m;

        // f0(i,0,num){
        //     ill node=arr[i];
        //     m[level[node]].pb(node);
        // }

        // for(auto x: m){
        //     ill sz=x.se.size();
        //     f3(i,sz-1,0){
        //         value[x.se[i]]=i+10;
        //     }
        // }


    }  
    return 0;
}