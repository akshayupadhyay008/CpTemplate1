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


ill solve(ill i,ill single,ill num){
    if (i==num+1) { // 0 friends left for pairing 
        return 1; // doing nothing 
    }
    if (i==num) { // 1 person pair --> he/she can only remain single 1 way
        return 1;
    }
    if (i>num+1){
        return 0;
    }

    if (single>=0 && dp[i][single]!=-1) { // to avoid negative index of array 
        return dp[i][single];
    }

    // ith player has 2 choices --> he can remain single or can pair with someone 
    // single --> i+1 ke call 
    // pair --> cannot pair with a pair 
    // has to have the number of singles right now 
    // single-- he is also included in the single --> 
    // if single>=1 then --> pair with any one of them --> say x     so x ke leye decision is done and that person is also removed from the singles 
    // else can only remain in pair 

    // if (single<=1) { // actually we will never reach single<1 --> will be always ==1 or greater (because this person is left for pairing) //we will never reach this --> this is handled in base case 
    //     // only keep him single --> because that person is he only --> who is single 
    //     single--; // now this will remain single and no longer available for pairing 
    //     solve(i+1,single,num); // this is single make choices for rest
    // }
    // else {
        // 2 choices 
        // 1. make pair 
        // 2. or reamin single 
        ill ans1=solve(i+1,single-1,num); // now i'm not available for pairing 

        // i'm pairing so decision of other person done so i+2 call and single also -2 (give answer for rest left number of friends)
        // num-i decision was left with single singles 
        // now   num-i-2 and single-2 singles 
        ill ans2=(single-1)* solve(i+2,single-2,num); 

        return dp[i][single]=ans1+ans2;
    // }

    // return 0; // ese he 
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ill num;
    cin>>num;

    f0(i,0,num+3){
        f0(j,0,num+3){
            dp[i][j]=-1;
        }
    }
    ill i=1; // 1st friend 
    ill single=num; // number of single available for pairing 
    ill ans=solve(i,single,num); 
    // number of ways pairing i to num friends ie 1 to num friends  with   single number of singles (this is the count of the singles which are available for pairing )

    cout<<ans<<endl;

    // you can reduce the state of DP 
    // as we can see the   singles = num-i+1 always 
    // say num=4
    // you are making decision for i=1 first person 
    // number of person left for decision -->  num-i = 3 are left and if you are counting yourself also so num-i+1 are singles at present 
    // sigles-1 are others who are singles therefore single-1 se multiply 
    return 0;    
}
