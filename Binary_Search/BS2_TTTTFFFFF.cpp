#include<bits/stdc++.h>
using namespace std;

#define ill int long long

int ok(ill x,ill key) {
    if (x<=key) return 1;
    else return 0;
}

int main(){
    int j,num;
    cin>>num;
    int key;
    cin>>key;
    int arr[num];
    for(j=0;j<num;j++){
        cin>>arr[j];
    }
    
    //  TTTTTTTTT(T)FFFFFFFFFF
    // THIS TRUE () IS POINTED BY THE lo
    ill lo=0; // first valid candidate 
    ill hi=num; // invalid candidate
    ill mid;

    while(hi>lo+1){
        mid=lo+(hi-lo)/2;
        if (ok(arr[mid],key)){
            lo=mid;
        }
        else {
            hi=mid;
        } 
    }

    if (arr[lo]==key) cout<<lo;
    else cout<<-1;

    return 0;
}
