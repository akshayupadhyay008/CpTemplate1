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
bool comp(const pair<ill,ill> &a, const pair<ill,ill> &b) {
    ill val1=a.fi-a.se;
    ill val2=b.fi-b.se;
    if (val1<val2){
        return true;
    }
    else {
        return false;
    }
    // return (a.second < b.second);
    // return (a.fi < a.fi);  // if not by second (second are equal ) then by first 
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
ill dp[30][30][2];

ill solve(ill i,ill num,ill arr[],ill fee,ill state,ill prev){
    if (i==num){ // no day left can do nothing
        return 0;
    }

    // if state = 0 --> you are looking for buying state --> this index can become the buying state or can remain empty(not used, forward to next) 
    // if state = 1 --> you are looking for selling state --> this index can become the selling state or can remain empty(not used, forward to next) 
    if (dp[i][prev][state]!=-1) {
        return dp[i][prev][state];
    }

    if (state==0) {
        ill ans1=solve(i+1,num,arr,fee,0,prev); // not taken this 
        ill ans2=solve(i+1,num,arr,fee,1,i); // taken this now looking for a selling state of this 
        return dp[i][prev][state]=max(ans1,ans2);
    }
    else if (state==1) {
        ill ans1=solve(i+1,num,arr,fee,state,prev); // not taking this 
        
        // if you are taking this you can only take this if --> profit is positive 
        if (arr[i]-arr[prev]-fee > 0) {
            // we are eligible to make this a buying day
            ill profit=arr[i]-arr[prev]-fee;
            
            // now this can also become a buying day or not a selling day (  b (sb) s   s and b can be same )
            // ill a1=solve(i+1,num,arr,fee,1,i); // this is  buying day
            // ill a2=solve(i+1,num,arr,fee,0,-1); // this is not buying day
            ill a2=solve(i+1,num,arr,fee,0,num); // this is not buying day

            // return dp[i][prev][state]=max(ans1 , profit + max(a1,a2));
            return dp[i][prev][state]=max(ans1 , profit + a2);
        }
        else {
            return dp[i][prev][state]=ans1;
        }

    }

    return 0; //ese he 
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
    // final_seive();

    ill t,ic;
	// cin>>t;
    t=1;


    f1(ic,1,t) {
        ill num;
        cin>>num;

        ill arr[num];

        f0(i,0,num){
            cin>>arr[i];
        }

        ill fee;
        cin>>fee;


        f0(i,0,num+3){
            f0(j,0,num+3){
                f0(k,0,2){
                    dp[i][j][k]=-1;
                }
            }
        }

        // pattern is BS BS BS BS BS ...
        // after buying you have to sell before buying again
        // choices --> a index i --> has 3 choices 
        // 1. can be a buying day
        // 2. can be a selling day
        // 3. can be a empty(no buy/no sell) day 
        
        ill i=0;

        ill state=0; // 0 means No transition till now 
        // 1 --> this is a buying 

        // 0 also means we are looking for buying state 
        // 1 also means we are looking for selling state 

        // ill prev=-1; // if you are solving a selling state then you will need a previous buying state 
        ill prev=num; // default --> because dp me -1 problem 

        // so we have to pass this also

        ill ans=solve(i,num,arr,fee,state,prev); // returns the max profit that can be earned from 0-->i where current state is 0(no buy or sell) 
        // 0 --> num-1    and we are looking for buying state 

        // also note buy and sell can take place at the same day but -fee from profit because has to pay also
        // better is not to buy and sell on the same day

        cout<<ans<<endl;

    }  
    return 0;
}