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

// google -->     cout<<"Case #"<<ic<<": "<<mn<<endl; 

// Driver function to sort the vector elements
// by second element of pairs
// bool comp(const pair<ill,ill> &a, const pair<ill,ill> &b) {
//     return (a.second < b.second);
//     return (a.fi < a.fi);  // if not by second (second are equal ) then by first 
// }

// this also worked :: 
bool comp(const pair<int,int> &a , const pair<int,int> &b )
{
    if(a.fi==b.fi)
        return a.se<b.se;
    return a.fi<b.fi;
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

// const int N=10005;
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
// vector <ill> adj[N];
// ill vis[N];

int getMid(int s, int e)
{
    return s + (e - s) / 2;
}
 
int MaxUtil(int* st, int ss, int se, int l,
            int r, int node)
{
 
    if (l <= ss && r >= se)
        return st[node];
 
    if (se < l || ss > r)
        return -1;
    int mid = getMid(ss, se);
     
    return max(MaxUtil(st, ss, mid, l, r,
                       2 * node + 1),
               MaxUtil(st, mid + 1, se, l,
                       r, 2 * node + 2));
}
 
void updateValue(int arr[], int* st, int ss, int se,
                 int index, int value, int node)
{
    if (index < ss || index > se)
    {
        // cout << "Invalid Input" << endl;
        return;
    }
     
    if (ss == se)
    {  
 
        arr[index] = value;
        st[node] = value;
    }
    else {
            int mid = getMid(ss, se);
             
            if (index >= ss && index <= mid)
                updateValue(arr, st,
                            ss, mid, index,
                            value, 2 * node + 1);
            else
                updateValue(arr,
                            st, mid + 1, se,
                            index,
                            value, 2 * node + 2);
             
            st[node] = max(st[2 * node + 1],
                       st[2 * node + 2]);
    }
    return;
}
 
int getMax(int* st, int n, int l, int r)
{
 
    if (l < 0 || r > n - 1 || l > r)
    {
        // printf("Invalid Input");
        return -1;
    }
 
    return MaxUtil(st, 0, n - 1, l, r, 0);
}
 
int constructSTUtil(int arr[], int ss, int se,
                    int* st, int si)
{
 
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
    int mid = getMid(ss, se);
     
    st[si] = max(constructSTUtil(arr, ss, mid, st,
                                 si * 2 + 1),
                 constructSTUtil(arr, mid + 1, se,
                                 st, si * 2 + 2));
     
    return st[si];
}
 
int* constructST(int arr[], int n)
{
 
    int x = (int)(ceil(log2(n)));
 
 
    int max_size = 2 * (int)pow(2, x) - 1;
 
 
    int* st = new int[max_size];
 
 
    constructSTUtil(arr, 0, n - 1, st, 0);
 
 
    return st;
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

    // spf_seive(); 

//     ill t,ic;
// 	cin>>t;
// // // 	for(ic=1;ic<=t;ic++){
//     f1(ic,1,t) {

        
//     }    

    int n,m;
    cin>>n>>m;

    char arr[n][m];

    f0(i,0,n){
        f0(j,0,m){
            cin>>arr[i][j];
        }
    }

    int down[m];

    f0(j,0,m){
        int check=1;

        f0(i,1,n){
            if (arr[i][j]=='.') {
                check=0;
                break;
            }
        }

        if (check == 1 ) {
            down[j]=1;
        }
        else {
            down[j]=0;
        }

    }


    int side[m+1];

    side[m]=0;


    f3(i,m-1,0) {
        if (i==m-1) {
            if (arr[0][i] == '.') {
                side[i]=0;
            }
            else {
                side[i]=i;
            }
        }
        else {
            if (arr[0][i] == '.' && arr[0][i+1] == '.') {
                side[i]=0;
            }
            else if  (arr[0][i] == '.' && arr[0][i+1] == 'X')  {
                side[i]=side[i+1];
            }
            else if  (arr[0][i] == 'X' && arr[0][i+1] == '.')  {
                side[i]=i;
            }
            else if  (arr[0][i] == 'X' && arr[0][i+1] == 'X')  {
                side[i]=side[i+1];
            }
            
        }
    }

    f0(i,0,m){
        if (down[i] == 0) {
            side[i]=0;
        }
    }

    int* st = constructST(side, m);

    ill q;
    cin>>q;

    ill x,y;

    while(q--) {
        cin>>x>>y;

        x--;
        y--;

        if (x==y) {
            cout<<"YES"<<endl;
            continue;
        }

        int ans=getMax(st, m, x, y);

        if (ans >= y) {
            cout<<"NO"<<endl;
        }
        else {
            cout<<"YES"<<endl;
        }

    }
    
    return 0;
}