// https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/count-binary-strings-official/ojquestion'

#include <bits/stdc++.h>
using namespace std;

// #pragma GCC target ("avx2")
// #pragma GCC optimize ("O3")
// #pragma GCC optimize ("unroll-loops")
 
#define ill int long long
#define ld long double

#define fi first 
#define se second 
#define pb push_back 

#define MP make_pair

// #define fo(i,k,n) for(ill i=k;i<n;i++)
// #define fr(i,n,k) for(ill i=n;i>=k;i--)
 
#define f0(i,a,b) for(int i=a;i<b;i++)
#define f1(i,a,b) for(int i=a;i<=b;i++)
#define f2(i,a,b) for(int i=a;i>b;i--)
#define f3(i,a,b) for(int i=a;i>=b;i--)
 
#define all(a) a.begin(),a.end()
#define pii pair<ill,ill>

#define vi vector<ill>
#define mii map<ill,ill>


#define intmax 2147483647
#define intmin -2147483648

#define inf ( (1e18) + 10)
#define neginf (-1 * (1e18 + 10))
#define pi 3.141592653589
#define mod 1000000007
// 998244353
// #define mod 998244353
#define endl '\n'

ill dp[100][3];

ill solve(ill i,ill ch,ill num){
    if (i==num-1){
        return 1;
    }

    if (dp[i][ch]!=-1) {
        return dp[i][ch];
    }

    if (ch==0) {
        return dp[i][ch]=solve(i+1,1,num); // if we are 0 we cannot have 0 after this 
        // now understand it like this 
        // we are parent (big problem) --> in order to solve our problem we are using the answer of child (smaller problm)
        // we are asking child to give the answer (number of stringd of ) i+1 to num starting at 1 
        // then in all those we will append 0 and thus the number will be same and we return 
    }
    else {
        return dp[i][ch]=solve(i+1,1,num)+solve(i+1,0,num); // if we are 1 we can have 0 or 1 after this // both are valid 
        // similar explaination here also 
    }
}

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif  

    // initialise_fact();
    // final_seive();

    ill t,ic;
	// cin>>t;
    t=1;


    f1(ic,1,t) {
        
        ill num;
        cin>>num;

        f0(i,0,num+5){
            f0(j,0,3){
                dp[i][j]=-1;
            }
        }

        ill ans=solve(0,0,num) + solve(0,1,num);   
        // solve(i,ch,num) --> returns the number of binary strings starting with ch at the ith position
        // ie having ch at the ith position --> satisfying the given condition 

        cout<<ans<<endl;
    }  
    return 0;
}