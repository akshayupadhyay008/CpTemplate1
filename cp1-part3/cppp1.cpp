
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


// dearrangements 
// 1 -> 0 
// 2 -> 1 
// 3 -> 2 
// 4 -> 9 
// 5 -> 44 

ill solve(deque <ill> arr,ill m,ill sum){
    if (sum%m==0) {
        return 0;
    }
    
    if (arr.size()==0) {
        return intmax;
    }
    if (arr.size()==1) {
        if (arr.front()%m==0 ) {
            return 0;
        }
        else {
            return intmax;
        }
    }

    ill sz=arr.size();
    ill x=log2(sz);

    ill mn=intmax;

    f1(i,0,x) {
        ill num=(1<<i);
        deque <ill> copy1;
        copy1=arr;

        deque <ill> copy2;
        copy2=arr;   

        ill sum1=sum;
        ill sum2=sum;     

        f0(j,0,num){
            sum1=sum1-copy1.back();
            copy1.pop_back();
        }
        ill ans1=solve(copy1,m,sum1);

        f0(j,0,num){
            sum2=sum2-copy2.front();
            copy2.pop_front();
        }
        ill ans2=solve(copy2,m,sum2);

        // if (ans1==intmax && ans2==intmax)  {
        //     mn=mn;
        // }
        // else {
        //     mn=min(mn,min(ans1,ans2+1));
        // }

        if (ans1==intmax && ans2==intmax) {
            mn=mn;
        }
        else if (ans1==intmax) {
            mn=ans2+1;
        }
        else if (ans2==intmax) {
            mn=ans1+1;
        }
        else {
            mn=min(ans1,ans2)+1;
        }

    }

    return mn;

}


int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif  

	ill t,ic;
	cin>>t;
// 	for(ic=1;ic<=t;ic++){
    f1(ic,1,t) {

        ill num,m;
        cin>>num>>m;

        deque <ill> arr;

        ill sum=0;

        f0(i,0,num){
            ill x;

            cin>>x;

            sum=sum+x;
            arr.push_back(x);
        }


        ill ans=solve(arr,m,sum);

        if (ans==intmax) {
            cout<<-1<<endl;
        }
        else {
            cout<<ans<<endl;
        }

        

	}

	return 0;
}