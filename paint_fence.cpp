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

ill dp[500][5];

ill solve(ill i,ill num,ill k,ill state){
    if (i==num){
        return 1;
    }
    
    if (dp[i][state]!=-1) {
        return dp[i][state];
    }

    if (state==0) {
        return dp[i][state]=k*solve(i+1,num,k,1);  // choice any 1 of k colors 
    }
    else if (state==1) { 
        // 2 choices --> continue the same color OR choice a different color 
        return dp[i][state]=solve(i+1,num,k,2) + (k-1)*solve(i+1,num,k,1);
    }
    else if (state==2) {
        // cannot continue the color 
        // you can only choice a differnt color 
        return dp[i][state]=(k-1)*solve(i+1,num,k,1);
    }

    return 0; // vscode issue or for security // will never reach here 
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ill num,k;
    cin>>num>>k;

    f0(i,0,num+3){
        f0(j,0,5){
            dp[i][j]=-1;
        }
    }

    ill ans=solve(0,num,k,0); // 0 se num  in k colours   state --> 0(No consecutive)
    // 0 --> no consequtive 
    // 1 --> 1 consequtive 
    // 2 --> 2 consequtive 
    
    cout<<ans<<endl;
    
    return 0;    
}
