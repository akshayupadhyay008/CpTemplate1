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

// const ill N=105;
// const ill H=305;
// ill dp[N][H][H];

// ill solve(ill i,ill h1,ill h2,ill arr[],ill num,ill k){
//     if (i==num){
//         if (h1>=k && h2>=k) {
//             return 0;
//         }
//         else {
//             return intmax;
//         }
//     }

//     if (dp[i][h1][h2]!=-1)  {
//         return dp[i][h1][h2];
//     }

//     if (h1>=k && h2>=k) {
//         return dp[i][h1][h2]=0;
//     }
//     else if (h1>=k) {
//         // 2 choices take this or not for h2 
//         ill a1=solve(i+1,h1,h2,arr,num,k); // not taking this 
//         ill a2=1+solve(i+1,h1,h2+arr[i],arr,num,k); // taking this 
//         return dp[i][h1][h2]=min(a1,a2);
//     }
//     else if (h2>=k){
//         // 2 choices take this or not for h1 
//         ill a1=solve(i+1,h1,h2,arr,num,k); // not taking this 
//         ill a2=1+solve(i+1,h1+arr[i],h2,arr,num,k); // taking this 
//         return dp[i][h1][h2]=min(a1,a2);
//     }
//     else {
//         // 3 choices --> for h1 or h2 or none 
//         ill a1=solve(i+1,h1,h2,arr,num,k); // not taking this 
//         ill a2=1+solve(i+1,h1,h2+arr[i],arr,num,k); // taking this 
//         ill a3=1+solve(i+1,h1+arr[i],h2,arr,num,k); // taking this 
//         return dp[i][h1][h2]=min(a1,min(a2,a3)); 
//     }

//     return 0; // for vscode 
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
    // final_seive();

    ill t,ic;
	cin>>t;
    // t=1;

    f1(ic,1,t) {

        ill num,k;
        cin>>num>>k;

        // ill arr[num];
        vector <ill> arr(num);

        multiset <ill> s;

        // ill x;

        f0(i,0,num){
            cin>>arr[i];
            // cin>>x;
            s.insert(arr[i]);
        }   

        ill k1=k;

        ill k2=k;

        ill ch=1; // checking for 1 

        ill ans=0;

        while(1) {
            if (s.empty()) {
                break;
            }
            if (ch==1) {
                auto it=s.lower_bound(k1);
                if (it==s.end()){
                    break;
                }
                else {
                    if (k1<=(*it)) {
                        k1=0;
                        ch=2;
                        ans++;
                        s.erase(it);
                    }
                    else {
                        k1=k1-*it;
                        ans++;
                        s.erase(it);
                    }
                }
            }
            else if (ch==2) {
                auto it=s.lower_bound(k2);
                if (it==s.end()){
                    break;
                }
                else {
                    if (k2<=(*it)) {
                        k2=0;
                        ch=3;
                        ans++;
                        s.erase(it);
                    }
                    else {
                        k2=k2-*it;
                        ans++;
                        s.erase(it);
                    }
                }
            }
            else {
                break;
            }
        }

        if (ch==3) {
            cout<<ans<<endl;
        }
        else {
            cout<<-1<<endl;
        }


        // // sort(arr,arr+num);
        // sort(all(arr));

        // vector <int> present(num,0);

        // ill k1=k;

        // f0(i,0,num){
        //     if (i%2==0) {
        //         if (arr[i]>=k1) {
        //             k1=0;
        //             present[i]=1;
        //             break;
        //         }
        //         else {
        //             present[i]=1;
        //             k1=k1-arr[i];
        //         }
        //     }
        // }

        // ill k2=k;
        // f0(i,0,num){
        //     if (present[i]==0) {
        //         if (arr[i]>=k2) {
        //             k2=0;
        //             present[i]=1;
        //             break;
        //         }
        //         else {
        //             present[i]=1;
        //             k2=k2-arr[i];
        //         }
        //     }
        // }

        // if (k2==0) {
        //     ill ans=0;
        //     f0(i,0,num){
        //         if (present[i]){
        //             ans++;
        //         }
        //     }
        //     cout<<ans<<endl;
        // }
        // else {
        //     cout<<-1<<endl;
        // }
        
        // f0(i,0,num+5){
        //     f0(j,0,300){
        //         f0(k,0,300){
        //             dp[i][j][k]=-1;
        //         }
        //     }
        // }

        // ill h1=0;
        // ill h2=0;
        // ill i=0;

        // ill ans=solve(i,h1,h2,arr,num,k);

        // if (ans==intmax){
        //     cout<<-1<<endl;
        // }

        // cout<<ans<<endl;

    }  
    return 0;
}