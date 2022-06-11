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


// ill solve (ill num, char ch)  {

//     if (num==0) {
//         return 1;
//     }

//     counter++;

//     if (ch=='0') {
//         return solve(num-1,'1');
//     }
//     else if (ch=='1') {
//         return solve(num-1,'1')+solve(num-1,'0');
//     }

//     return 0;
// }


// 20

// without dp

// 17711
// 28654


// with dp

// 17711
// 38



const ill N=50;
const ill X=3;
ill dp[N][X];

ill solve (ill num, ill check)  {

    if (num==0) {
        return 1;
    }

    if (dp[num][check]!=-1) {
        return dp[num][check];
    }

    counter++;

    if (check==0) {
        return dp[num][check]=solve(num-1,1);
    }
    else if (check==1) {
        return dp[num][check]=solve(num-1,1)+solve(num-1,0);
    }

    return 0;
}


int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ill num;
    cin>>num;

    f0(i,0,num+3){
        dp[i][0]=-1;
        dp[i][1]=-1;
    }

    // string can end in 1 or 0 
    // ill ans=solve(num-1,'0') + solve(num-1, '1');
    ill ans=solve(num-1,0) + solve(num-1,1);
            // num-1 th index can end in 0 
            // num-1 th index can end in 1 
    cout<<ans<<endl;

    cout<<counter<<endl;
    return 0;
}