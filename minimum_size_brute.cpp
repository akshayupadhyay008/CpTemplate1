#include <bits/stdc++.h>
using namespace std;

#define ill long long int 
#define ld long double

#define fi first 
#define se second 
#define pb push_back 

#define MP make_pair

#define f0(i,a,b) for(int i=a;i<b;i++)
#define f1(i,a,b) for(int i=a;i<=b;i++)
#define f3(i,a,b) for(int i=a;i>=b;i--)
 
#define all(a) a.begin(),a.end()
#define pii pair<ill,ill>

#define intmax 2147483647
#define intmin -2147483648

#define inf 1e18
#define neginf -1e18
#define PI 3.141592653589
#define mod 1000000007
#define md 998244353
#define endl '\n'


ill mxSum(ill arr[],ill num,ill k) {
    ill ans=0;
    ill sum=0;
    f1(i,0,k-1) {
        sum+=arr[i];
    }
    ans=sum;
    f1(i,k,num-1) {
        sum+=arr[i];
        sum-=arr[i-k];
        ans=max(ans,sum);
    }
    return ans;
}

int ok (ill a[],ill b[],ill k,ill num,ill m,ill p) {
    ill mxsuma=mxSum(a,num,k);
    ill mxsumb=mxSum(b,m,k);

    if (mxsuma*mxsumb >= p) return 1;
    else return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout);
    #endif   

    ill tt=1; 
	cin>>tt;
    
    f1(ic,1,tt) {

        ill num,m;
        cin>>num>>m;

        ill a[num],b[m];

        f0(i,0,num) {
            cin>>a[i];
        }
        
        f0(i,0,m) {
            cin>>b[i];
        }

        ill p;
        cin>>p;

        ill ans=inf;

        f1(i,1,min(num,m)) {
            if (ok(a,b,i,num,m,p)){
                ill sz=i;
                ans=min(sz,ans);
            }
        }

        if (ans==inf) ans=-1;
        
        cout<<ans<<endl;

    }           
    return 0;
}