#include<bits/stdc++.h>
using namespace std;

#define ill int long long

int ok (ill arr[],ill index,ill key) {
    if (arr[index] >= key) return 1;
    else return 0;
}

int main(){

    // use when values do not repeat

    // TEMPLATE 3 ( MODIFIED )
    // we have only 2 values at the end ie lo and hi 
    // seperated and arranged like    (lo)(hi)
    // we give high the responsibily to point to the valid candidate 
    // we give low the responsibility to point to the invalid candidate
    // so we have to check only 1 value at the end ie high 

    // creating sth like 
    //      FFFFFFFFFTTTTTTTTTTT
    //      00000000011111111111
    // THE OK FUNCTION CAN CONTAIN ANYTHING
    

    ill num,i,key;
    cin>>num;
    cin>>key;  // which we want to find in the array
    ill arr[num];
    for(i=0;i<num;i++){
        cin>>arr[i];
    } 

    ill lo=-1; // invalid candidate therefore -1
    ill hi=num-1; // valid candidate therefore num-1
    ill mid; 

    while (lo+1<hi){   // to maintain a distance of 1 between lo and hi
        mid=lo+(hi-lo)/2; // to avoid overflow
        if (ok(arr,mid,key)){
            hi=mid;
        }
        else {
            lo=mid;
        }

    }

    if (arr[hi]==key) cout<<hi;
    else cout<<-1;

    return 0;
}
