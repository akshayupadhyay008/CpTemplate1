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

    ill num,k;
    cin>>num>>k;

    ill arr[num][k];

    f0(i,0,num){
        f0(j,0,k){
            cin>>arr[i][j];
        }
    }

    ill dp[num][k]; 
    // dp[i][j] represents the cost of coloring ith house with color jth
    ill mn1=intmax;
    // ill mn1index=-1;

    ill mn2=intmax;
    // ill mn2index=-1;

    ill oldmn1=intmax;
    ill oldmn2=intmax;

    f0(i,0,num){
        f0(j,0,k){
            if (i==0) {
                dp[i][j]=arr[i][j];
                if (dp[i][j]<=mn1){
                    mn2=mn1;
                    // mn2index=mn1index;

                    mn1=dp[i][j];
                    // mn1index=j;
                }
                else if (dp[i][j]<mn2) {
                    mn2=dp[i][j];
                    // mn2index=j;
                }
            }
            else {
                // ill mn=intmax;
                // f0(x,0,k){
                //     if (x!=j){
                //         mn=min(mn,dp[i-1][x]);
                //     }
                // }
                if (dp[i-1][j]==oldmn1) {
                    dp[i][j]=arr[i][j]+oldmn2;
                }
                else if (dp[i-1][j]==oldmn2){
                    dp[i][j]=arr[i][j]+oldmn1;
                }
                else {
                    dp[i][j]=arr[i][j]+oldmn1;
                }


                // dp[i][j]=arr[i][j]+mn;
                if (dp[i][j]<=mn1){
                    mn2=mn1;
                    // mn2index=mn1index;

                    mn1=dp[i][j];
                    // mn1index=j;
                }
                else if (dp[i][j]<mn2) {
                    mn2=dp[i][j];
                    // mn2index=j;
                }
            }
        }

        oldmn1=mn1;
        oldmn2=mn2;
        mn1=intmax;
        mn2=intmax;

    }

    // f0(i,0,num){
    //     f0(j,0,k){
    //         cout<<dp[i][j]<< " ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;

    ill ans=intmax;

    f0(j,0,k) {
        ans=min(ans,dp[num-1][j]);
    }

    cout<<ans<<endl;


    return 0;
    
}
