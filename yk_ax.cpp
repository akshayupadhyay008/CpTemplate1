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


// with mod 
// yogesh sir --> with mod 
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

ill fact[300000];
ill ncr(ill n,ill r) {return (n>=r?(fact[n]*modInv(fact[r],mod))%mod*modInv(fact[n-r],mod)%mod:0);}

//call this before using ncr 
// initialise_fact();  // call only 1 time before the test cases run 

void initialise_fact(){
    fact[0]=1;
    fact[1]=1;
    f0(i,2,300000) {
        fact[i]=((fact[i-1]%mod)*(i%mod))%mod;
    }
}



// sambhav sir --> with mod  
// int binExp(int x,int n)
// {
//     int res=1;
//     while(n)
//     {
//         if(n&1) res=(res*x)%mod;
//         x=(x*x)%mod;
//         n>>=1;
//     }
//     return res;
// }

// int modInv(int i) {return binExp(i,mod-2);}
// ill fact[300000];
// int ncr(int n,int r) {return (n>=r?(fact[n]*modInv(fact[r]))%mod*modInv(fact[n-r])%mod:0);}



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
        
        
	    
	    
	}
    return 0;
}

#define ff first
#define ss second
#define pb push_back
#define int long long
#define double long double
#define vi vector<int>
#define vb vector<bool>
#define vc vector<char>
#define vvi vector<vi>
#define vvb vector<vb>
#define vvc vector<vc>
#define vpii vector<pii>
#define pii pair<int, int>
#define Size(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define sortI(v) sort(v.begin(), v.end())
#define sortD(v) sort(v.begin(), v.end(), greater<int>())
#define sortIF(v) sort(v.begin(), v.end(), [&](pii a, pii b) { return a.ff < b.ff; })
#define sortIS(v) sort(v.begin(), v.end(), [&](pii a, pii b) { return a.ss < b.ss; })
#define sortDF(v) sort(v.begin(), v.end(), [&](pii a, pii b) { return a.ff > b.ff; })
#define sortDS(v) sort(v.begin(), v.end(), [&](pii a, pii b) { return a.ss > b.ss; })
#define ffor(i, a, n) for (int i = a; i < n; i++)
#define rfor(i, a, n) for (int i = n - 1; i >= a; i--)
#define pinf 1e18
#define ninf -1e18

int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
string yon[] = {"NO", "YES"};

const int N = 100005;
const int mod = 1000000007;

void scan(vi &v)
{
    for (int i = 0; i < v.size(); i++)
        cin >> v[i];
}

void print(vi v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int exp(int a, int b)
{
    a %= mod;
    int res = 1;
    while (b)
    {
        if (b % 2)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

double dist(pii a, pii b)
{
    double x = (a.ff - b.ff) * (a.ff - b.ff) + (a.ss - b.ss) * (a.ss - b.ss);
    return sqrt(x);
}

bool is_prime(int n)
{
    if (n == 1)
        return false;
    ffor(i, 2, (int)sqrt(n) + 1)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int fac(int n)
{
    if (n < 2)
        return 1;
    return n * fac(n - 1);
}

int nCr(int n, int r)
{
    if (r > n)
        return 0;
    if (r > n - r)
        r = n - r;
    int res = 1;
    ffor(i, 0, r)
    {
        res = res * (n - i) / (i + 1);
    }
    return res;
}


#define si(x) scanf("%d", &x)
#define pi(x) printf("%d", x)
#define sss(str) scanf("%s", str)
#define pl(x) printf("%lld", x)
#define sl(x) scanf("%lld", &x)
#define sii(x, y) scanf("%d %d", &x, &y)
#define sll(x, y) scanf("%lld %lld", &x, &y)
#define siii(x, y, z) scanf("%d %d %d", &x, &y, &z)
#define slll(x, y, z) scanf("%lld %lld %lld", &x, &y, &z)
using namespace std;
//Graph direction array[4]
//int dx[]={0,0,-1,1};
//int dy[]={1,-1,0,0};
//Graph direction array[8]
//dx[]={0,0,1,-1,-1,1,1,-1};
//dy[]={1,-1,0,0,-1,-1,1,1};
//Bishop direction array[8]
//dx[]={0,0,1,-1,-1,1,1,-1};
//dy[]={1,-1,0,0,-1,-1,1,1};
//Knight Direction array[8]
//dx[]={1,1,2,2,-1,-1,-2,-2};
//dy[]={2,-2,1,-1,2,-2,1,-1};
#define popcountL __builtin_popcountll
#define popcount __builtin_popcount
inline bool checkBit(int N, int pos){return (bool)(N & (1 << pos));}
inline int setBit(int N, int pos) { return N = N | (1 << pos); }
inline int unsetBit(int N, int pos) { return N = (N & (~(1 << pos))); }
inline int toggleBit(int N, int pos) { return N = (N ^ (1 << pos)); }
long long powerMod(long long number, long long power, long long mod)
{
    LL ret = 0;
    if (power == 0)
        return 1LL % mod;
    if (power == 1)
        return number % mod;
    if (power % 2 == 0)
    {
        ret = powerMod(number, power / 2, mod);
        ret = (ret % mod * ret % mod) % mod;
        return ret % mod;
    }
    else
    {
        ret = powerMod(number, power / 2, mod);
        ret = (ret % mod * ret % mod * number % mod) % mod;
        return ret % mod;
    }
}



string tobinary(ll n,ll length){
   string s;
   for(ll i=0;i<length;i++){
      if(n&1)s.push_back('1');
      else s.push_back('0');
	  n=n>>1;
   }reverse(s.begin(),s.end());return s;
}