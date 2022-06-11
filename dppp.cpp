#include<bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int num;
    cin>>num;

    int arr[num];

    for(int i=0;i<num;i++){
        cin>>arr[i];
    }

    for(int i=0;i<num;i++){
        cout<<arr[i]<<"  ";
    }
    cout<<endl;

    return 0;
}