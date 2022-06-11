#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=5;

    int a[n]={1,2,5,34,24,21};

    stack<int> s; 

    int ans[n];

    for(int i=n-1;i>=0;i--){
        while(!s.empty()&&a[i]>=s.top()){
            s.pop();
        }
        if(!s.empty()){
            ans[i]=s.top();
        }
        else {
            ans[i]=-1;
        }

        s.push(a[i]);
    }

    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}