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
#define md 998244353
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
    ill val1=a.fi-a.se;
    ill val2=b.fi-b.se;
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

    ill tt;
	// cin>>tt;
    tt=1;

    f1(ic,1,tt) {
        ill num;
        cin>>num;

        string str;
        cin>>str;

        ill c0=0;
        ill c1=0;
        ill c2=0;

        f0(i,0,num){
            if (str[i]=='0'){
                c0++;
            }
            else if (str[i]=='1') {
                c1++;
            }
            else if (str[i]=='2') {
                c2++;
            }
        }

        ill req0=(num/3) - c0;
        ill req1=(num/3) - c1;
        ill req2=(num/3) - c2;

        // cout<<((-1*req1)+(-1*req2)==(req0))<<endl;

        // cout<<req0<<endl;
        // cout<<req1<<endl;
        // cout<<req2<<endl;

        if (req0==0 && req1==0 && req2==0) {
            // cout<<1<<endl;
            cout<<str<<endl;
            continue;
        }
        else if (req0==0) {
            // cout<<2<<endl;
            // 1 and 2 equal and opp
            if (req1>0) {
                // 2 more -->  2 to 1 
                string res=str;
                // starting 
                ill c=0;
                f0(i,0,num){
                    if (c==req1){
                        break;
                    }
                    if (str[i]=='2') {
                        res[i]='1';
                        c++;
                    }
                }

                                    cout<<res<<endl;
            }
            else {
                // 1 --> 2 
                string res=str;
                ill c=0;
                f3(i,num-1,0){
                    if (c==req2){
                        break;
                    }
                    if (str[i]=='1') {
                        res[i]='2';
                        c++;
                    }
                }
                    cout<<res<<endl;
            }

        }
        else if (req1==0) {
            // 0 to 2 
            // cout<<3<<endl;
            if (req2>0) {
                // last 
                string res=str;
                ill c=0;
                f3(i,num-1,0){
                    if (c==req2){
                        break;
                    }
                    if (str[i]=='0') {
                        res[i]='2';
                        c++;
                    }
                }

                                    cout<<res<<endl;
            }
            else {
                // 2 --> 0
                // start 
                string res=str;
                // starting 
                ill c=0;
                f0(i,0,num){
                    if (c==req0){
                        break;
                    }
                    if (str[i]=='2') {
                        res[i]='0';
                        c++;
                    }
                }

                                    cout<<res<<endl;
            }

        }
        else if (req2==0) {

            // cout<<4<<endl;
            // 1 --> 0
            // 0 to 1
            if (req1>0) {
                // last 
                string res=str;
                ill c=0;
                f3(i,num-1,0){
                    if (c==req1){
                        break;
                    }
                    if (str[i]=='0') {
                        res[i]='1';
                        c++;
                    }
                }

                                    cout<<res<<endl;
            }
            else {
                // 2 --> 0
                // start 
                string res=str;
                // starting 
                ill c=0;
                f0(i,0,num){
                    if (c==req0){
                        break;
                    }
                    if (str[i]=='1') {
                        res[i]='0';
                        c++;
                    }
                }

                                    cout<<res<<endl;


            }


        }
        // else if (req0>0 && req1(-req0)+(-req1)==req2) {

            // cout<<5<<endl;

            // 2 --> 0 and 1 
           else if (req0>0 && req1>0) {


                string res=str;
                // starting 
                ill c=0;
                f0(i,0,num){
                    if (c==req0){
                        break;
                    }
                    if (str[i]=='2') {
                        res[i]='0';
                        str[i]='0';
                        c++;
                    }
                }


                c=0;
                f0(i,0,num){
                    if (c==req0){
                        break;
                    }
                    if (str[i]=='2') {
                        res[i]='1';
                        str[i]='1';
                        c++;
                    }
                }


                cout<<res<<endl;


            }

                // 1 to 0 and 2 
           else  if (req0>0 && req2>0) {
                // start 1 to 0

                string res=str;
                // starting 
                ill c=0;
                f0(i,0,num){
                    if (c==req0){
                        break;
                    }
                    if (str[i]=='1') {
                        res[i]='0';
                        str[i]='0';
                        c++;
                    }
                }


                c=0;
                f3(i,num-1,0){
                    if (c==req2){
                        break;
                    }
                    if (str[i]=='1') {
                        res[i]='2';
                        str[i]='2';
                        c++;
                    }
                }


                cout<<res<<endl;

 
            }


            else   if (req1>0 && req2>0) {
                // start 1 to 0

                string res=str;
                // starting 
                ill c=0;
                f3(i,num-1,0){
                    if (c==req2){
                        break;
                    }
                    if (str[i]=='0') {
                        res[i]='2';
                        str[i]='2';
                        c++;
                    }
                }


                c=0;
                f3(i,num-1,0){
                    if (c==req1){
                        break;
                    }
                    if (str[i]=='0') {
                        res[i]='1';
                        str[i]='1';
                        c++;
                    }
                }


                cout<<res<<endl;
                // cout<<"cch"<<endl;

 
            }

else if ((-req0)+(-req1)==req2) {
            // else if () {
                // else 
            // 0 or 1 to 2
            // last 
                string res=str;
                ill c=0;
                f3(i,num-1,0){
                    if (c==req2){
                        break;
                    }
                    if (str[i]=='0' || str[i]=='1') {
                        res[i]='2';
                        c++;
                    }
                }
                        cout<<res<<endl;

            }
        // }
        else if ((-1*req0)+(-1*req2)==req1) {

        
            // 0 to 1 or 2 to 1 
            // last 0's 
            // first 2's 
// else {
                string res=str;
                ill c=0;
                f3(i,num-1,0){
                    if (c==(-req0)){
                        break;
                    }
                    if (str[i]=='0') {
                        res[i]='1';
                        c++;
                    }
                }

                c=0;

                f0(i,0,num){
                    if (c==(-req2)){
                        break;
                    }
                    if (str[i]=='2') {
                        res[i]='1';
                        c++;
                    }
                }
                        cout<<res<<endl;

}
        // }
        else if ((-1*req1)+(-1*req2)==(req0)) {
// cout<<"1"<<endl;
            // 1 2 to 0
            // 0 to 1 and 2 
            // end 
            // 1 to 0 and 2 
         
            // else {

            string res=str;
                ill c=0;
                f0(i,0,num){
                    if (c==req0){
                        break;
                    }
                    if (str[i]=='1' || str[i]=='2') {
                        res[i]='0';
                        c++;
                    }
                }
                        cout<<res<<endl;

            }
        // }

    }   
    return 0;
}