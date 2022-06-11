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


int dp[50001][3][3][3][3][3];

int solve(int i,int prev1,int prev2,int prev3,int prev4,int prev5,int num,string &str) {
    if(i==num) {
        return 1;
    }

    if(dp[i][prev1][prev2][prev3][prev4][prev5]!=-1) {
        return dp[i][prev1][prev2][prev3][prev4][prev5];
    }
    if(str[i]=='0' or str[i]=='1') {
        int c=str[i]-'0'+1;
        
        if(i>=5 and prev1==c and prev2==prev5 and prev3==prev4) {
            return dp[i][prev1][prev2][prev3][prev4][prev5]=0;
        }

        if(i>=4 and prev2==c and prev3==prev5) {
            return dp[i][prev1][prev2][prev3][prev4][prev5]=0;
        }

        return dp[i][prev1][prev2][prev3][prev4][prev5]=solve(i+1,prev2,prev3,prev4,prev5,c,num,str);
    }
    else {
        int c1=2,c2=1;
        bool f1=true,f2=true;
        if(i>=5 and prev1==c1 and prev2==prev5 and prev3==prev4)f1=false;
        if(i>=4 and prev2==c1 and prev3==prev5)f1=false;
        if(i>=5 and prev1==c2 and prev2==prev5 and prev3==prev4)f2=false;
        if(i>=4 and prev2==c2 and prev3==prev5)f2=false;
        int ans=0;
        if(f1)ans|=solve(i+1,prev2,prev3,prev4,prev5,c1,num,str);
        if(f2)ans|=solve(i+1,prev2,prev3,prev4,prev5,c2,num,str);
        return dp[i][prev1][prev2][prev3][prev4][prev5]=ans;
    }
}

// const ill N=50005;
// ill dp[N][3][3][3][3][3];


// int solve(ill i,int prev1,int prev2,int prev3,int prev4,int prev5,ill num,string & str) {
//     if (i==num) {
//         return 1;
//     }

//     if (dp[i][prev1+1][prev2+1][prev3+1][prev4+1][prev5+1] != -1) {
//         return dp[i][prev1+1][prev2+1][prev3+1][prev4+1][prev5+1];
//     }
//     if (i<=3) {
//         prev5=prev4;
//         prev4=prev3;
//         prev3=prev2;
//         prev2=prev1;

//         if (str[i] == '0') {
//             prev1=0;
//             return dp[i][prev1+1][prev2+1][prev3+1][prev4+1][prev5+1] = solve(i+1,prev1,prev2,prev3,prev4,prev5,num,str);
//         }
//         else if (str[i]=='1') {
//             prev1=1;
//             return dp[i][prev1+1][prev2+1][prev3+1][prev4+1][prev5+1] = solve(i+1,prev1,prev2,prev3,prev4,prev5,num,str);
//         }
//         else {
//             prev1=0;
//             int ans1=solve(i+1,prev1,prev2,prev3,prev4,prev5,num,str);
//             prev1=1;
//             int ans2=solve(i+1,prev1,prev2,prev3,prev4,prev5,num,str);
//             int ans=(ans1|ans2);
//             return dp[i][prev1+1][prev2+1][prev3+1][prev4+1][prev5+1] = ans;
//         }
//     }
//     else if (i==4) {

//         int cur=-1;
//         if (str[i]=='1') {
            
//             cur=1;
//             bool check1=cur==1 && prev4==0;
//             bool check2=cur==0 && prev4==1;
//             bool check3=prev1==0 && prev3==1;
//             bool check4=prev1==1 && prev3==0;

//             if (((check1|check2)|(check3|check4))) {
//                 prev5=prev4;
//                 prev4=prev3;
//                 prev3=prev2;
//                 prev2=prev1;
//                 prev1=1;
//                 return dp[i][prev1+1][prev2+1][prev3+1][prev4+1][prev5+1] = solve(i+1,prev1,prev2,prev3,prev4,prev5,num,str);
//             }

