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
 
// ill modInv(ill i, ill m) {return binExp(i,m-2,m);}
 
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
 
// const int N=10005;
// const int N=2005;
// int parent[N];
// int size[N];
 
// void make_set(int v) {
//     parent[v] = v;
//     size[v] = 1;
// }
 
// int find_set(int v) {
//     if (v == parent[v]) {
//         return v;
//     }
//     return parent[v] = find_set(parent[v]);
// }
 
// void union_set(int a, int b) {
//     a = find_set(a);
//     b = find_set(b);
//     if (a != b) {
//         if (size[a] < size[b]) {
//             swap(a, b);
//         }
//         parent[b] = a;
//         size[a] += size[b]; // updating the size of b is of no use because we will not use it anyway now 
//         // as when we will be asked to do sth with b we will operate on its parent b 
//     }
// }
 
// const ill N=100005;
// ill dp[N];
 
// ill solve(string str,ill i,ill num) {
//     if (i==num) {
//         return 1;
//     }
 
//     if (dp[i]!=-1) {
//         return dp[i];
//     }
 
//     if (str[i]=='m' || str[i]=='w') {
//         return dp[i]=0;
//     }
 
//     if (str[i]!='u' && str[i]!='n') {
//         return dp[i]=solve(str,i+1,num)%mod;
//     }
//     else if (str[i]=='u') {
//         if (i==num-1) {
//             return dp[i]=solve(str,i+1,num)%mod;
//         }
//         else {
//             if (str[i+1]=='u') {
//                 return dp[i]=(solve(str,i+1,num)%mod + solve(str,i+2,num)%mod)%mod;
//             }
//             else {
//                 return dp[i]=solve(str,i+1,num)%mod;
//             }
//         }
//     }
//     else { // 'n
//         if (i==num-1) {
//             return dp[i]=solve(str,i+1,num)%mod;
//         }
//         else {
//             if (str[i+1]=='n') {
//                 return dp[i]=(solve(str,i+1,num)%mod + solve(str,i+2,num)%mod)%mod;
//             }
//             else {
//                 return dp[i]=solve(str,i+1,num)%mod;
//             }
//         }
//     }
 
// }
 
 
int ok(ill mid,string& str,string& res,ill num,ill n2,ill arr[]) {
    if (mid>num-1) {
        return 0;
    }
 
    if (mid==-1) {
        return 1;
    }
 
 
    // string temp="";
    string temp;
    int isPresent[num];
    f0(i,0,num){
        isPresent[i]=1;
    }
 
    f1(i,0,mid){
        ill index=arr[i]-1;
        isPresent[index]=0;
    }
 
    f0(i,0,num){
        if (isPresent[i]) {
            // temp=temp+str[i];
            temp.pb(str[i]);
        }
    }
 
 
    ill check=1;
 
    ill i=0;
    ill j=0;
 
    ill n1=temp.size();
 
 
    while(1) {
        if (i==n1 || j==n2){
            break;
        }
 
        if (temp[i]==res[j]) {
            i++;
            j++;
        }
 
        else {
            i++;
        }
 
    }
 
    if (j==n2){
        return 1;
    }
    else {
        return 0;
    }
 
    
    // if (x<=key) return 1;
    // else return 0;
}
 
 
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
	// cin>>t;
    t=1;
 
    f1(ic,1,t) {
        
        string str;
        cin>>str;
 
 
        ill num=str.size();
 
        string res;
        cin>>res;
 
        ill n2=res.size();
 
        ill arr[num];
 
        f0(i,0,num){
            cin>>arr[i];
        }
        
 
        //  TTTTTTTTT(T)FFFFFFFFFF
    // THIS TRUE () IS POINTED BY THE lo
    ill lo=-1; // first valid candidate 
    ill hi=num+10; // invalid candidate
    ill mid;
 
    while(hi>lo+1){
        mid=lo+(hi-lo)/2;
        if (ok(mid,str,res,num,n2,arr)){
            lo=mid;
        }
        else {
            hi=mid;
        }
    }
 
    ill ans=lo+1;
    cout<<ans<<endl;
 
 
    }       
 
    return 0;
}