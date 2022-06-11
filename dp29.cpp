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

    ill num;
    cin>>num;

    ill arr[num][3];

    f0(i,0,num){
        f0(j,0,3) {
            cin>>arr[i][j];
        }
    }

    ill dp[num+1][3];

    dp[0][0]=0;
    dp[0][1]=0;
    dp[0][2]=0;

    f1(i,1,num){
        dp[i][0]=arr[i-1][0]+min(dp[i-1][1],dp[i-1][2]);
        dp[i][1]=arr[i-1][1]+min(dp[i-1][0],dp[i-1][2]);
        dp[i][2]=arr[i-1][2]+min(dp[i-1][0],dp[i-1][1]);
    }

    ill ans=min(dp[num][0],min(dp[num][1],dp[num][2]));
    cout<<ans<<endl;

    return 0;
    
}