//             return dp[i][prev1+1][prev2+1][prev3+1][prev4+1][prev5+1] = 0;

//         }
//         else if (str[i]=='0') {
            
//             cur=0;
//             bool check1=cur==1 && prev4==0;
//             bool check2=cur==0 && prev4==1;
//             bool check3=prev1==0 && prev3==1;
//             bool check4=prev1==1 && prev3==0;

//             if (((check1|check2)|(check3|check4))) {
//                 prev5=prev4;
//                 prev4=prev3;
//                 prev3=prev2;
//                 prev2=prev1;
//                 prev1=0;
//                 return dp[i][prev1+1][prev2+1][prev3+1][prev4+1][prev5+1] = solve(i+1,prev1,prev2,prev3,prev4,prev5,num,str);
//             }

//             return dp[i][prev1+1][prev2+1][prev3+1][prev4+1][prev5+1] = 0;

//         }
//         else {
//             {
//                 cur=0;
//                 bool check1=cur==1 && prev4==0;
//                 bool check2=cur==0 && prev4==1;
//                 bool check3=prev1==0 && prev3==1;
//                 bool check4=prev1==1 && prev3==0;

//                 if (((check1|check2)|(check3|check4))) {
//                     prev5=prev4;
//                     prev4=prev3;
//                     prev3=prev2;
//                     prev2=prev1;
//                     prev1=0;
//                     return dp[i][prev1+1][prev2+1][prev3+1][prev4+1][prev5+1] = solve(i+1,prev1,prev2,prev3,prev4,prev5,num,str);
//                 }
//             }

//             {
//                 cur=1;
//                 bool check1=cur==1 && prev4==0;
//                 bool check2=cur==0 && prev4==1;
//                 bool check3=prev1==0 && prev3==1;
//                 bool check4=prev1==1 && prev3==0;

//                 if (((check1|check2)|(check3|check4))) {
//                     prev5=prev4;
//                     prev4=prev3;
//                     prev3=prev2;
//                     prev2=prev1;
//                     prev1=1;
//                     return dp[i][prev1+1][prev2+1][prev3+1][prev4+1][prev5+1] = solve(i+1,prev1,prev2,prev3,prev4,prev5,num,str);
//                 }
//             }

//             return dp[i][prev1+1][prev2+1][prev3+1][prev4+1][prev5+1] = 0;
//         }
//     }
//     else {

//         int cur=-1;
//         if (str[i]=='1') {
            
//             cur=1;
//             bool check1=cur==1 && prev4==0;
//             bool check2=cur==0 && prev4==1;
//             bool check3=prev1==0 && prev3==1;
//             bool check4=prev1==1 && prev3==0;

//             bool c1=cur==1 && prev5==0;
//             bool c2=cur==0 && prev5==1;
//             bool c3=prev1==0 && prev4==1;
//             bool c4=prev1==1 && prev4==0;
//             bool c5=prev2==1 && prev3==0;
//             bool c6=prev2==0 && prev3==1;

//             bool c=((c1|c2)|((c3|c4)|(c5|c6)));

//             if (((check1|check2)|(check3|check4)) && c) {
//                 prev5=prev4;
//                 prev4=prev3;
//                 prev3=prev2;
//                 prev2=prev1;
//                 prev1=1;
//                 return dp[i][prev1+1][prev2+1][prev3+1][prev4+1][prev5+1] = solve(i+1,prev1,prev2,prev3,prev4,prev5,num,str);
//             }
//             return dp[i][prev1+1][prev2+1][prev3+1][prev4+1][prev5+1] = 0;

//         }
//         else if (str[i]=='0') {
            
//             cur=0;
//             bool check1=cur==1 && prev4==0;
//             bool check2=cur==0 && prev4==1;
//             bool check3=prev1==0 && prev3==1;
//             bool check4=prev1==1 && prev3==0;

//             bool c1=cur==1 && prev5==0;
//             bool c2=cur==0 && prev5==1;
//             bool c3=prev1==0 && prev4==1;
//             bool c4=prev1==1 && prev4==0;
//             bool c5=prev2==1 && prev3==0;
//             bool c6=prev2==0 && prev3==1;

