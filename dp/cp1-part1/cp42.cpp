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

#define MP make_pair

// #define fo(i,k,n) for(ill i=k;i<n;i++)
// #define fr(i,n,k) for(ill i=n;i>=k;i--)
 
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
#define pi 3.141592653589
#define mod 1000000007
// 998244353
// #define mod 998244353
#define endl '\n'

// google -->     cout<<"Case #"<<ic<<": "<<ans<<endl; 
// cout<<fixed<<setprecision(12)<<ans<<endl;

// bool comp(const pair<pii,pii> &a, const pair<pii,pii> &b) {
//     ill val1=a.se.se;
//     ill val2=b.se.se;
//     // return (a.second < b.second);
//     if (val1>val2) {
//         return true;
//     }
//     else {
//         return false;
//     }
//     // return (a.fi < a.fi);  // if not by second (second are equal ) then by first 
// }

bool comp(const pair<string,ill> &a, const pair<string,ill> &b) {
    // ill val1=a.se.se;
    // ill val2=b.se.se;
    // // return (a.second < b.second);
    // if (val1>val2) {
    //     return true;
    // }
    // else {
    //     return false;
    // }
    return (a.se < b.se);  // if not by second (second are equal ) then by first 
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

ill be_rec(ill x,ill n) 
{
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

// ill binExp(ill x,ill n,ill m)
// {
//     ill res=1;
//     while(n)
//     {
//         if(n&1) res=(res*x)%m;
//         x=(x*x)%m;
//         n>>=1;
//     }
//     return res;
// }

// ill binExp(ill x,ill n)
// {
//     ill res=1;
//     while(n)
//     {
//         if(n&1) res=(res*x);
//         x=(x*x);
//         n>>=1;
//     }
//     return res;
// }

ill modInv(ill i, ill m) {return binpow(i,m-2,m);}

// ill fact[200005];
// ill ncr(ill n,ill r) {
//     return (n>=r?(fact[n]*modInv(fact[r],mod))%mod*modInv(fact[n-r],mod)%mod:0);
// }

// void initialise_fact(){
//     fact[0]=1;
//     fact[1]=1;
//     f0(i,2,200005) {
//         fact[i]=((fact[i-1]%mod)*(i%mod))%mod;
//     }
// }


// DSU ...

// const ill N=100005;
// // const int N=2005;
// ill parent[N];
// ill size1[N];

// void make_set(ill v) {
//     parent[v] = v;
//     size1[v] = 1;
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

    ill tt;
	// cin>>tt;
    tt=1;

    f1(ic,1,tt) {

        ill x,y;
        cin>>x>>y;

        string s1="";

        f3(i,64,0){
            if ((x&(1LL<<i))) {
                s1=s1+'1';
            }
            else {
                if (s1.size()==0){

                }
                else {
                    s1=s1+'0';
                }
            }
        }

        // string s2=to_string(y);
        string s2="";
        f3(i,64,0){
            if ((y&(1LL<<i))) {
                s2=s2+'1';
            }
            else {
                if (s2.size()==0){

                }
                else {
                    s2=s2+'0';
                }
            }
        }

        ill len=s1.size();


        string s3=s1;

        f3(i,len-1,0){
            if (s1[i]=='0') {
                s3.pop_back();
            }
            else {
                break;
            }
        }


        string s1rev=s1;
        reverse(all(s1rev));

        string s3rev=s3;
        reverse(all(s3rev));

        cout<<s1<<endl;
        cout<<s1rev<<endl;
        cout<<s2<<endl;
        cout<<s3<<endl;
        cout<<s3rev<<endl;

        ill check=0;

        f1(i,0,64){
            f1(j,0,64){

                string t1="";
                f1(a,1,i){
                    t1=t1+'1';
                }

                string t2="";
                f1(a,1,j){
                    t2=t2+'1';
                }

                if ((t1+s1+t2) == s2){
                    check=1;
                    break;
                }
            }
        }


        f1(i,0,64){
            f1(j,0,64){

                string t1="";
                f1(a,1,i){
                    t1=t1+'1';
                }

                string t2="";
                f1(a,1,j){
                    t2=t2+'1';
                }

                if ((t1+s1rev+t2) == s2){
                    check=1;
                    break;
                }
            }
        }


        f1(i,0,64){
            f1(j,0,64){

                string t1="";
                f1(a,1,i){
                    t1=t1+'1';
                }

                string t2="";
                f1(a,1,j){
                    t2=t2+'1';
                }

                if ((t1+s3+t2) == s2){
                    check=1;
                    break;
                }
            }
        }

        f1(i,0,64){
            f1(j,0,64){

                string t1="";
                f1(a,1,i){
                    t1=t1+'1';
                }

                string t2="";
                f1(a,1,j){
                    t2=t2+'1';
                }

                if ((t1+s3rev+t2) == s2){
                    check=1;
                    break;
                }
            }
        }

        if (check){
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }


    }

    return 0;
}