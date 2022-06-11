#include<bits/stdc++.h>
using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
 
#define ill int long long
#define ld long double

#define fi first 
#define se second 
#define pb push_back 
// #define fo(i,k,n) for(ill i=k;i<n;i++)
// #define fr(i,n,k) for(ill i=n;i>=k;i--)
 
#define f0(i,a,b) for(int i=a;i<b;i++)
#define f1(i,a,b) for(int i=a;i<=b;i++)
#define f2(i,a,b) for(int i=a;i>b;i--)
#define f3(i,a,b) for(int i=a;i>=b;i--)
 
#define all(a) a.begin(),a.end()
#define pii pair<ill,ill>
#define intmax 2147483647
#define intmin -2147483648
#define pi 3.141592653589
#define mod 1000000007
#define mdl 998244353
#define endl '\n'

// const int N=50;
// ill arr[N]; // simple array not dp array 

ill num;
vector <ill> arr;

ill solve(ill x) {
    if (x==num) {
        return 1;
    }
    if (x>num) {
        return 0;
    }

    ill sum=0;

    f1(i,1,arr[x]) {
        sum=sum+solve(x+i);
    }

    return sum;

}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif


    cin>>num; 

    ill x;

    f0(i,0,num){
    //     cin>>arr[i];
        cin>>x;
        arr.pb(x);
    }

    ill ans=solve(0);
    cout<<ans<<endl;
    
    return 0;
}