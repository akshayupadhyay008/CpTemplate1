#include<bits/stdc++.h>
using namespace std;

#define ill int long long

int main(){

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif  


    ill t;
    cin>>t;

    while(t--) {
        ill num;
        cin>>num;

        string str;
        cin>>str;

        ill prefix0[num];
        ill prefix1[num];

        ill count0=0;
        ill count1=0;

        for(int i=0;i<num;i++) {
            if (str[i]=='0') {
                count0++;
            }
            else {
                count1++;
            }
            prefix0[i]=count0;
            prefix1[i]=count1;
        }

        ill arr[num];

        for(int i=0;i<num;i++) {
            arr[i]=prefix0[i]-(2*prefix1[i]);
        }

        map <ill,ill> mp;
        mp[0]=1;

        ill ans=0;
        for(int i=0;i<num;i++) {
            ans=ans+mp[arr[i]];
            mp[arr[i]]++;
        }

        ill a1=0;
        for(int i=0;i<num;i++) {
            for(int j=i;j<num;j++) {
                ill c0=0;
                ill c1=0;
                for(int k=i;k<=j;k++){
                    if (str[k]=='1'){
                        c1++;
                    }
                    else {
                        c0++;
                    }
                }
                if ((c1*2)==c0) {
                    a1++;
                }
            }
        }

        cout<<ans << "  " << a1 <<endl;
    }

    return 0;
}