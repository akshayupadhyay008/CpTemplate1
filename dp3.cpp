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
    
    ill num;
    cin>>num;

    ill arr[num];

    f0(i,0,num){
        cin>>arr[i];
    }


// you are building the soln 
// works here but not always using simple addition you will be able to build the answer 



// not always necesary that you will be able to just build your soln by add only 
// here just add was suffiecnt so worked 
// else whole sub storage would have generated the answer 
// here discrete way and build worked 
// but not always 


    // ill dpp[num+1];
    
    // f0(i,0,num+1) {
    //     dpp[i]=0;
    // }

    // dpp[0]=1;

    // f0(i,0,num) {

    //     f1(j,1,arr[i]) {
    //         if (i+j <= num ) { 
    //             dpp[i+j]+=dpp[i];
    //         }
    //     }

    // }

    // cout<<dpp[num]<<endl;

    return 0;
}



// correct --> he is calling ahead 
// num to num --> 1 way 
// if not num then call for all the ways where you can make a visit 
// and add the answers from there 


// lli n;
// vec v;
// lli func(lli i){
//     if(i==n)fo 1;
//     if(i>n)fo 0;
//     lli s=0;
//     f(j,1,v[i]+1){
//         s+=func(i+j);
//     }   
//     fo s;
// }
// void solve()
// {
//     cin>>n;
//     in1(v,n);
//     cout<<func(0)<<endl;
// }