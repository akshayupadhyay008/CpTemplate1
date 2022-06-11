#include<bits/stdc++.h>
using namespace std;


int long long solve(int long long num){
    string str;

    str=to_string(num);

    int long long sz=str.size();

    sort(str.begin(),str.end());

    string res1="";

    string res2="";

    for(int long long i=0;i<sz;i++) {
        if (i%2==0) {
            res1=res1+str[i];
        }
        else {
            res2=res2+str[i];
        }
    }

    int long long n1=stoll(res1);
    int long long n2=stoll(res2);

    int long long ans=n1+n2;

    return ans;
}

int main(){

    int t;
    cin>>t;

    for(int i=0;i<t;i++) {
        int long long num;

        cin>>num;

        int long long sum=solve(num);

        cout<<sum<<endl;

    }
    
    return 0;
}