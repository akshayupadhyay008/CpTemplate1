#include <bits/stdc++.h>
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


// dearrangements 
// 1 -> 0 
// 2 -> 1 
// 3 -> 2 
// 4 -> 9 
// 5 -> 44 


ill gcd(ill a, ill b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);     
}

ill ans=0;


const ill N1=1000;
const ill N2=1000;

ill dp[N1][N2];


ill solve(string str1,string str2,ill num1,ill num2){

    if (num1==-1 && num2==-1) {
        ans++;
        return 1;
    }
    if (num2==-1) {
        ans++;
        return 1;
    }
    if (num1==-1) {
        return 0;
    }

    if (dp[num1][num2]!=-1) {
        ans=ans+dp[num1][num2];
        return dp[num1][num2];
    }

    if (str1[num1]==str2[num2]) {
        return dp[num1][num2]=solve(str1,str2,num1-1,num2-1) + solve(str1,str2,num1-1,num2) ;
    }
    else {
        return dp[num1][num2]=solve(str1,str2,num1-1,num2);
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

	ill t,ic;
	cin>>t;
// 	for(ic=1;ic<=t;ic++){
    f1(ic,1,t) {

        string str1,str2;       
        cin>>str1>>str2;

        ill num1=str1.size();
        ill num2=str2.size();

        f0(i,0,num1+1){
            f0(j,0,num2+1) {
                dp[i][j]=-1;
            }
        }
        
        ans=0;

        ill ans1=solve(str1,str2,num1-1,num2-1);


        // both correct tried and tested 
        cout<<ans1<<endl; // returning from the answer 
        cout<<ans<<endl; // adding whenever the condition is satified 

    }
	return 0;
}