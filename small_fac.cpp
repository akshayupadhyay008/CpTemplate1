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

void multiply( vector <int> &v , int num) { // vector sent by reference and we make changes as we move 
    int carry=0;

    f0(i,0,v.size()) {
        int val=num*v[i]+carry;
        v[i]=val%10;
        carry=val/10;
    }

    while(1) {
        if (carry==0){
            break;
        }
        else {
            v.pb(carry%10);
            carry=carry/10;
        }
    }


}

void smallFac(ill num){

    vector <int> ans;
    ans.pb(1);

    f1(i,2,num){
        multiply(ans,i);
    }

    reverse(all(ans));

    for(auto x: ans){
        cout<<x<<"";
    }
    cout<<endl;

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
        
        ill num;
        cin>>num;

        smallFac(num);

    }
	return 0;
}