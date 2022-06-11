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


// first of all --> this is counting permututaions 
// not combinations 


int dp1[6];

int solve1(int curr,int num){
    
    int ans=0; 
    int ans1,ans2,ans3;

    if (dp1[curr]!=-1) {
        return dp1[curr];
    }

    if (curr+1 > num) {

        ans1=0; 
    }
    else if (curr+1 == num ){
      
      ans1=1; 
    }
    else if (curr+1 < num) {

        ans1=solve1(curr+1,num);

    }



    // choice2 --> ans2 --> child 2 answer
    if (curr+2>num){
        ans2=0;
    }
    else if (curr+2==num){
        ans2=1;
    }
    else if (curr+2<num){
        ans2=solve1(curr+2,num);
    }


    if (curr+3>num){
        ans3=0;
    }
    else if (curr+3==num){
        ans3=1;
    }
    else if (curr+3<num){
        ans3=solve1(curr+3,num);
    }

    
    ans=ans1+ans2+ans3;

    cout<<curr<<"   " << ans<< endl;
// reduced reaching here 
// 4   1
// 3   2
// 2   4
// 1   7
// 0   13
// rest of the times return 


    return dp1[curr]=ans;

}




int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    
    // 0 to n 
    // intelligent call without array
    memset(dp1,-1,sizeof(dp1));

    for(int i=0;i<6;i++){
        cout<<i<<" " << dp1[i]<<endl;
    }
    cout<<endl;
// 0 -1       
// 1 -1       
// 2 -1       
// 3 -1       
// 4 -1       
// 5 -1       

    int num=5;
    int curr=0;
    int ans=solve1(curr,num);
    cout<<endl;
    cout<<ans<<endl;
// 13 


    return 0;
}