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
// #define mod 1000000007
// 998244353
#define mod 998244353
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

bool comp(const pair<ill,ill> &a, const pair<ill,ill> &b) {
    // ill val1=a.se.se;
    // ill val2=b.se.se;
    // // return (a.second < b.second);
    // if (val1>val2) {
    //     return true;
    // }
    // else {
    //     return false;
    // }
    
    if (a.fi==b.fi) {
        return (a.se>b.se);
    }
    
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

ill fact[1000005];
// ill ncr(ill n,ill r) {
//     return (n>=r?(fact[n]*modInv(fact[r],mod))%mod*modInv(fact[n-r],mod)%mod:0);
// }

void initialise_fact(){
    fact[0]=1;
    fact[1]=1;
    f0(i,2,1000005) {
        fact[i]=((fact[i-1]%mod)*(i%mod))%mod;
    }
}


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

    initialise_fact();
    // final_seive();

    ill tt;
	// cin>>tt;
    tt=1;

    f1(ic,1,tt) {

        ill h,w,k;
        cin>>h>>w>>k;

        ill x1,y1;
        cin>>x1>>y1;

        ill x2,y2;
        cin>>x2>>y2;

        ill xp=abs(x1-x2);
        ill yp=abs(y1-y2);

        ill t=k-xp-yp;

        if (t<0) {
            cout<<0<<endl;
            continue;
        }

        if (t%2==1) {
            cout<<0<<endl;
            continue;
        }

        ill sum=t/2;

        ill ans=0;

        ill md=modInv(k,mod);
        
        // cout<<sum<<endl;


        f1(x,0,sum) {
            // x
            // y
            ill y=sum-x;
            ill xx=x+xp;
            ill yy=y+yp;
            
            cout<<"aa"<<endl;
            // if (x2>x1) {
            //     if (x1+xx>h || x1-x<=0) {
            //         continue;
            //     }
            // }
            // else {
            //     if (x1-xx<=0 || x1+x>h) {
            //         continue;
            //     }
            // }

            // if (y2>y1) {
            //     if (y1+yy>w || y1-y<=0) {
            //         continue;
            //     }
            // }
            // else {
            //     if (y1-yy<=0 || y1+y>w) {
            //         continue;
            //     }
            // }

            // ans=(ans+ (((fact[x]%mod*fact[y]%mod)%mod)*(fact[xx]%mod*fact[yy]%mod*md%mod)%mod)%mod)%mod;
            // ans=ans+((fact[xx]*fact[yy]*fact[x]*fact[y]))/fact[k];
            // ans=ans + (fact[k]/(fact[xx]*fact[yy]*fact[x]*fact[y]));
            ans=ans+((fact[k]%mod)*(modInv(fact[x],mod)%mod)*(modInv(fact[y],mod)%mod)*(modInv(fact[xx],mod)%mod)*(modInv(fact[yy],mod)%mod));
            ans=ans%mod;

        }

        cout<<ans<<endl;
    }   
    return 0;
}