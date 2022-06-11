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

unordered_map <ill,ill> dp;

ill solve(ill num){
    if (num<=2) {
        return num;
    }
    
    if (dp.find(num)!=dp.end()){
        return dp[num];
    }
    
    return dp[num]=max(num,solve(num/2)+solve(num/3)+solve(num/4));
}
 
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
// 	ill t,ic;
// 	cin>>t;
// // 	for(ic=1;ic<=t;ic++){
//     f1(ic,1,t) {
	    
	ill num;
	
	while(cin>>num){
	    ill ans=solve(num);
	    cout<<ans<<endl;
	}
	    
	    
// 	}
	return 0;
}