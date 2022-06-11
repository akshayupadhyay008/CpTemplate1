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

int solve(string s1,string s2,vector <string> str,ill num,ill n){
    
    string res=s1+s2;

    vector <string> v;

    string temp;

    f0(i,0,num-1){
        temp.pb(res[i]);
        v.pb(temp);
    }

    temp.clear();
    f3(i,num-1,1){
        temp.pb(res[i]);
        string s2=temp;
        reverse(all(s2));
        v.pb(s2);
    }

    sort(all(str));
    sort(all(v));

    int ch1=1;
    f0(i,0,n){
        if (v[i]==str[i]){

        }
        else {
            ch1=0;
            break;
        }
    }

    if (ch1==1) {
        vector <char> ans(n,'?');

        string temp;
        f0(i,0,num-1){
            temp.pb(res[i]);
            // v.pb(temp);
            f0(j,0,n){
                if (str[j]==temp){
                    if (ans[j]=='?') {
                        ans[j]='P';
                        break;
                    }
                }
            }
        }

        temp.clear();
        f3(i,num-1,1){
            temp.pb(res[i]);
            // v.pb(temp);
            f0(j,0,n){
                if (str[j]==temp){
                    if (ans[j]=='?') {
                        ans[j]='S';
                        break;
                    }
                }
            }
        }

        f0(i,0,n){
            cout<<ans[i];
        }
        cout<<endl;
        // continue;

        return 1;
    }

    string res2=s2+s1;

    vector <string> v2;

    string temp2;
    f0(i,0,num-1){
        temp2.pb(res2[i]);
        v2.pb(temp2);
    }

    temp2.clear();
    f3(i,num-1,1){
        temp2.pb(res2[i]);
        v2.pb(temp2);
    }

    sort(all(str));
    sort(all(v2));

    int ch2=1;
    f0(i,0,n){
        if (v2[i]==str[i]){

        }
        else {
            ch2=0;
            break;
        }
    }

    if (ch2==1) {
        
        res=s2+s1;

        vector <char> ans(n,'?');

        string temp;
        f0(i,0,num-1){
            temp.pb(res[i]);
            // v.pb(temp);
            f0(j,0,n){
                if (str[j]==temp){
                    if (ans[j]=='?') {
                        ans[j]='P';
                        break;
                    }
                }
            }
        }

        temp.clear();
        f3(i,num-1,1){
            temp.pb(res[i]);
            // v.pb(temp);
            f0(j,0,n){
                if (str[j]==temp){
                    if (ans[j]=='?') {
                        ans[j]='S';
                        break;
                    }
                }
            }
        }

        f0(i,0,n){
            cout<<ans[i];
        }
        cout<<endl;
        // continue;

        return 1;
    }
    
    return 0;
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

    ill tt;
	// cin>>tt;
    tt=1;

    f1(ic,1,tt) {

        ill num;
        cin>>num;

        vector <int> present(num,0);


        ill n=2*num-2;

        // string str[n];
        vector <string> str(n);

        map <ill,string> mp;

        f0(i,0,n){
            cin>>str[i];
            ill len=str[i].size();
            if (present[len]==0) {
                mp[len]=str[i];
                present[len]=1;
            }
            else {
                mp[(-1*len)]=str[i];
            }
        }

        if (num%2==0) {
            string s1=mp[(num/2)];
            string s2=mp[(-1*(num/2))];

            string res=s1+s2;

            vector <string> v;

            string temp;
            f0(i,0,num-1){
                temp.pb(res[i]);
                v.pb(temp);
            }

            temp.clear();
            f3(i,num-1,1){
                temp.pb(res[i]);
                v.pb(temp);
            }

            sort(all(str));
            sort(all(v));

            int ch1=1;
            f0(i,0,n){
                if (v[i]==str[i]){

                }
                else {
                    ch1=0;
                    break;
                }
            }

            if (ch1==1) {
                vector <char> ans(n,'?');

                string temp;
                f0(i,0,num-1){
                    temp.pb(res[i]);
                    // v.pb(temp);
                    f0(j,0,n){
                        if (str[j]==temp){
                            if (ans[j]=='?') {
                                ans[j]='P';
                                break;
                            }
                        }
                    }
                }

                temp.clear();
                f3(i,num-1,1){
                    temp.pb(res[i]);
                    // v.pb(temp);
                    f0(j,0,n){
                        if (str[j]==temp){
                            if (ans[j]=='?') {
                                ans[j]='S';
                                break;
                            }
                        }
                    }
                }

                f0(i,0,n){
                    cout<<ans[i];
                }
                cout<<endl;
                continue;
            }

            string res2=s2+s1;

            vector <string> v2;

            string temp2;
            f0(i,0,num-1){
                temp2.pb(res2[i]);
                v2.pb(temp2);
            }

            temp2.clear();
            f3(i,num-1,1){
                temp2.pb(res2[i]);
                v2.pb(temp2);
            }

            sort(all(str));
            sort(all(v2));

            int ch2=1;
            f0(i,0,n){
                if (v2[i]==str[i]){

                }
                else {
                    ch2=0;
                    break;
                }
            }

            if (ch2==1) {
                
                res=s2+s1;

                vector <char> ans(n,'?');

                string temp;
                f0(i,0,num-1){
                    temp.pb(res[i]);
                    // v.pb(temp);
                    f0(j,0,n){
                        if (str[j]==temp){
                            if (ans[j]=='?') {
                                ans[j]='P';
                                break;
                            }
                        }
                    }
                }

                temp.clear();
                f3(i,num-1,1){
                    temp.pb(res[i]);
                    // v.pb(temp);
                    f0(j,0,n){
                        if (str[j]==temp){
                            if (ans[j]=='?') {
                                ans[j]='S';
                                break;
                            }
                        }
                    }
                }

                f0(i,0,n){
                    cout<<ans[i];
                }
                cout<<endl;
                continue;
            }

        }
        else {
            ill len1=(num/2);
            ill len2=(num/2)+1;

            string s1=mp[len1];
            string s2=mp[(-len2)];

            cout<<s1<<"  " << s2<<endl;

            int ch=solve(s1,s2,str,num,n);
            if (ch==1){

            }
            else {
                ch=solve(s2,s1,str,num,n);

                cout<<s2<<"  " << s1<<endl;

                if (ch==1){

                }
                else {
                    
                    s1=mp[(-len1)];

                    s2=mp[len2];

                    cout<<s1<<"  " << s2<<endl;

                    ch=solve(s1,s2,str,num,n);
                    if (ch==1){

                    }
                    else {
                        cout<<s2<<"  " << s1<<endl;

                        ch=solve(s2,s1,str,num,n);
                    }
                }
            }

        }
    }   
    return 0;
}