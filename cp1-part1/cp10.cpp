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

// ill fact[300000];
// ill ncr(ill n,ill r) {return (n>=r?(fact[n]*modInv(fact[r],mod))%mod*modInv(fact[n-r],mod)%mod:0);}

// void initialise_fact(){
//     fact[0]=1;
//     fact[1]=1;
//     f0(i,2,300000) {
//         fact[i]=((fact[i-1]%mod)*(i%mod))%mod;
//     }
// }



const int N=100;
int vis[N][N];

ill solve(string str,ill i,ill num,ill x,ill y){
    if (x<0 || y<0 || x>num-1 || y>num-1) {
        return 0;
    }

    if (i==num){
        if (x==0 && y==num-1) {
            return 1;
        }
        else {
            return 0;
        }
    }

    
    vis[x][y]=1;

    if (str[i]!='?') {
        if (str[i]=='U') {
            return solve(str,i+1,num,x+1,y);
        }
        else if (str[i]=='D') {
            return solve(str,i+1,num,x-1,y);
        }
        else if (str[i]=='R') {
            return solve(str,i+1,num,x,y+1);
        }
        else if (str[i]=='U') {
            return solve(str,i+1,num,x,y-1);
        }
        
    }

    return solve(str,i+1,num,x+1,y)+solve(str,i+1,num,x-1,y)+solve(str,i+1,num,x,y+1)+solve(str,i+1,num,x,y-1);

    vis[x][y]=0;
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

//     ill t,ic;
// 	cin>>t;
// // 	for(ic=1;ic<=t;ic++){
//     f1(ic,1,t) {

        
//     }

    string str;
    cin>>str;   

    ill num=str.size();

    f0(i,0,num+1){
        f0(j,0,num+1) {
            vis[i][j]=0;
        }
    }

    ill ans=solve(str,0,num,0,0);

    cout<<ans<<endl;

    return 0;
}