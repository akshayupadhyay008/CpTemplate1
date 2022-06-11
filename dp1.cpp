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


ill count1=0;

ill fib1(ill num) {
    if (num==0) {
        return 0;
    }
    if (num==1) {
        return 1;
    }

    count1++;

    return fib1(num-1)+fib1(num-2);
}



const ill N1=50;

ill dp1[N1];

ill count2=0;

ill fib2(ill num) {
    if (num==0) {
        return 0;
    }
    if (num==1) {
        return 1;
    }

    if (dp1[num]!=-1) {
        return dp1[num];
    }
    count2++;

    return dp1[num]=fib2(num-1)+fib2(num-2);
}


// nothing else --> exactly same 
// just moving from front 
// thats it 
// num = 0
// num-1 = 1 
// num-2 = 2
// just that 


// ill dp2[N1];

// ill solve(ill x,ill num){
//     if (x==num) {
//         return 0;
//     }
//     if (x==num-1) {
//         return 1;
//     }

//     if (dp2[x]!=-1) {
//         return dp2[x];
//     }


//     return dp2[x]=solve(x+1,num)+solve(x+2,num);

// }

int main(){

    ill num=10;
    ill res=fib1(num);
    // fib(num)=fib(num-1)+fib(num-2);
    // fib(0)=0
    // fib(1)=1
    // cout<<res<<endl;
    cout<<count1<<endl;


    f0(i,0,num+1) {
        dp1[i]=-1;
    }

    f0(i,0,num+1) {
        cout<<dp1[i]<<" ";
    }
    cout<<endl;

    res=fib2(num);
    cout<<res<<endl;

    
    f0(i,0,num+1) {
        cout<<dp1[i]<<" ";
    }
    cout<<endl;

    cout<<count2<<endl;


    ill dp[num+1];

    dp[0]=0;
    dp[1]=1;

    f1(i,2,num){
        dp[i]=dp[i-1]+dp[i-2];
    }

    cout<<dp[num];



// not always necesary that you will be able to just build your soln by add only 
// here just add was suffiecnt so worked 
// else whole sub storage would have generated the answer 
// here discrete way and build worked 
// but not always 
 
    // ill dpp[num+1];
    // f0(i,0,num+1){
    //     dpp[i]=0; // initiazed with zero 
    // }

    // dpp[0]=0;
    // dpp[1]=1;

    // f1(i,0,num-1){
    //     // this value will contribute in fibonaci of i+1 and i+2
    //     // by its addition 
    //     if ( i+1 <= num ) {
    //         // dp[i+1]=dp[i+1]+dp[i];
    //         dpp[i+1]+=dpp[i];
    //     }
    //     if ( i+2 <= num) {
    //         dpp[i+2]+=dpp[i];
    //     }
    // }

    // cout<<endl;
    // f0(i,0,num+1) {
    //     cout<<dpp[i]<< "  ";
    // }
    // cout<<endl;
    // cout<<endl<<endl;





// same as num-1 and num-2 call 

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