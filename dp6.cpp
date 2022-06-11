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

    ill dp[num+1];

    f0(i,0,num+1) {
        dp[i]=0;
    }

    dp[num]=0; // num to num 0 move 

    f3(i,num-1,0) {

        ill mn=intmax;
        f1(j,1,arr[i]) {
            if ((i+j)<=num) {
                // dp[i]=dp[i]+dp[i+j];
                // sum=sum+dp[i+j];
                mn=min(mn,dp[i+j]);
            }
        }

        if (mn==intmax) {
            dp[i]=intmax;
        }
        else {
            dp[i]=1+mn;
        }

    }

    cout<<dp[0]<<endl;

    f0(i,0,num+1){
        cout<<dp[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}