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

    // ill dp[num+1][2];

    // dp[0][0]=0; // string of len 0 and ending at 0 
    // dp[0][1]=0; // string of len 0 and ending at 1 

    // dp[1][0]=1; // string of len 1 and ending at 0 
    // dp[1][1]=1; // string of len 1 and ending at 1 
    ill zero=1;
    ill one=1;

    f1(i,2,num){
        // dp[i][0]=dp[i-1][1];
        // dp[i][1]=dp[i-1][0]+dp[i-1][1];
        ill newzero=one;
        ill newone=zero+one;

        one=newone;
        zero=newzero;
    }

    // ill ans=dp[num][0]+dp[num][1];
    ill ans=zero+one;
    cout<<ans<<endl;

    return 0;
    
}