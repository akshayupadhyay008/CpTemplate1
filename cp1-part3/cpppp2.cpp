
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


        int num;
        cin>>num;

        int arr[num];

        ill sum=0;
        f0(i,0,num){
            cin>>arr[i];
            // scanf("%lld",&arr[i]);
            sum=sum+arr[i];
        }


        // int b[num-1];
        // ill x;
        // int x;


        ill s2=0;

        f0(i,0,num-1){
            // cin>>b[i];
            int x;
            cin>>x;

            // scanf("%lld",&x);
            // s2=s2+b[i];
            s2=s2+x;
        }


        ill ans=intmax;

        f0(i,0,num){
            ill val=s2-(sum-arr[i]);
            if (val<=0) {
                continue;
            }
            if ( (val%(num-1)) == 0 )  {
                ill temp=(val/(num-1));
                ans=min(ans,temp);
                // break;
            }
        }


        cout<<ans<<endl;
        // printf("%lld",ans);


	}

	return 0;
}