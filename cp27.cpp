#include <bits/stdc++.h>
using namespace std;

/*
// Ordered-Set (PBDS)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define os_find(k) os.find_by_order(k)
#define os_order(k) os.order_of_key(k)
*/
 
// #pragma GCC target ("avx2")
// #pragma GCC optimize ("O3")
// #pragma GCC optimize ("unroll-loops")
 
// #define int long long int 
#define ld long double

#define fi first 
#define se second 
#define pb push_back 

#define MP make_pair

#define f0(i,a,b) for(int i=a;i<b;i++)
#define f1(i,a,b) for(int i=a;i<=b;i++)
#define f2(i,a,b) for(int i=a;i>b;i--)
#define f3(i,a,b) for(int i=a;i>=b;i--)
 
#define all(a) a.begin(),a.end()
#define pii pair<int,int>

#define vi vector<int>
#define mii map<int,int>

#define intmax 2147483647
#define intmin -2147483648

#define inf ( (1e18) + 10)
#define neginf (-1 * (1e18 + 10))
#define PI 3.141592653589
#define mod 1000000007
// 998244353
#define md 998244353
#define endl '\n'

// google -->     cout<<"Case #"<<ic<<": "<<ans<<endl; 
// cout<<fixed<<setprecision(12)<<ans<<endl;

bool comp(const pair<int,int> &a, const pair<int,int> &b) {
    // int val1=a.se-a.fi;
    // int val2=b.se-b.fi;
    // // return (a.second < b.second);
    // if (val1>val2) {
    //     return true;
    // }
    // else {
    //     return false;
    // }
    
    // if (a.fi==b.fi) {
        // return (a.se>b.se);
    // }    

    if (a.fi != b.fi) {
        return a.fi<b.fi; 
    }
    else {
        int d1=a.fi-a.se;
        int d2=b.fi-b.se;

        if (d1>d2) {
            return true;
        }
        else {
            return false;
        }
        // return a.se<b.se;
    }
    
    // return a.fi<b.fi;
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);     
}

int binpow(int a, int b,int m) {
    if (b == 0)
        return 1;

    int res = binpow(a, b / 2,m);
    if (b % 2)
        return (res%m * res%m * a%m)%m;
    else
        return (res%m * res%m)%m;
}

int be_rec(int x,int n) {
	if(n==0){
		return 1;
	}
	if(n%2==0){
		return be_rec((x*x),n/2);
	}
	return x*be_rec(x*x,(n-1)/2);
}

int lcm(int a,int b) {
    return ((a/gcd(a,b))*b); // to avoid overflow 
}

int modInv(int i, int m) {return binpow(i,m-2,m);}

// int fact[2000005];
// int ncr(int n,int r) {
//     return (n>=r?(fact[n]*modInv(fact[r],mod))%mod*modInv(fact[n-r],mod)%mod:0);
//     // return (n>=r?(fact[n]*modInv(fact[r],md))%md*modInv(fact[n-r],md)%md:0);
// }

// void initialise_fact(){
//     fact[0]=1;
//     fact[1]=1;
//     f0(i,2,2000005) {
//         fact[i]=((fact[i-1]%mod)*(i%mod))%mod;
//         // fact[i]=((fact[i-1]%md)*(i%md))%md;
//     }
// }



// vector<int> prefix_function(string &s) {
    
//     int n = (int)s.length();
//     vector<int> pi(n,0);
    
//     for (int i = 1; i < n; i++) {
//         int j = pi[i-1];
//         while (j > 0 && s[i] != s[j])
//             j = pi[j-1];
//         if (s[i] == s[j])
//             j++;
//         pi[i] = j;
//     }

//     return pi;
// }


// vector <int> lis(vector <int> &v){
//     // lis in nlogn
//     int n=v.size();
//     vector <int> temp;

//     f0(i,0,n) {
      
//         auto it = upper_bound(all(temp), v[i]); // for non decreasing (increasing and equal wint work)
//         // auto it = lower_bound(all(temp), v[i]); // for strictly increasing 
            
//         if (it == temp.end()) {
//             temp.pb(v[i]);
//         }
//         else {
//             *it = v[i];
//         }
//     }
//    return temp;
// }


// DSU ...

// const int N=50005;
// // const int N=205;
// int parent[N];
// int size1[N];

// // vector <int> adj[N];

// void make_set(int v) {
//     parent[v] = v;
//     size1[v] = 1;
//     // adj[v].pb(v);
// }

// int find_set(int v) {
//     if (v == parent[v]) {
//         return v;
//     }
//     return parent[v] = find_set(parent[v]);
// }

// void union_set(int a,int b) {
//     a = find_set(a);
//     b = find_set(b);

//     if (a != b) {
//         if (size1[a] < size1[b]) {
//             swap(a, b);
//         }
        
//         parent[b] = a;
//         size1[a] += size1[b]; // updating the size of b is of no use because we wint not use it anyway now 
//         // as when we wint be asked to do sth with b we wint operate on its parent b 
//         // size1[b] += size1[a];

//         // for(auto x: adj[b]) {
//         //     adj[a].pb(x);
//         // }

//         // adj[b].clear();
//     }
// }

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);  // --> for taking input output from .txt

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout);
    #endif   

    // initialise_fact();
    // final_seive();

    int tt=1; 
	// cin>>tt;
    
    f1(ic,1,tt) {

        int num;
        cin>>num;

        int arr[num];

        set <int> s;
        int mx=0;

        f0(i,0,num) {
            cin>>arr[i];
            s.insert(arr[i]);
            mx=max(mx,arr[i]);
        }

        vector <int> v;
        for(auto x: s) {
            v.pb(x);
        }
        int sz=v.size();

        int ans=0;
        
        f0(i,0,sz) {
            int val=v[i];

            if (val==1) {
                continue;
            }

            for(int j=1;j*val<=mx;j++) {
                auto it=s.lower_bound(val*(j+1));
                auto itr=it;
                if (it!=s.begin()) {
                    it--;
                    if ((*it) > (j*val)) {
                        ans=max(ans,((*it) - (j*val)));
                    }
                }
                if(itr==s.end())break;


            }
        }

        cout<<ans<<endl;

    }           
    return 0;
}