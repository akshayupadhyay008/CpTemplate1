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
        ill num;
        cin>>num;

        string str;
        cin>>str;

        if (num==1) {
            cout<<"Bob"<<endl;
        }
        else if (num==2) {
            if (str=="11"){
                cout<<"Bob"<<endl;
            }
            else if (str=="00"){
                cout<<"Bob"<<endl;
            }
            else {
                cout<<"Alice"<<endl;
            }
        }
        else if (num==3) {
            if (str=="111"){
                cout<<"Bob"<<endl;
            }
            else if (str=="000"){
                cout<<"Bob"<<endl;
            }
            else {
                cout<<"Alice"<<endl;
            }
        }
        else {
            map <char,ill> m;

            f0(i,0,num){
                m[str[i]]++;
            }

            if (m.size()==1){
                cout<<"Bob"<<endl;
                continue;
            }
            else {
                ill t11=max(m['0'],m['1'])-min(m['0'],m['1']);
                if (t11%2==0) {
                    cout<<"Bob"<<endl;
                }
                else {
                    cout<<"Alice"<<endl;
                }
            }
            //     if (num%2==0) {
            //         ill index=-1;

            //         f0(i,1,num){
            //             if (str[i]!=str[i-1]) {
            //                 index=i;
            //                 break;
            //             }
            //         }
            //         ill check=1;

            //         f0(i,index,num-1){
            //             if (str[i]==str[i+1]){

            //             }
            //             else {
            //                 check=0;
            //                 break;
            //             }
            //         }

            //         if (check) {
            //             // cout<<"Alice"<<endl;
            //             if (num==4) {
            //                 if (max(m['0'],m['1']) == 3) {
            //                     cout<<"Alice"<<endl;
            //                 }
            //                 else {
            //                     cout<<"Bob"<<endl;
            //                 }
            //             }
            //             else {
            //                 if (min(m['0'],m['1']) >= 3) {
            //                     cout<<"Alice"<<endl;
            //                 }
            //                 else {
            //                     cout<<"Bob"<<endl;
            //                 }
            //             }
            //         }
            //         else {
            //             cout<<"Bob"<<endl;
            //         }
            //     }   
            //     else {
            //         ill index=-1;

            //         f0(i,1,num){
            //             if (str[i]!=str[i-1]) {
            //                 index=i;
            //                 break;
            //             }
            //         }
            //         ill check=1;

            //         f0(i,index,num-1){
            //             if (str[i]==str[i+1]){

            //             }
            //             else {
            //                 check=0;
            //                 break;
            //             }
            //         }

            //         if (check) {
            //             // cout<<"Bob"<<endl;
            //             if (num==5) {
            //                 if (max(m['0'],m['1']) >= 3) {
            //                     cout<<"Bob"<<endl;
            //                 }
            //                 else {
            //                     cout<<"Alice"<<endl;
            //                 }
            //             }
            //             else {
            //                 if (min(m['0'],m['1']) >= 3) {
            //                     cout<<"Bob"<<endl;
            //                 }
            //                 else {
            //                     cout<<"Alice"<<endl;
            //                 }
            //             }
            //         }
            //         else {
            //             cout<<"Alice"<<endl;
            //         }
            //     }
            // }

        }

        // ill c=0;
        
        // ill m1=0;
        // ill m2=0;

        // f0(i,0,num-1){
        //     if (str[i]!=str[i+1]){
        //         c++;
        //         i++;
        //     }
        //     if (str[i]=='0') {
        //         m1++;
        //     }
        //     else {
        //         m2++;
        //     }
        // }

        // if (str[num-1]=='0'){
        //     m1++;
        // }
        // else {
        //     m2++;
        // }

        // if (c%2==1) {
        // // if ((max(m1,m2)+min(m1,m2))%2==1){
        //     cout<<"Alice"<<endl;
        // }
        // else{
        //     cout<<"Bob"<<endl;
        // }

    }  
    return 0;
}