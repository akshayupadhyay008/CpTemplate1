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

        if (str2.size()>str1.size()) {
            swap(str2,str1);
        }

        vector <int> v1;
        vector <int> v2;

        f0(i,0,str1.size()){
            v1.pb(str1[i]-'0');
        }

        f0(i,0,str2.size()){
            v2.pb(str2[i]-'0');
        }

        reverse(all(v1));
        reverse(all(v2));

        ill sz=v2.size();

        // vector <int> ans(v2.size()+1);
        vector <int> ans;

        int carry=0;
        f0(i,0,sz){
            int val=v1[i]+v2[i]+carry;
            if (val<=9) {
                // ans[i]=val;
                ans.pb(val);
                carry=0;
            }
            else {
                int rm=val%10;
                ans.pb(rm);
                carry=val/10;
            }

        }

        f0(i,sz,v1.size()){
            int val=v1[i]+carry;
            if (val<=9) {
                // ans[i]=val;
                ans.pb(val);
                carry=0;
            }
            else {
                int rm=val%10;
                ans.pb(rm);
                carry=val/10;
            }
        }

        if (carry>0) {
            ans.pb(carry);
        }

        reverse(all(ans));

        for(auto x: ans){
            cout<<x;
        }

        cout<<endl;


    }
	return 0;
}