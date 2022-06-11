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



const ill N=100;
const ill SUM=100;

ill dp[N][SUM];

ill knapsack(ill val[],ill wt[],ill total,ill i,ill num){

    if(i==num) { // nothing left so return 0 // no value in array left // have nothing
        return 0;
    }

    if (dp[i][total]!=-1 ) {
        return dp[i][total];
    }

    if (wt[i]>total) {
        return dp[i][total]=knapsack(val,wt,total,i+1,num);
    }
    else {
        // return dp[num][total]=max( knapsack(val,wt,total,num-1) , val[num]+knapsack(val,wt,total-wt[num],num-1) );
        return dp[i][total]=max( knapsack(val,wt,total,i+1,num) , val[i]+knapsack(val,wt,total-wt[i],i,num) ); // unbounded knapsack ... therefore calling for itself 
        // take and call for this only ( not ahead )
        // not take move ahead ( meaning for the next choice )
    }

}

// can also be done by starting with 0 index and 0 current sum also 
// but no differnece 

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ill num;
    cin>>num;

    ill val[num];
    ill wt[num];

    f0(i,0,num){
        cin>>val[i];
    }

    f0(i,0,num){
        cin>>wt[i];
    }

    ill total;
    cin>>total;

    f0(i,0,num+1+5) {
        f0(j,0,total+1+5) {
            dp[i][j]=-1;
        }
    }

    ill ans=knapsack(val,wt,total,0,num);
    cout<<ans<<endl;

    // f0(i,0,num+1) {
    //     f0(j,0,total+1+1) {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    return 0;
}