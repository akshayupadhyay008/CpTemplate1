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

// dp not work in bool return type 
// because only 2 values true false no null value to identify 

// bool solve(ill arr[],ill num,ill tar) {
//     if (num==-1) {
//         if (tar==0) {
//             return true;
//         }
//         else {
//             return false;
//         }
//     }

//     counter++;

//     return (solve(arr,num-1,tar-arr[num])|solve(arr,num-1,tar));

// }

const ill N=50;
const ill M=500;

ill dp[N][M];

int solve(ill arr[],ill i,ill num,ill tar) {
    if (i==num) {
        if (tar==0) {
            return 1; // yes we can 
        }
        else {
            return 0; // no we cant 
        }
    }
    

    // to prevent negative index check // also a base condition 
    // if (tar<0) {
        // return 0; // no 
    // }

    if (dp[i][tar]!=-1) {
        return dp[i][tar];
    }

    counter++;

    //  || this makes it bool so do carefully 
    if (arr[i]<=tar){
        ill n1 =solve(arr,i+1,num,tar-arr[i]);  // take the ith 
        ill n2= solve(arr,i+1,num,tar); // do not take the ith 
        
        if (n1==1 || n2==1) {
            return dp[num][tar]=1;
        }
        else {
            return dp[num][tar]=0;
        }
    }
    else {
        return dp[num][tar]=solve(arr,i+1,num,tar); 
    }
    // return dp[num][tar]=(solve(arr,num-1,tar-arr[num]) || solve(arr,num-1,tar));

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

    ill tar;
    cin>>tar;

    f0(i,0,num+1) {
        f0(j,0,tar+1) {
            dp[i][j]=-1;
        }
    }

    ill check=solve(arr,0,num,tar); // whether we can create the target using array from 0 to num-1

    if (check){
        // cout<<"YES"<<endl;
        cout<<"true"<<endl;
    }
    else {
        // cout<<"NO"<<endl;
        cout<<"false"<<endl;
    }

    cout<<counter<<endl;


// without dp

// YES
// 47


// with dp

// YES
// 16

    return 0;
}