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


// dearrangements 
// 1 -> 0 
// 2 -> 1 
// 3 -> 2 
// 4 -> 9 
// 5 -> 44 

// google -->     cout<<"Case "<<ic<<": "<<ans<<endl; 

// Driver function to sort the vector elements
// by second element of pairs
bool comp(const pair<ill,ill> &a, const pair<ill,ill> &b) {
    return (a.second < b.second);
    return (a.fi < a.fi);  // if not by second (second are equal ) then by first 
}

// this also worked :: 
// bool compare(const pair<int,int> &a , const pair<int,int> &b )
// {
//     if(a.ff==b.ff)
//         return a.ss>b.ss;
//     return a.ff<b.ff;
// }


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

ill modInv(ill i, ill m) {return binExp(i,m-2,m);}

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


// int spf[1000001];

// void spf_seive(){

//     for(int i=0;i<=1e6;i++){
//         spf[i] = i; // inilisation --> if a number is prime then spf=itself
//         // just similar to seive when we inilize every number with 1 ie prime 
//         // here also we inilise every number with prime 
//     }


//     for(int i=2;i*i<=1e6;i++){ // 100% similar to seive 
        
//         if(spf[i]==i){ // prime 
//             for(int j=i*i;j<=1e6;j+=i){ 
                
//                 if(spf[j]==j){ 
//                     // imp point // mark only when it is not marked by any other 
//                     // because we want spf
//                     spf[j]=i;
//                 }

//             }
//         }
//     }


// }


// void prime_factorisation_spf(ill num){

//     spf_seive();  

//     map <int,int > m;

    // while(num>1) {

    //     m[spf[num]]++;
    //     num=num/spf[num];

    // }

// }


// DSU ...

// const int N=100005;
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


int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif  

    // initialise_fact();

    // spf_seive(); 

    ill t,ic;
	cin>>t;
// 	for(ic=1;ic<=t;ic++){
    f1(ic,1,t) {

        ill num;
        cin>>num;

        ill arr[num];

        f0(i,0,num){
            cin>>arr[i];
        }

        ill premx[num];

        ill sum=0;
        f0(i,0,num){
            sum=sum+arr[i];
            ill mxx=max(sum,arr[i]);
            premx[i]=mxx;
        }

        ill suffmx[num];

      sum=0;
        f3(i,num-1,0){
            sum=sum+arr[i];
            ill mxx=max(sum,arr[i]);
            suffmx[i]=mxx;
        }


        // f0(i,0,num){
        //     arr[i]=-1*arr[i];
        // }

        ill premxneg[num];

   sum=0;
        f0(i,0,num){
            sum=sum+arr[i];
            // ill mxx=max(sum,arr[i]);
            ill mxx=min(sum,arr[i]);
            premxneg[i]=mxx;
        }

        ill suffmxneg[num];

      sum=0;
        f3(i,num-1,0){
            sum=sum+arr[i];
            ill mxx=min(sum,arr[i]);
            // ill mxx=max(sum,arr[i]);
            suffmxneg[i]=mxx;
        }


        f0(i,0,num){
            cout<<premx[i]<<" ";
        }
        cout<<endl;

        f0(i,0,num){
            cout<<suffmx[i]<<" ";
        }
        cout<<endl;

        f0(i,0,num){
            cout<<premxneg[i]<<" ";
        }
        cout<<endl;

        f0(i,0,num){
            cout<<suffmxneg[i]<<" ";
        }
        cout<<endl;

        ill ans=intmin;

        f0(i,0,num-1) {

        }


        cout<<endl;

    }

    return 0;
}