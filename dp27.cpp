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
ill dp[N][2];

ill solve(ill arr[],ill num ,ill check){

    if (num<=-1) {
        return 0;
    }   

    if (dp[num][check]!=-1) {
        return dp[num][check];
    }

    counter++;

    if (check==1) {
        return dp[num][check]=solve(arr,num-1,0); // you do not take this // only choice you have 
    }
    else {
        return dp[num][check]=max ( arr[num]+solve(arr,num-1,1) , solve(arr,num-1,0)  );
    }
}


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
        dp[i][0]=-1;
        dp[i][1]=-1;
    }

    ill ans=max ( arr[num-1] + solve(arr,num-2,1) , solve(arr,num-2,0) ) ;
                // taken --> 1 means taken the forward element so this cannot be 
                // 0 means --> the next element (forward ) is not taken so 2 choices here 
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



without dp
110

28654

with dp
110

38

*/