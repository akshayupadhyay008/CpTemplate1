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
        ill num;
        cin>>num;

        ill a[num];

        ill b[num];

        f0(i,0,num){
            cin>>a[i];
        }

        f0(i,0,num){
            cin>>b[i];
        }



        // vector <ill> v;
        map <ill,ill> m;

        ill ans=0;

        ill res=0;

        f3(j,31,0){
            
            ill check=1;

            f0(i,0,num){
                if (  (a[i] & (1<<j)) || (b[i] & (1<<j)) )  {
                    check=1;
                }
                else {
                    check=0;
                    break;
                }
            }


            if (check==0) {
                continue;
            }

            else if (check==1) {
                
                // cout<<j<<" -- > "<<endl;

                ill flag=1;


                f0(i,0,num){
                    // if (  (a[i] & (1<<j))  ) {
                    //     flag=1;
                    // }
                    // else if ( (b[i] & (1<<j)) ) {
                    //     if ((m.find(i))==m.end()) {
                    //     // if (m[i]==0){
                    //         flag=1;
                    //     }
                    //     else {
                    //         flag=0;
                    //         break;
                    //     }
                    // }
                    if (m.find(i)==m.end()) {
                        continue;
                    }
                    else {
                        if ((b[i] & (1<<j))) {
                            flag=1;
                        }
                        else {
                            flag=0;
                            break;
                        }
                    }
                }

                // cout<<j<<"   "<<flag<<endl;

                if (flag==0) {
                    continue;
                }
                else if (flag==1){
                    
                    // res=res+(1<<j);
                    res=res+pow(2,j);

                    f0(i,0,num){
                        // if (  (a[i] & (1<<j))  ) {
                        //     continue;
                        // }
                        // else if ( (b[i] & (1<<j)) ) {
                        //     m[i]++;
                        // }
                        if (m.find(i)==m.end()) {
                            // continue;
                            if (  (a[i] & (1<<j))  ) {
                                continue;
                            }
                            else if ( (b[i] & (1<<j)) ) {
                                m[i]++;
                            }
                        }
                        else {
                            // if ((b[i] & (1<<j))) {
                            //     flag=1;
                            // }
                            // else {
                            //     flag=0;
                            //     break;
                            // }
                            continue;
                        }
                    }
                }

                // for(auto x: m) {
                //     cout<<x.fi<<"  "<<x.se<<endl;
                // }
                // cout<<endl;


            }



        }


        cout<<res<<" "<<m.size()<<endl;


	}

	return 0;
}