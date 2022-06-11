/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here


#include <bits/stdc++.h>
using namespace std;

#define f0(i,a,b) for(int i=a;i<b;i++)

int solve(vector <int> & arr,int num)  {
        int mx=1e6+10;

        f0(i,0,num){
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

                if (arr[i] == m[arr[i]]) {
                    ans=ans+max(0,arr[i]*(num-1-last[arr[i]]));
                }

            }
            else {
                
                if (m[arr[i]]-prcount >= arr[i]) {
                    ans=ans+(arr[i]*(i-prindex));
                    prev[arr[i]].first++;
                    prev[arr[i]].second=i;
                }

                 if (m[arr[i]]-prcount == arr[i]) {
                     ans=ans+max(0,arr[i]*(num-1-last[arr[i]]));
                }
            }
        }


        // cout<<ans<<endl;

        return ans;



}

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

        vector <int> arr(num);

        // int mx=1e6+10;
        f0(i,0,num){
            cin>>arr[i];
            // mx=max(mx,arr[i]);
        }

        int res=0;

        res=solve(arr,num);

        vector <int> dup(num);


        f0(i,0,num){
            dup[i]=arr[i];
        }

        reverse(dup.begin(),dup.end());

        res=res+solve(dup,num);


        cout<<res<<endl;

    }

}