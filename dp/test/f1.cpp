#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ITER iterator
#define rep(i,s,e) for(int i=s;i<=e;i++)
#define brep(i,s,e) for(int i=s;i>=e;i--)
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x))
#define ones __builtin_popcount
#define fast std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define modi 1000000007;

ll pref[100005][32];

int main(){

    #ifndef ONLINE_JUDGE
        freopen("input6.txt", "r", stdin);
        freopen("output1.txt", "w", stdout);
    #endif

    fast;
    ll n,k,x;cin>>n>>k>>x;
    ll arr[n];
    for(int i = 0;i<n;i++)cin>>arr[i];
    mem(pref,0);
    for(int i = 0;i<n;i++){
        int c = 0;
        while(arr[i]){
            if(arr[i] & 1) pref[i+1][c]++;
            arr[i]/=2;
            c++;
        }
        for(int j = 0;j<=31;j++)pref[i+1][j] += pref[i][j];
    }
    int ans = 0;
    for(int i = k;i<=n;i++){
        ll mul = 1;
        ll tar = 0;
        for(int j = 0;j<=31;j++){
            if(pref[i][j]-pref[i-k][j])tar += mul;
            mul *= 2;
        }
        if(tar == x)ans++;
    }
    cout<<ans<<"\n";
    return 0;
}