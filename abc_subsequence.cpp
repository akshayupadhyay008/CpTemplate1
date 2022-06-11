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

ill dp[1000][5];

ill solve(ill i,ill num,string str,ill prev){
    if (i==num){
        if (prev==3) {
            return 1; // vaild subsequence (a...b...c...)
        }
        else {
            return 0; // not valid 
        }
    }


    // at any char you 2 choices --> take or not take ans you have to 
    // maintain a...b...c... (so for this you have to have a prev value --> depending on the prev value you have to decide whether to take this char or not take this )
    // the questions where the current selection is depenedent on the previous selection --> we have to follow this approach
    // maintaining and forwarding prev and taking decisions depending on prev 


    if (dp[i][prev]!=-1) {
        return dp[i][prev];
    }

    if (prev==0) {
        if (str[i]=='a') { // decide to take or not 
            ill ans1=solve(i+1,num,str,1); // decided to take --> prev change
            ill ans2=solve(i+1,num,str,0); // decided not to take --> prev do not change --> still searching for a 
            // return the sum because we want all the valid subseq.. which we can get by taking or not taking this 
            return dp[i][prev]=ans1+ans2;
        }
        else {
            // no choice 
            // we havent taken any so 'b' or 'c' we cannot take
            return dp[i][prev]=solve(i+1,num,str,0); // not taking this 
        }
    }
    else if (prev==1) { // ending at 'a' 
        if (str[i]=='a') {
            // 2 choices take it or not take it 
            ill ans1=solve(i+1,num,str,1); // taking this // prev remains 1 
            ill ans2=solve(i+1,num,str,1); // not taking this // prev remains 1 
            // note ans1 and ans2 are same --> but they are different because in 1 ith index  'a'  is taken and in 1 it is not taken but ans1 and ans2 so you can also return 2*solve(...);
            return dp[i][prev]=ans1+ans2;
        }
        else if (str[i]=='b') {
            // 2 choices take it or not take it 
            ill ans1=solve(i+1,num,str,2); // taking this // prev 2 
            ill ans2=solve(i+1,num,str,1); // not taking this // prev remains 1 
            return dp[i][prev]=ans1+ans2;
        }
        else if (str[i]=='c') {
            // cannot take
            return dp[i][prev]=solve(i+1,num,str,prev);
        }
    }
    else if (prev==2) { // ending at 'b' 
        if (str[i]=='a') {
            // cannot take 
            return dp[i][prev]=solve(i+1,num,str,prev);
        }
        else if (str[i]=='b') {
            // 2 choices take it or not take it 
            ill ans1=solve(i+1,num,str,2); // taking this // prev remains 1 
            ill ans2=solve(i+1,num,str,2); // not taking this // prev remains 1 
            // note ans1 and ans2 are same --> but they are different because in 1 ith index b is taken and in 1 it is not taken but ans1 and ans2 so you can also return 2*solve(...);
            return dp[i][prev]=ans1+ans2;
        }
        else if (str[i]=='c') {
            // 2 choices take it or not take it 
            ill ans1=solve(i+1,num,str,3); // taking this // prev 3 
            ill ans2=solve(i+1,num,str,2); // not taking this // prev remains 2
            return dp[i][prev]=ans1+ans2;
        }
    }
    else if (prev==3) {
        if (str[i]=='a') {
            // cannot take 
            return dp[i][prev]=solve(i+1,num,str,prev);
        }
        else if (str[i]=='b') {
            // cannot take 
            return dp[i][prev]=solve(i+1,num,str,prev);
        }
        else if (str[i]=='c') {
            // 2 choices take it or not take it 
            ill ans1=solve(i+1,num,str,prev); // taking this // prev remains 3 
            ill ans2=solve(i+1,num,str,prev); // not taking this // prev remains 3
            // note ans1 and ans2 are same --> but they are different because in 1 ith index b is taken and in 1 it is not taken but ans1 and ans2 so you can also return 2*solve(...);
            return dp[i][prev]=ans1+ans2;
        }
    }
    // else {
        return 0; // ese he for vscode 
    // }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    string str;
    cin>>str;

    ill num=str.size();

    f0(i,0,num+3){
        f0(j,0,5){
            dp[i][j]=-1;
        }
    }

    ill i=0;
    ill prev=0; // not taken any character yet --> signify using 0
    // as dp index starts with 0 1 ...
    // prev=0 none previous 
    // prev=1 a is the prev ( aa...a )
    // prev=2 b is the prev ( aaaa..abbbb....b )
    // prev=3 c is the prev ( aaaa..abbbb....bcccc....ccc )

    ill ans=solve(i,num,str,prev);
    cout<<ans<<endl;

    return 0;    
}
