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
ill dp[N];

ill solve(ill arr[],ill num){

    if (num<=-1) {
        return 0;
    }   

    if (dp[num]!=-1) {
        return dp[num];
    }

    counter++;

    // either take this or not take this 
    // max of them return 
    return dp[num]=max(arr[num]+solve(arr,num-2) , solve(arr,num-1));
    // if take then the prev cannot be taken --> so n-2 call 
    // if not take then prev can be taken --> so n-1 call   
}

// Question : Maximum sum you can get and you are not allowed to take consecutive elements 

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

    f0(i,0,num+5){
        dp[i]=-1;
    }

    ill ans=solve(arr,num-1);
    cout<<ans<<endl;

    cout<<endl<<counter<<endl;

    return 0;
    
}


/*

20
5
5
10
100
10
5
0
0
0
0
0
0
0
0
0
0
0
0
0
0
00
0
00
0
0
00

0
0




output
without dp

110

17710




with dp
110

20



*/