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


int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ill n,m;
    cin>>n>>m;

    ill arr[n][m];

    f0(i,0,n){
        f0(j,0,m){
            cin>>arr[i][j];
        }
    }

    ill dp[n][m];

    f3(i,n-1,0) {
        f3(j,m-1,0) {
            if (i==n-1 && j==m-1) {
                dp[i][j]=arr[i][j];
            }
            else if (i==n-1) {
                dp[i][j]=arr[i][j]+dp[i][j+1];
            }
            else if (j==m-1) {
                dp[i][j]=arr[i][j]+dp[i+1][j];
            }
            else {
                dp[i][j]=arr[i][j]+min(dp[i][j+1],dp[i+1][j]);
            }
        }
    }

    f0(i,0,n){
        f0(j,0,m){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;


    return 0;
}