//             bool c=((c1|c2)|((c3|c4)|(c5|c6)));

//             if (((check1|check2)|(check3|check4)) && c) {
//                 prev5=prev4;
//                 prev4=prev3;
//                 prev3=prev2;
//                 prev2=prev1;
//                 prev1=0;
//                 return dp[i][prev1+1][prev2+1][prev3+1][prev4+1][prev5+1] = solve(i+1,prev1,prev2,prev3,prev4,prev5,num,str);
//             }
//             return dp[i][prev1+1][prev2+1][prev3+1][prev4+1][prev5+1] = 0;

//         }
//         else {
//             {
                
//                 cur=1;
//                 bool check1=cur==1 && prev4==0;
//                 bool check2=cur==0 && prev4==1;
//                 bool check3=prev1==0 && prev3==1;
//                 bool check4=prev1==1 && prev3==0;

//                 bool c1=cur==1 && prev5==0;
//                 bool c2=cur==0 && prev5==1;
//                 bool c3=prev1==0 && prev4==1;
//                 bool c4=prev1==1 && prev4==0;
//                 bool c5=prev2==1 && prev3==0;
//                 bool c6=prev2==0 && prev3==1;

//                 bool c=((c1|c2)|((c3|c4)|(c5|c6)));

//                 if (((check1|check2)|(check3|check4)) && c) {
//                     prev5=prev4;
//                     prev4=prev3;
//                     prev3=prev2;
//                     prev2=prev1;
//                     prev1=1;
//                     return dp[i][prev1+1][prev2+1][prev3+1][prev4+1][prev5+1] = solve(i+1,prev1,prev2,prev3,prev4,prev5,num,str);
//                 }
                
//             }

//             {

//                 cur=0;
//                 bool check1=cur==1 && prev4==0;
//                 bool check2=cur==0 && prev4==1;
//                 bool check3=prev1==0 && prev3==1;
//                 bool check4=prev1==1 && prev3==0;

//                 bool c1=cur==1 && prev5==0;
//                 bool c2=cur==0 && prev5==1;
//                 bool c3=prev1==0 && prev4==1;
//                 bool c4=prev1==1 && prev4==0;
//                 bool c5=prev2==1 && prev3==0;
//                 bool c6=prev2==0 && prev3==1;

//                 bool c=((c1|c2)|((c3|c4)|(c5|c6)));

//                 if (((check1|check2)|(check3|check4)) && c) {
//                     prev5=prev4;
//                     prev4=prev3;
//                     prev3=prev2;
//                     prev2=prev1;
//                     prev1=0;
//                     return dp[i][prev1+1][prev2+1][prev3+1][prev4+1][prev5+1] = solve(i+1,prev1,prev2,prev3,prev4,prev5,num,str);
//                 }

//             }

//             return dp[i][prev1+1][prev2+1][prev3+1][prev4+1][prev5+1] = 0;
//         }

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

    ill tt=1; 
	cin>>tt;
    
    f1(ic,1,tt) {

        ill num;
        cin>>num;

        string str;
        cin>>str;

        f0(i,0,num+2) {
            f0(j1,0,3){
                f0(j2,0,3){
                    f0(j3,0,3){
                        f0(j4,0,3){
                            f0(j5,0,3){
                                dp[i][j1][j2][j3][j4][j5]=-1;
                            }
                        }
                    }
                }
            }
        }

        ill i=0;
        int prev1=-1;
        int prev2=-1;
        int prev3=-1;
        int prev4=-1;
        int prev5=-1;

        int ans=solve(0,0,0,0,0,0,num,str);

        if (ans==1) {
            cout<<"Case #"<<ic<<": "<<"POSSIBLE"<<endl; 
        }
        else {
            cout<<"Case #"<<ic<<": "<<"IMPOSSIBLE"<<endl; 
        }

    }           
    return 0;
}