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


// Driver function to sort the vector elements
// by second element of pairs
bool comp(const pair<ill,ill> &a, const pair<ill,ill> &b) {
    return (a.second < b.second);
    return (a.fi < a.fi);  // if not by second (second are equal ) then by first 
}


int solve(vector<int> &a, vector<int> &b) {
    int num=a.size();
    
    vector <pair <int,int> > arr;
    
    for(int i=0 ;i<num; i++) {
        arr.push_back({a[i]-b[i] , i});
    }
    
    sort(arr.begin(),arr.end());
    
    int sum=0;
    int res=0;
    
    for(int i=0;i<num;i++) {
        if (i==0) {
            sum=sum+b[arr[i].second];
        }
        else {
            res=res+ (2*(sum+(i*a[arr[i].second])));
        }
    }
    
    return res;
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

    ill num,q;  
    cin>>num>>q;

    set < pair <ill,ill> > range;
    range.insert({0,num});

    multiset <ill> s;
    s.insert(num+0+1);

    while(q--) {
        ill x;
        cin>>x;

        auto it=range.upper_bound({x,1LL});
        it--;

        ill start=it->first;
        ill end=it->second;

        range.insert({start,x});
        range.insert({x,end});

        if (start==0 && end==num){

        }

        if (start==0 && end!=num) {
            s.insert(x);
            s.erase(end-start);
        }
        else {
            s.erase(end-start-1);
            s.insert(x-start);
        }

        if (end==num && start!=0 ) {
            s.insert(end-start);
            s.insert(x-end);
        }
        else {
            s.erase(end-start-1);
            s.insert(x-end-1);
        }

        range.erase(it);

        auto it1=s.end();
        it1--;

        ill ans=*it1;

        cout<<ans<<endl;
    }

    return 0;
}