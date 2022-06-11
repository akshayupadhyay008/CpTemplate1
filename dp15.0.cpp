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

ill dp[100][100];

ill solve(ill i,ill num,ill arr[],ill target){
    if (i==num) {
        if (target==0) {
            return 1;
        }
        else {
            return 0;
        }
    }
    
    if (dp[i][target]!=-1)  {
        return dp[i][target];
    }

    // i have 2 choices 
    // either to take this --> taking this then you can choice to take this again so call i,target-sth not i+1
    // either not to take this --> not taking 1 choice --> move ahead 

    if (arr[i]>target){ // no choice move
        return dp[i][target]=solve(i+1,num,arr,target);
    }
    else {
        return dp[i][target]=solve(i+1,num,arr,target)+solve(i,num,arr,target-arr[i]);
    }
}


int main(){
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    ill num;
    cin>>num;

    ill arr[num];

    f0(i,0,num){
        cin>>arr[i];
    }

    ill target;
    cin>>target;

    f0(i,0,num+5){
        f0(j,0,target+5){
            dp[i][j]=-1;
        }
    }

    ill ans=solve(0,num,arr,target); // number of ways(only combinations) to pay target using infinite supply of all

    cout<<ans<<endl;

    return 0;
}