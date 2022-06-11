
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


// ill ans;

vector <string > v;

void solve(string str,ill i,ill num) {
    if (i==num) {
        // ans++;
        // cout<<str<<endl;
        v.pb(str);
        return;
    }

    solve(str,i+1,num);
    f0(j,i,num){
        if (str[i]!=str[j]){
            swap(str[i],str[j]);
            solve(str,i+1,num);
            swap(str[i],str[j]);
        }
    }
}

 
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ill fac[10];
    fac[0]=0;
    fac[1]=1;
    
    f0(i,2,10){
        fac[i]=fac[i-1]*i;
    }
    
    string str;
    cin>>str;

    ill num=str.size();
    
    ill ans1=1;
    f0(i,1,num+1) {
        ans1=ans1*i;
    }
    
    map <char,int> m;
    f0(i,0,num){
        m[str[i]]++;
    }
    
    for(auto x: m) {
        ans1=ans1/fac[x.se];
    }
    
    // cout<<ans1<<endl;
    
    

    string res=str;

    // ill ans=1;
    // f0(i,1,num+1) {
    //     ans=ans*i;
    // }
    // cout<<ans<<endl;

    solve(str,0,num);
    
    cout<<v.size()<<endl;
    
    
    sort(all(v));
    
    for(auto x: v){
        cout<<x<<endl;
    }
    

	return 0;
}