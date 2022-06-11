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
 
#define ill long long int 
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
#define pii pair<ill,ill>

#define vi vector<ill>
#define mii map<ill,ill>

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

bool comp(const pair<ill,ill> &a, const pair<ill,ill> &b) {
    // ill val1=a.se-a.fi;
    // ill val2=b.se-b.fi;
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
        ill d1=a.fi-a.se;
        ill d2=b.fi-b.se;

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

ill be_rec(ill x,ill n) {
	if(n==0){
		return 1;
	}
	if(n%2==0){
		return be_rec((x*x),n/2);
	}
	return x*be_rec(x*x,(n-1)/2);
}

ill lcm(ill a,ill b) {
    return ((a/gcd(a,b))*b); // to avoid overflow 
}

ill modInv(ill i, ill m) {return binpow(i,m-2,m);}

// ill fact[2000005];
// ill ncr(ill n,ill r) {
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


// vector <ill> lis(vector <ill> &v){
//     // lis in nlogn
//     ill n=v.size();
//     vector <ill> temp;

//     f0(i,0,n) {
      
//         auto it = upper_bound(all(temp), v[i]); // for non decreasing (increasing and equal will work)
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

// const ill N=50005;
// // const int N=205;
// ill parent[N];
// ill size1[N];

// // vector <ill> adj[N];

// void make_set(ill v) {
//     parent[v] = v;
//     size1[v] = 1;
//     // adj[v].pb(v);
// }

// ill find_set(ill v) {
//     if (v == parent[v]) {
//         return v;
//     }
//     return parent[v] = find_set(parent[v]);
// }

// void union_set(ill a,ill b) {
//     a = find_set(a);
//     b = find_set(b);

//     if (a != b) {
//         if (size1[a] < size1[b]) {
//             swap(a, b);
//         }
        
//         parent[b] = a;
//         size1[a] += size1[b]; // updating the size of b is of no use because we will not use it anyway now 
//         // as when we will be asked to do sth with b we will operate on its parent b 
//         // size1[b] += size1[a];

//         // for(auto x: adj[b]) {
//         //     adj[a].pb(x);
//         // }

//         // adj[b].clear();
//     }
// }

long long compute_hash(string const& s) {
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}

const int maxn = 10005;
const int cat = 2;
long long p[cat], hashmod = 1e9 + 7;
long long pp[cat][maxn];
long long invpp[cat][maxn];
bool pcdone = 0;

#define sz(a) a.size()

struct Hash {
    vector<long long> h[cat], hr[cat];
    static void precalc() {
        if (pcdone) return;
        pcdone = 1;
        p[0]=599;
        p[1]=937;
        for (int i = 0; i < cat; ++i) {
            pp[i][0]=1;
        }
        for (int j = 0; j < cat; ++j) {
            for (int i = 1; i < maxn; ++i) {
                pp[j][i] = (pp[j][i - 1] * p[j]) % hashmod;                
            }
        }
        for (int j = 0; j < cat; ++j) {
            for (int i = 0; i < maxn; ++i) {
                invpp[j][i]=modInv(pp[j][i],mod);
            }
        }
    }
    Hash(string s) {
        build(s);
    }
    void build(string s) {
        precalc();
        for (int i = 0; i < cat; ++i) {
            h[i].assign(sz(s),0);
            hr[i].assign(sz(s),0);
        }
        for (int i = 0; i < cat; ++i) {
            h[i][0]=pp[i][0]*s[0];
        }
        for (int j = 0; j < cat; ++j) {
            for (int i = 1; i < sz(s); ++i) {
                h[j][i]=(h[j][i-1]+pp[j][i]*s[i])%hashmod;
            }
        }
        for (int i = 0; i < cat; ++i) {
            hr[i][sz(s)-1]=pp[i][0]*s[sz(s)-1];
        }
        for (int j = 0; j < cat; ++j) {
            for (int i = sz(s) - 2; i >= 0; --i)
            {
                hr[j][i]=(hr[j][i+1]+pp[j][sz(s)-i-1]*s[i])%hashmod;
            }            
        }
    }
    vector<ill> subhash(int l, int r) {
        if (l < 0 || r >= sz(h[0])) {
            vector<ill> dog;
            for (int i = 0; i < cat; ++i) {
                dog.pb(-2);
            }
            return dog;
        }
        if (r < l){
            vector<ill> dog;
            for (int i = 0; i < cat; ++i) {
                dog.pb(-1);
            }
            return dog;
        }
        if (l == 0){
            vector<ill> dog;
            for (int i = 0; i < cat; ++i) {
                dog.pb(h[i][r]);
            }
            return dog;
        }
        vector<ill> dog;
        for (int i = 0; i < cat; ++i) {
            dog.pb((h[i][r] - h[i][l - 1] + hashmod) * invpp[i][l] % hashmod);
        }
        return dog;
    }
    vector<ill> subhashrev(int l, int r) {
        if (l < 0 || r >= sz(h[0])) {
            vector<ill> dog;
            for (int i = 0; i < cat; ++i) {
                dog.pb(-2);
            }
            return dog;
        }
        if (r < l) {
            vector<ill> dog;
            for (int i = 0; i < cat; ++i) {
                dog.pb(-1);
            }
            return dog;
        }
        if (r == sz(hr[0]) - 1){
            vector<ill> dog;
            for (int j = 0; j < cat; ++j) {
                dog.pb(hr[j][l]);
            }
            return dog;
        }

        vector<ill> dog;
        for (int i = 0; i < cat; ++i) {
            dog.pb((hr[i][l] - hr[i][r + 1] + hashmod) * invpp[i][sz(hr[i]) - r - 1] % hashmod);
        }
        return dog;

    }
    bool ispalindrome(int l, int r) {
        return (subhash(l, r) == subhashrev(l, r));
    }
};

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

    ill tt=1; 
	cin>>tt;
    
    f1(ic,1,tt) {

        

    }           
    return 0;
}


