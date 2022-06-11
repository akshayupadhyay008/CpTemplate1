
#include <bits/stdc++.h>
using namespace std;

#define f0(i,a,b) for(int i=a;i<b;i++)

int solve(int arr[],)

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif  

    int t;
    cin>>t;

    while(t--) {

        int num;
        cin>>num;

        int arr[num];

        int mx=1e6+10;
        f0(i,0,num){
            cin>>arr[i];
            mx=max(mx,arr[i]);
        }

        map <int,int> m;


        f0(i,0,num){
            m[arr[i]]++;
        }


        // int prev[mx+5];
        vector <pair <int ,int >> prev(mx+5);


        f0(i,0,mx+5) {
            prev[i].first=0;
            prev[i].second=-1;
        }


        vector <int> last(mx+5,-1);

        f0(i,0,num){
            last[arr[i]]=i;
        }


        // f0(i,0,num){
        //     cout<<last[arr[i]]<<  "  ";
        // }
        // cout<<endl;



        int ans=0;

        f0(i,0,num){
            
            int val=arr[i];
            
            int prcount=prev[arr[i]].first;
            int prindex=prev[arr[i]].second;


            if (prcount==-1) {

                if ( arr[i] <= m[arr[i]]) {
                    ans=ans+(arr[i]*(i+1));
                    prev[arr[i]].first++;
                    prev[arr[i]].second=i;
                }

                // if (arr[i] == m[arr[i]]) {
                //     ans=ans+max(0,arr[i]*(num-1-last[arr[i]]));
                // }

                // cout<<i<<"  "<<arr[i] << "  "<<ans<< "   "<<prev[arr[i]].first <<"   "<<prev[arr[i]].second<<endl;

            }
            else {
                
                if (m[arr[i]]-prcount >= arr[i]) {
                    ans=ans+(i-prindex)*(arr[i]);
                    prev[arr[i]].first++;
                    prev[arr[i]].second=i;
                }

                //  if (m[arr[i]]-prcount == arr[i]) {
                //      ans=ans+max(0,arr[i]*(num-1-last[arr[i]]));
                // }

                // cout<<i<<"  "<<arr[i] << "  "<<ans<< "   "<<prev[arr[i]].first <<"   "<<prev[arr[i]].second<<endl;
            }
        }


        cout<<ans<<endl;



    }







}