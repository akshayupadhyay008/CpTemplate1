#include <bits/stdc++.h>
using namespace std;

/*
// Ordered-Set (PBDS)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define os_find(k) os.find_by_order(k)
#define os_order(k) os.order_of_key(k)
*/


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
#define PI 3.141592653589
#define mod 1000000007
// 998244353
#define md 998244353
// #define endl '\n'

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
    ill val1=a.se-a.fi;
    ill val2=b.se-b.fi;
    // return (a.second < b.second);
    if (val1>val2) {
        return true;
    }
    else {
        return false;
    }
    
    // if (a.fi==b.fi) {
    //     return (a.se>b.se);
    // }
    
    // return a.fi<b.fi;
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

// ill fact[1000005];
// ill ncr(ill n,ill r) {
//     return (n>=r?(fact[n]*modInv(fact[r],mod))%mod*modInv(fact[n-r],mod)%mod:0);
// }

// void initialise_fact(){
//     fact[0]=1;
//     fact[1]=1;
//     f0(i,2,1000005) {
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

// for this ques 
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
//         size1[b] += size1[a]; // for this ques 
//     }
// }


// vector<int> prefix_function(string &s) {
    
//     int n = (int)s.length();
//     vector<int> pi(n,0);
    
//     for (int i = 1; i < n; i++) {
//         int j = pi[i-1];
//         while (j > 0 && s[i] != s[j])
//             j = pi[j-1];
//         if (s[i] == s[j])
//             j++;
//         pi[i] = j;
//     }

//     return pi;
// }

int ok (ill sum,ill arr[],ill mean,ill median,vector <ill> & v,vector <ill> & prefix,ill num,ill sz) {
    // if (arr[index] >= key) return 1;
    // else return 0;
    // if (mean<median) {
    //     return 0;
    // }
    // if (mean==median) {
    //     return 1;
    // }

    ill x=mean-median;

    // ill y=(num*x) - sum + (median*num) - x;

    // if (y<0) {
    //     return 0;
    // }

    ill v1=mean;

    // less then or equal to --> upper bound 
    auto it=upper_bound(all(v),v1);

    if (it==v.begin()) {
        return 1;
    }

    it--;
    auto index=it-v.begin();

    ill v2=(index+1)*(v1) - (prefix[index]);
    
    ill y=((num-1)*x) - sum;
    
    if (v2<=y) {
        return 1;
    }
    
    y=y+(median*num);
    
    // if (y<0) {
    //     return 0;
    // }


    if (v2<=y) {
        return 1;
    }
    else {
        return 0;
    }

}


ill ok2 (ill sum,ill arr[],ill mean,ill median,vector <ill> & v,vector <ill> & prefix,ill num,ill sz) {
    // if (arr[index] >= key) return 1;
    // else return 0;
    // if (mean<median) {
    //     return 0;
    // }
    if (mean==median) {
        return 0;
    }

    ill x=mean-median;

    ill y=(num*x) - sum + (median*num) - x;

    return x+y;
}


int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);  // --> for taking input output from .txt

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif  

    // initialise_fact();
    // final_seive();
        
    ill tt;
	cin>>tt;
    // tt=1;

    f1(ic,1,tt) {

        ill num;
        cin>>num;

        ill arr[num];

        ill sum=0;

        f0(i,0,num){
            cin>>arr[i];
            sum=sum+arr[i];
        }

        sort(arr,arr+num);

        ill median,mean;

        vector <ill> v;

        if (num%2==0) {
            median=arr[(num/2-1)];
            ill index=(num/2-1);
            f0(i,index+1,num){
                v.pb(arr[i]);
            }
        }
        else {
            median=arr[(num/2)];
            ill index=(num/2);
            f0(i,index+1,num){
                v.pb(arr[i]);
            }
        }

        ill ans;

        // mean=sum/num;
        

        // if (median>=mean){
        //     ans=sum-median*num;
        //     cout<<ans<<endl;
        //     cout<<" -- "<<endl;
        //     continue;
        // }

        ill sz=v.size();

        vector <ill> prefix(sz);

        ill s=0;

        f0(i,0,sz){
            s=s+v[i];
            prefix[i]=s;
        }

        // f0(i,0,num){
        //     cout<<arr[i]<<" ";
        // }
        // cout<<endl;

        // for(auto x:v){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        
        
        // for(auto x:prefix){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        
        // cout<<mean<< "  "<<median<<endl;

        // BS on mean 
        ill lo=median-1; // invalid candidate therefore -1
        ill hi=arr[num-1]+100; // valid candidate therefore num-1
        ill mid; 

        while (lo+1<hi){   // to maintain a distance of 1 between lo and hi
            
            mid=lo+(hi-lo)/2; // to avoid overflow
            // cout<<lo<< "  "<<hi << "  "<<mid<<endl;
            if (ok(sum,arr,mid,median,v,prefix,num,sz)){
                hi=mid;
            }
            else {
                lo=mid;
            }

        }

        // cout<<hi<<endl;

        // if (arr[hi]==key) cout<<hi;
        // else cout<<-1;

        ill res=ok2(sum,arr,hi,median,v,prefix,num,sz);
        
        cout<<res<<endl;

        // cout<<endl;
    }       
    return 0;
};