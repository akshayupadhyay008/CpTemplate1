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

ill dp[100][100];

ill solve(ill i,ill num,ill k,ill curr){

    // you are calling intelligently 
    // so base simple
    if (i==num+1) {
        if (curr==k) {
            return 1;
        }
        else {
            return 0;
        }
    }

    if (dp[i][curr]!=-1) {
        return dp[i][curr];
    }

    // every person has 2 choice --> he can start a new set or can join a previous set
    // (all the previous sets are different from one another ) --> so joining previous set will have 
    // curr set count number of choices (he can join any of them )
    // base cases --> if (i==1 --> has to form new set)
    if (i==1) {
        return dp[i][curr]=solve(i+1,num,k,curr+1);
    }
    // we have to fill k sets with atleast 1 person 
    // number of choices left = num-i+1 
    // number of sets left to be formed = k-curr
    // if (number of person <= number of sets ) --> has to form new set 
    else if (num-i+1 <= k-curr) {
        return dp[i][curr]=solve(i+1,num,k,curr+1);
    }
    // if curr==k --> no new set can be formed --> so 1 choice join previous set 
    else if (curr==k) {
        return dp[i][curr]=k*solve(i+1,num,k,curr); // k sets are there --> can join any one of them 
    }
    else {
        // 2 choices 
        return  dp[i][curr]=(curr*solve(i+1,num,k,curr)) + solve(i+1,num,k,curr+1); // can form new set or join any 1 of the previous set 
    }

}

// check using some PNC if you can do it 

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ill num,k;
    cin>>num>>k;

    f0(i,0,num+3){
        f0(j,0,k+3){
            dp[i][j]=-1;
        }
    }

    ill ans=solve(1,num,k,0); // number of ways of partitioning 1-->num people into k grps 
    // when the count of current active set is 0
    cout<<ans<<endl;

    return 0;    
}
