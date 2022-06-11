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

    ill arr[num];

    f0(i,0,num){
        cin>>arr[i];
    }

    // can be converted to just 2 variables 
    // include and exclude 
    // no need of the array 
    // because only previous 2 values pe answer depend so 2 variables fine 

    ill dp[num+1][2];

    dp[0][0]=0;
    dp[0][1]=0;

    f1(i,1,num){
        dp[i][0]=max(dp[i-1][0],dp[i-1][1]);   // not including this and max value if not including this 
        dp[i][1]=arr[i-1]+dp[i-1][0];     // including this and max value if not including this
    }

    ill ans=max(dp[num][0],dp[num][1]);
    cout<<ans<<endl;

    return 0;
    
}
