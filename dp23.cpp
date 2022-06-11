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

ill counter;


const ill N=50;
const ill X=3;
ill dp[N][X];


ill solve(ill i,ill prev,ill num){
    // if (i==num) {
    //     return 1; // empty --> 1 way   // correct 
    // }

    if (i==num-1) {
        if (prev==1) {
            return 2;
        }
        else if (prev==0) {
            return 1;
        }
    }


 if (dp[i][prev]!=-1) {
        return dp[i][prev];
    }

    counter++;

    if (prev==1) {
        return dp[i][prev]=solve(i+1,1,num)+solve(i+1,0,num);
    }
    else {
        return dp[i][prev]=solve(i+1,1,num);
    }

}


// without dp

// 17711
// 17708


// with dp

// 17711
// 36

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    // the first position can start with 0 
    // or the first position can start with 1 
    // now we decide for the first index taking the prev as 0 or prev as 1 

    ill num;
    cin>>num;

f0(i,0,num+3){
        dp[i][0]=-1;
        dp[i][1]=-1;
    }


    ill ans=solve(1,0,num)+solve(1,1,num);
        //  solve index to be decided (1)  , prev character , num 
    cout<<ans<<endl;

    cout<<counter<<endl;

    return 0;
}