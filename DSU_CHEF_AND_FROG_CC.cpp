#include<bits/stdc++.h> 
#include <iostream> 
#include <vector> 
#include <iterator>

using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define f(i,x,n) for(int i=x;i<(int)n;++i)
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define pq priority_queue<int>
#define pqs priority_queue<int,vi,greater<int>>	
#define vpii vector<pair<int,int>>
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define mpi map<int,int>
#define lb lower_bound 
#define ub upper_bound 

int mod=1e9+7;


// DSU :
const int mxn=101000;
const int N = mxn;

int parent[N]; // parent of that node (just preceding it)
int siz[N]; // size of the group in which that node is a part 

// used to initialise a particular group
void make_set(int v) {
    parent[v] = v; // parent itself 
    siz[v] = 1; // size of the group 1 
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (siz[a] < siz[b]){
            swap(a, b);
        }
        parent[b] = a;
        siz[a] += siz[b];
    }
}


void solve(){
    int n,k,p; cin>>n>>k>>p;
    f(i,0,n) make_set(i);
    vpii vt; 
    f(i,0,n){
        int x; cin>>x;
        vt.pb({x,i});
    }
    sort(all(vt));
    f(i,1,n)
        if((vt[i].ff - vt[i-1].ff)<=k) union_sets(vt[i].ss, vt[i-1].ss);
    f(i,0,p){
        int e,ee; cin>>e>>ee;
        if(find_set(e-1)==find_set(ee-1)) cout<<"Yes\n";
        else cout<<"No\n";
    }
}
 
int32_t main(){
 	ios_base::sync_with_stdio(false);cin.tie(NULL);	
	srand(time(0)); 	
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int t=1; //cin>>t;
	while(t--) solve();
	return 0;
}

/*

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
const int mod=1e9+7;
const int mxx=1e5+10;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ff first
#define ss second

int main(){
	IOS;
	ll t=1,i,j;
	while(t--){
	    ll n,p,k;
	    cin>>n>>k>>p;
	    ll a[n],b[n];
	    
	    for(i=0;i<n;i++){
	        cin>>a[i];
	        b[i]=a[i];
	    }
	    
	    sort(b,b+n);
	    map<ll,ll> mp;
	    
	    mp[b[0]]=0;
	    ll prev=b[0],pc=0;
	    
	    for(i=1;i<n;i++){
	        if((b[i]-prev)<=k)
	            mp[b[i]]=pc;
	        else{
	            pc++;
	            mp[b[i]]=pc;
	        }
	        prev=b[i];
	    }
	    
	    while(p--){
	        ll l,r;
	        cin>>l>>r;
	        if(mp[a[l-1]]==mp[a[r-1]])
	            cout<<"Yes\n";
	        else
	            cout<<"No\n";
	    }
	}
}


*/
