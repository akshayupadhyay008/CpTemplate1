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

    ill total_weight;
    cin>>total_weight;


    ill dp[total_weight+1]={0};

    dp[0]=0;

    // combination way 
    // permutation way also works well 
    // because order of element do not matter 

    f0(i,0,num){
        f0(j,1,total_weight+1) {
            if (j-wt[i] >= 0) {
                dp[j]=max(dp[j], val[i] + dp[j-wt[i]]);
            }
        }
    }

    cout<<dp[total_weight]<<endl;

    return 0;
}