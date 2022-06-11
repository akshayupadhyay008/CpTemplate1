#include<bits/stdc++.h>
using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
 
#define ill int long long
#define ld long double

#define fi first 
#define se second 
#define pb push_back 
// #define fo(i,k,n) for(ill i=k;i<n;i++)
// #define fr(i,n,k) for(ill i=n;i>=k;i--)
 
#define f0(i,a,b) for(int i=a;i<b;i++)
#define f1(i,a,b) for(int i=a;i<=b;i++)
#define f2(i,a,b) for(int i=a;i>b;i--)
#define f3(i,a,b) for(int i=a;i>=b;i--)
 
#define all(a) a.begin(),a.end()
#define pii pair<ill,ill>
#define intmax 2147483647
#define intmin -2147483648
#define pi 3.141592653589
#define mod 1000000007
#define mdl 998244353
#define endl '\n'

const ill N=50;
const ill M=50;

ill arr[N][M];

ill dp[N][M];

ill counter=0;

ill solve(ill n,ill m) {
    if (n==0 && m==0) {
        return arr[0][0];
    }
    if (n<0 || m<0) {
        return intmax; // so that the other becomes the min (this should not be selected )
    }

    if (dp[n][m]!=-1) {
        return dp[n][m];
    }    

    counter++;

    return dp[n][m]=arr[n][m]+min(solve(n-1,m) , solve(n,m-1)) ;

}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ill n,m;
    cin>>n>>m;

    f0(i,0,n){
        f0(j,0,m){
            cin>>arr[i][j];
        }
    }

    f0(i,0,n+1){
        f0(j,0,m+1){
            dp[i][j]=-1;
        }
    }
    
    ill ans=solve(n-1,m-1);

    cout<<ans<<endl;

    f0(i,0,n+1){
        f0(j,0,m+1){
            cout<<dp[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<endl;


    cout<<counter;


    return 0;
}