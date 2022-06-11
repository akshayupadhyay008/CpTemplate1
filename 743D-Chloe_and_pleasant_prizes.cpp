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


const ill N=200005;
vector <ill> adj[N];
bool vis[N];
ill value[N];
ill ans;

ill subsum[N];
ill mxsubsum[N];

ill dfs(ill root) {
    vis[root]=true;

    ill mx1=neginf;
    ill mx2=neginf;

    for(auto x: adj[root]) {
        if (!vis[x]) {
            
            ill temp=dfs(x);

            if (temp>=mx1) {
                mx2=mx1;
                mx1=temp;
            }
            else if (temp>mx2) {
                mx2=temp;
            }
        }
    }

    ans=max(mx1+mx2,ans);
    return mxsubsum[root];
}


ill dfs1(ill root) {
    vis[root]=true;

    ill sum=0;
    for(auto x: adj[root]) {
        if (!vis[x]){
            ill temp=dfs1(x);
            sum=sum+temp;
        }
    }

    subsum[root]=sum+value[root];
    return subsum[root];

}


ill dfs2(ill root) {
    vis[root]=true;

    ill mx=neginf;

    for(auto x: adj[root]) {
        if (!vis[x]){
            ill temp=dfs2(x);
            // sum=sum+temp;
            mx=max(mx,temp);
        }
    }

    mxsubsum[root]=max(subsum[root],mx);

    return mxsubsum[root];

}


int isLinear(ill root) {
    vis[root]=true;
    if (root==1 && adj[root].size() > 1) {
        return 1;
    }
    else if (adj[root].size() > 2) {
        return 1;
    }

    for(auto x:adj[root]) {
        if (!vis[x]) {
            ill c=isLinear(x);
            if (c==1) {
                return 1;
            }
        }
    }

    return 0;
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

    // spf_seive(); 

    ill t,ic;
	// cin>>t;
    t=1;

// // 	for(ic=1;ic<=t;ic++){
    f1(ic,1,t) {

        ill num;
        cin>>num;

        f1(i,1,num) { // 1 based 
            cin>>value[i];
            vis[i]=false;
        }

        if (num==1) {
            cout<<"Impossible"<<endl;
            continue;
        }

        ill x,y;

        f0(i,0,num-1) {
            cin>>x>>y;
            adj[x].pb(y);
            adj[y].pb(x);
        }

        int c=isLinear(1);

        if (c==0) {
            cout<<"Impossible"<<endl;
            continue;
        }

           f1(i,1,num) { // 1 based 
         
            vis[i]=false;
        }
        
        // if (check==0) {
            // cout<<"Impossible"<<endl;
            // continue;
        // }

        ans=neginf;

        ill dummy = dfs1(1);

        f1(i,1,num) { // 1 based 
         
            vis[i]=false;
        }

        ill d=dfs2(1);

         f1(i,1,num) { // 1 based 
         
            vis[i]=false;
        }

        ill ddd=dfs(1);


        cout<<ans<<endl;


    }       

    return 0;
}