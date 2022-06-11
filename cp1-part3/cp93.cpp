#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--) {
        
        int num,q;
        cin>>num>>q;

        int arr[num];

        for(int i=0;i<num;i++) {
            cin>>arr[i];
        }


        while(q--) {
            int l,r;
            cin>>l>>r;

            int odd=0;
            int even=0;

            for(int i=l-1;i<=r-1;i++) {
                if (arr[i]%2 == 0) even++;
                else odd++;
            }

            cout<<odd<<" "<<even<<endl;
        }
    }

    return 0;
}