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

const ill N=100005;
vector <ill> adj[N];
int vis[N];
ill arr[N];

ill path[N];
ill gcdpath[N];
ill subtreegcd[N];

void dfs1(ill root,ill p) {
    vis[root]=1;
    path[root]=p;

    for(auto x:adj[root]) {
        if (!vis[x]) {
            dfs1(x,p);
        }
    }

}


void dfs2(ill root,ill g) {
    vis[root]=1;
    ill temp=gcd(g,arr[root]);
    gcdpath[root]=temp;

    for(auto x: adj[root]) {
        if (!vis[x]) {
            dfs2(x,temp);
        }
    }

}

ill dfs3(ill root){
    vis[root]=1;
    ill g=arr[root];

    for(auto x: adj[root]){
        if (!vis[x]) {
            ill y=dfs3(x);
            g=gcd(g,y);
        }
    }

    subtreegcd[root]=g;
    return g;

}


ill ans;


void dfs4(ill root,vector <ill> & pre ,vector <ill> & suff ) {
    vis[root]=1;
    // delete this 
    ill sum=0;

    for(auto x:adj[root]){
        if (!vis[x]) { // child
            sum=sum+subtreegcd[x];
        }
    }

    ill index=path[root];

    ill pregcd=pre[index-1];
    ill suffgcd=suff[index+1];

    ill g=gcd(pregcd,suffgcd);
    g=gcd(g,arr[1]);

    // path including this stored but we want not including this 
    // so parent path gcd
    // 1 --> parent store 
    // 2 --> parent find here only 

    ill par;

    for(auto x: adj[root]){
        if (vis[x]==1) {
            par=x;
            break;
        }
    }

    g=gcd(g,gcdpath[par]);

    sum=sum+g;

    ans=max(ans,sum);

    for(auto x:adj[root]){
        if (!vis[x]) {
            dfs4(x,pre,suff);
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

        ill x,y;
        f0(i,0,num-1){
            cin>>x>>y;
            adj[x].pb(y);
            adj[y].pb(x);
        }

        f1(i,1,num){
            cin>>arr[i];
        }

   f0(i,0,num+2){
            vis[i]=0;
        }


        path[1]=-1;
        vis[1]=1;


        ill p=0; 
        for(auto x: adj[1]) {
            if (!vis[x]) {
                p++; // 1 2 3 
                dfs1(x,p);
            }
        }   
        

        f0(i,0,num+2){
            vis[i]=0;
        }

        ill g=0;
        dfs2(1,g);

        f0(i,0,num+2){
            vis[i]=0;
        }

        ill dummy = dfs3(1);

        f0(i,0,num+2){
            vis[i]=0;
        }


        ill sz=adj[1].size();

        // ill pre[sz+1]; 
        vector <ill> pre(sz+1);
        // path 1 2 3 4 5 6 ...
        // 0 --> 1 
        // 1 --> paths 0 , 1 
        // num --> paths 0 , 1 // num

        // ill pre[sz+1];

        pre[0]=0;

        f0(i,0,sz){
            ill val=adj[1][i];
            ill g=subtreegcd[val];
            pre[i+1]=gcd(pre[i],g);
        }

        // ill suff[sz+2];
        vector <ill> suff(sz+2);

        // suff[num]= paths num
        // suff[num-1]=paths num num-1

        // suff[1]=num ............ 1
        suff[sz+1]=0;


        f3(i,sz,1){
            ill val=adj[1][i-1];
            ill g=subtreegcd[val];
            suff[i]=gcd(suff[i+1],g);
        }

        ans=0;

        ill sum=0;
        // remove root --> 1
        for(auto x: adj[1]) {
            sum=sum+subtreegcd[x];
        }

        ans=max(ans,sum);

     f0(i,0,num+2){
            vis[i]=0;
        }
        
        vis[1]=1;
        
        for(auto x:adj[1]) {    
            if (!vis[x]) {
                dfs4(x , pre ,suff);
            }
        }


        cout<<ans<<endl;

    }       

    return 0;
}