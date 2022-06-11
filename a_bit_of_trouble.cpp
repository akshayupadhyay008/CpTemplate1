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
#define f2(i,a,b) for(int i=a;i>b;i--)
#define f3(i,a,b) for(int i=a;i>=b;i--)
 
#define all(a) a.begin(),a.end()
#define pii pair<ill,ill>

#define vi vector<ill>
#define mii map<ill,ill>

#define intmax 2147483647
#define intmin -2147483648

#define inf 1e18
#define neginf -1e18
#define PI 3.141592653589
#define mod 1000000007

#define md 998244353
#define endl '\n'

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

        ill num,x;
        cin>>num>>x;

        ill arr[num];
        vector <int> used(num,0);

        f0(i,0,num) {
            cin>>arr[i];
        }

        ill ans=0;

        f3(j,30,0) {
            if ((x&(1LL<<j))) { 
                f0(i,0,num) {
                    if (!used[i]) {
                        if (!(arr[i]&(1LL<<j))) {
                            used[i]=1;
                        }
                    }
                }
            }
            else {
                ill cnt=0;
                f0(i,0,num) {
                    if (!used[i]) {
                        if ((arr[i]&(1LL<<j))) {
                            cnt++;
                        }
                    }
                }
                ans=max(ans,cnt);
            }
        }

        ill c=0;
        f0(i,0,num) {
            if (!used[i]) {
                c++;
            }
        }

        ans=max(ans,c);

        if (ans==0) ans=-1;

        cout<<ans<<endl;

    }           
    return 0;
}