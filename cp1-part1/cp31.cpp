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


ill solve(ill n,ill m){
    if (n==0 || m==0){
        return 0;
    }


    // if (n==1 && m==1) {
    //     return inf;
    // }

        ill ans1=inf;

        if (m!=1) {
            ill div1=m/3;
            ill rm=m%3;
            if (rm!=0) {
                div1++;
            }

            ans1=div1*n;
        }

        ill ans2=inf;
        if (n!=1) {
            ill div2=n/3;
            ill rm2=n%3;
            if (rm2!=0) {
                div2++;
            }

            ans2=div2*m;
        }

        ill ans=min(ans1,ans2);

        // cout<<ans<<endl;
        return ans;
}

ill solve1(ill n,ill m) {
        ill div1=m/3;
        ill rm1=m%3;

        ill ans=0;
        ans=n*div1;

        ill div2=n/3;
        ill rm2=n%3;

        ans=ans+(div2*rm1);

        // cout<<ans<<endl;
        // cout<<rm1<<"   "<<rm2<<endl;
        // cout<<endl;


        // ans=ans+solve(rm1,rm2);

        if (rm1==0 && rm2==0) {

        }
        else if (rm1==0 && rm2==1) {
            // ans++;
        }
        else if (rm1==0 && rm2==2) {
            // ans++;
        }
        else if (rm1==1 && rm2==0) {
            // ans++;
        }

        else if (rm1==1 && rm2==1) {
ans++;
        }
        else if (rm1==1 && rm2==2) {
            ans++;
        }
        else if (rm1==2 && rm2==0) {
            ans++;
        }
        else if (rm1==2 && rm2==1) {
            ans++;
        }
        else if (rm1==2 && rm2==2) {
            ans++;
            ans++;
        }

        // cout<<ans<<endl;
        return ans;
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
	cin>>t;
    // t=1;

    f1(ic,1,t) {
        ill n,m;
        cin>>n>>m;

        // if (n<m) {
        //     swap(n,m);
        // }

        // ill div1=m/3;
        // ill rm1=m%3;

        // ill ans=0;
        // ans=n*div1;

        // ill div2=n/3;
        // ill rm2=n%3;

        // ans=ans+(div2*rm1);

        // ans=ans+solve(rm1,rm2);

        // cout<<ans<<endl;

        ill ans=min(solve1(n,m),solve1(m,n));

        cout<<ans<<endl;

    }  
    return 0;
}