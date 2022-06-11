#include <bits/stdc++.h>
using namespace std;


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


int minPathSum(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();

    vector<int> dp1(m);

    vector<int> dp2(m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0)
            {
                if (j == 0)
                {
                    dp1[j] = arr[i][j];
                }
                else
                {
                    dp1[j] = arr[i][j] + dp1[j - 1];
                }
            }
            else
            {
                if (j == 0)
                {
                    dp2[j] = arr[i][j] + dp1[j];
                }
                else
                {
                    dp2[j] = arr[i][j] + min(dp2[j - 1], dp1[j]);
                }
            }
        }

        
        // cout<<i<<"  -->  ";
        // for(auto x: dp1){
        //     cout<<x<<"  ";
        // }
        // cout<<endl;

        if (i!=0) {
            // dp1 = dp2; this is not the way // this cahnges pointers only 
            for(int k=0;k<m;k++) {
                dp1[k]=dp2[k];
            }
            dp2.clear();   // can be done or cannot because we will anyhow override the value  
        }

        // cout<<i<<"  -->  ";
        // for(auto x: dp1){
        //     cout<<x<<"  ";
        // }
        // cout<<endl;

        
    }

    return dp1[m - 1];
}

int main()
{   
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

        int n,m;
        cin>>n>>m;

        vector <vector <int>> arr(n,vector <int> (m,-1));

        f0(i,0,n){
            f0(j,0,m){
                cin>>arr[i][j];
            }
        }

        int ans=minPathSum(arr);

        cout<<ans<<endl;
    }  
    return 0;
}