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

const ill N = 200005;
ill dp[N][2][2][2];
ill par[N]; 

ill solve(ill i,ill num,ill arr[],int c1,int c2,int p) {

    if (i==num) {
        // return 1;
        if (c1==1) return 1;
        else return 0;
    }

    if (dp[i][c1][c2][p] != -1) {
        return dp[i][c1][c2][p];
    }

    if (c1==0) { // 2 choice --> 
        // start 
        // or 
        // not start   
        int pt;
        
        if (arr[i] >= 0) pt=0;
        else pt=1;

        ill ch1 = arr[i] * solve(i+1,num,arr,1,0,pt); // start , not ended 
        ill ch2 = solve(i+1,num,arr,0,0,p);

        if (ch1 >= ch2) {
            par[i]=1; // start 
            return dp[i][c1][c2][p] = ch1;
        }
        else {
            par[i]=0; // no start 
            return dp[i][c1][c2][p] = ch2;
        }

    }
    else { 
        // use this  -->  
        // or 
        // not use this  --> 

        ill pt;
        
        if (arr[i]*p >= 0) pt=0;
        else pt=1;

        ill ch1 = 1; // not using 
        ill ch2 = arr[i] * solve(i+1,num,arr,1,0,pt);

        if (p==0) { // +ve 
            if (ch2 >= 0) {
                
                if (ch1 >= ch2) {
                    par[i]=0; // end 
                    return dp[i][c1][c2][p] = ch1;
                }
                else {
                    par[i]=1; // not end 
                    return dp[i][c1][c2][p] = ch2;
                }

            }
            else {
                par[i]=0;
                return dp[i][c1][c2][p]=ch1;
            }
        }
        else { // 1 
            if (ch2<0) {
                par[i]=1;
                return dp[i][c1][c2][p]=ch2;
            }
            else {
                par[i]=0;
                return dp[i][c1][c2][p]=ch1;
            }
        }

        
    }

    return 1;
}

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

        ill num;
        cin>>num;

        f0(i,0,num+2) {
            f0(j,0,2) {
                f0(k,0,2) {

                    dp[i][j][k][0]=-1;
                    dp[i][j][k][1]=-1;
                    par[i]=0;
                }
            }
        }


        ill arr[num];

        f0(i,0,num) {
            cin>>arr[i];
        }

        ill ans = solve(0,num,arr,0,0,0);

        
        if (ans <= 0) {
            cout<<num<<" " << 0 << endl;
        }
        else {
            f0(i,0,num) {
                cout<<par[i]  << " ";
            }
            cout<<endl;

            ill x=0;
            ill y=0;

            f0(i,0,num) {
                if (par[i] == 0) {
                    x++;
                }
                else {
                    break;
                }
            }

            ill z=0;
            f0(i,0,num) {
                if (par[i]==0) {
                    break;
                }
                else {
                    z++;
                }
            }

            y= num-z;

            cout<<x << " " << y<< endl;
        }

    }           
    return 0;
}