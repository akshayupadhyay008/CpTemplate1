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

const ill N=50;
ill dp1[N];

ill fun1(ill num){
    if (num==0) {
        return 1;
    }
    if (num<0) {
        return 0;
    }

    if (dp1[num]!=-1) {
        return dp1[num];
    }

    return dp1[num]=fun1(num-1)+fun1(num-2)+fun1(num-3);
}




// ill dp2[N];

// ill solve(ill x,ill num){
//     if (x==num) {
//         return 1;
//     }
//     if (x>num){
//         return 0;
//     }

//     if (dp2[x]!=-1) {
//         return dp2[x];
//     }


//     return dp2[x]=solve(x+1,num)+solve(x+2,num)+solve(x+3,num);

// }




int main(){
    ill num=10;

    f0(i,0,num+1) {
        dp1[i]=-1;
    }

    ill res=fun1(num);
    // fun1(num)=fun1(num-1) + fun1(num-2) + fun1(num-3)
    cout<<res<<endl;


    ill dp[num+1];

    dp[0]=1;

    f0(i,1,num+1){
        if (i==1) {
            dp[i]=dp[i-1]; // rest -2 -3 negative 
        }
        else if (i==2) {
            dp[i]=dp[i-1]+dp[i-2];    
        }
        else {
            dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
        }        
    }

    cout<<dp[num]<<endl;



 // reason same as fib 


    // ill dpp[num+1];
    // // building the answer 
    // f0(i,0,num+1) {
    //     dpp[i]=0;
    // }

    // dpp[0]=1;

    // f0(i,0,num+1) {
    //     if (i+1 <= num ){
    //         dpp[i+1]=dpp[i+1]+dpp[i];
    //     }
    //     if (i+2 <= num ){
    //         dpp[i+2]=dpp[i+2]+dpp[i];
    //     }
    //     if (i+3 <= num ){
    //         dpp[i+3]=dpp[i+3]+dpp[i];
    //     }
    // }

    // cout<<dpp[num]<<endl;



    // cout<<endl;
    // cout<<endl<<endl;




// reason same as fib 

    // f0(i,0,num+1) {
    //     dp2[i]=-1;
    // }


    // ill res1=solve(0,num);
    // cout<<res1<<endl;

    // f0(i,0,num+1) {
    //     cout<<dp2[i]<< "  ";
    // }
    // cout<<endl;


    return 0;
}