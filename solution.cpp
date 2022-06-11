#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--) {
        
        long long int num;
        cin>>num;

        long long int ans=num-1;

        for(long long int i=1; i*i<=num; i++) {
            if (num%i==0) {
                long long int divisor1=i;
                long long int divisor2=num/i;
                ans=min(ans,abs(divisor1-divisor2));
            }
        }

        cout<<ans<<endl;

    }

    return 0;
}