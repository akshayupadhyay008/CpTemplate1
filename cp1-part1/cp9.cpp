#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pbds                                               \
    tree<pair<int, int>, null_type, less<pair<int, int> >, \
         rb_tree_tag, tree_order_statistics_node_update>

using namespace std;
using namespace __gnu_pbds;
 
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
// 998244353
// #define mod 998244353
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

ill binpow(ill a, ill b,ill m) {
    if (b == 0)
        return 1;

    ill res = binpow(a, b / 2,m);
    if (b % 2)
        return (res%m * res%m * a%m)%m;
    else
        return (res%m * res%m)%m;
}



ill lcm(ill a,ill b) {
    return ((a/gcd(a,b))*b); // to avoid overflow 
}


ill binExp(ill x,ill n,ill m)
{
    ill res=1;
    while(n)
    {
        if(n&1) res=(res*x)%m;
        x=(x*x)%m;
        n>>=1;
    }
    return res;
}

ill modInv(ill i, ill m) {return binExp(i,m-2,m);}

// ill fact[300000];
// ill ncr(ill n,ill r) {return (n>=r?(fact[n]*modInv(fact[r],mod))%mod*modInv(fact[n-r],mod)%mod:0);}

// void initialise_fact(){
//     fact[0]=1;
//     fact[1]=1;
//     f0(i,2,300000) {
//         fact[i]=((fact[i-1]%mod)*(i%mod))%mod;
//     }
// }


int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif  


    // initialise_fact();

    ill t,ic;
	cin>>t;
// 	for(ic=1;ic<=t;ic++){
    f1(ic,1,t) {


        int num,m;
        cin>>m>>num;


        // ill arr[num];
        vector <ill> arr(num);

        f0(i,0,num){
            cin>>arr[i];
        }


        reverse(all(arr));        


        pbds s;


    // stores the answer
    vector<int> ans;
    for (int i = num - 1; i >= 0; i--) {
        if (i == num - 1) { 
            ans.push_back(0);
        }
        else { 
            ans.push_back(s.order_of_key({ arr[i], i }));
        }
        s.insert({ arr[i], i });
    }
 
    reverse(ans.begin(), ans.end());
    // for (auto x : ans)
    //     cout << x << " ";

   ill res=0;
   for(auto x: ans) {
       res=res+x;
   }

   cout<<res<<endl;
        	    
	}
    return 0;
}