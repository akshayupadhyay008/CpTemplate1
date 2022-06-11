#include <bits/stdc++.h>
using namespace std;

// #pragma GCC target ("avx2")
// #pragma GCC optimize ("O3")
// #pragma GCC optimize ("unroll-loops")
 
// #define int int long long
#define ld long double

#define fi first 
#define se second 
#define pb push_back 

#define MP make_pair

// #define fo(i,k,n) for(int i=k;i<n;i++)
// #define fr(i,n,k) for(int i=n;i>=k;i--)
 
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
#define pi 3.141592653589
#define mod 1000000007
// 998244353
// #define mod 998244353
#define endl '\n'

// google -->     cout<<"Case #"<<ic<<": "<<ans<<endl; 
// cout<<fixed<<setprecision(12)<<ans<<endl;

// bool comp(const pair<pii,pii> &a, const pair<pii,pii> &b) {
//     int val1=a.se.se;
//     int val2=b.se.se;
//     // return (a.second < b.second);
//     if (val1>val2) {
//         return true;
//     }
//     else {
//         return false;
//     }
//     // return (a.fi < a.fi);  // if not by second (second are equal ) then by first 
// }

bool comp(const pair<int,int> &a, const pair<int,int> &b) {
    int val1=a.fi-a.se;
    int val2=b.fi-b.se;
    // return (a.second < b.second);
    if (val1>val2) {
        return true;
    }
    else {
        return false;
    }
    
    // if (a.fi==b.fi) {
    //     return (a.se>b.se);
    // }
    
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

int be_rec(int x,int n) 
{
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

// int binExp(int x,int n,int m)
// {
//     int res=1;
//     while(n)
//     {
//         if(n&1) res=(res*x)%m;
//         x=(x*x)%m;
//         n>>=1;
//     }
//     return res;
// }

// int binExp(int x,int n)
// {
//     int res=1;
//     while(n)
//     {
//         if(n&1) res=(res*x);
//         x=(x*x);
//         n>>=1;
//     }
//     return res;
// }

int modInv(int i, int m) {return binpow(i,m-2,m);}

// int fact[1000005];
// int ncr(int n,int r) {
//     return (n>=r?(fact[n]*modInv(fact[r],mod))%mod*modInv(fact[n-r],mod)%mod:0);
// }

// void initialise_fact(){
//     fact[0]=1;
//     fact[1]=1;
//     f0(i,2,1000005) {
//         fact[i]=((fact[i-1]%mod)*(i%mod))%mod;
//     }
// }


// DSU ...

// const int N=100005;
// // const int N=2005;
// int parent[N];
// int size1[N];

// void make_set(int v) {
//     parent[v] = v;
//     size1[v] = 1;
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
    // final_seive();

    int tt;
	// cin>>tt;
    tt=1;

    f1(ic,1,tt) {

        int num;
        cin>>num;

        // int arr[num];

        
        map <int,int> mp;

        f0(i,0,num){
            // cin>>arr[i];
            int x;
            cin>>x;
            mp[x]++;
        }


        // f0(i,0,num){
        //     mp[arr[i]]++;
        // }

        vector <int> v;

        for(auto x:mp){
            v.pb(x.se);
        }

        sort(all(v));

        f0(i,0,v.size()){
            cout<<v[i]<< " ";
        }
        cout<<endl;

        int en=v[v.size()-1];

        if (v.size()==1) {
            int ans=en;
            cout<<ans<<endl;
            continue;
        }
        
        multiset <int> s;

        f1(i,0,v.size()-2){
            s.insert(v[i]);
        }

        int ans=0;

        
        // f1(i,1,en) {
            int res=en;

            if (en%2==1) {
                ans=max(ans,res);
                continue;
            }

            // multiset <int> s1=s;    

            // cout<<i<<" -- > " <<endl;
            // for(auto x:s1){
            //     cout<<x<<"  ";
            // }
            // cout<<endl;

            // int curr=i; // even 
            int curr=en;

            while(1){
                
                auto it=s.lower_bound((curr/2)); // search for even/2

                if (it != s.end()) {
                    res=res+(curr/2); // found 
                    if ((curr/2)%2==1) {
                        break;
                    }

                    curr=curr/2;

                    s.erase(it);
                }
                else {
                    break;
                }
            }

            ans=max(ans,res);
            // s1.clear();

            // cout<<i<<"  "<<res<<endl;
        // }

        cout<<ans<<endl;
    }   
    return 0;
}