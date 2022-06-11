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

    ill tar;
    cin>>tar;


    ill dp[num+1][tar+1];

    f1(i,0,num) {
        dp[i][0]=1;
    }


    f1(j,1,tar) {
        dp[0][j]=0;
    }


    f1(i,1,num){ // iterating over coin first --> to get combinations 
        f1(j,1,tar){ 
            if (j-arr[i-1] >= 0) {
                // dp[i][j]=dp[i-1][j]+dp[i-1][j-arr[i-1]];  --> in cannot repeat
                dp[i][j]=dp[i-1][j]+dp[i][j-arr[i-1]]; // can repeat 
            }
            else {
                dp[i][j]=dp[i-1][j];
            }
        }
    }


    cout<<dp[num][tar]<<endl;

    return 0;
}