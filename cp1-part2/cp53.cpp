#include<bits/stdc++.h>
using namespace std;

int main(){

    int num;
    cin>>num;

    vector <int> v(num);

    for(int i=0;i<num;i++) {
        cin>>v[i];
    }

    sort(v.begin(),v.end()); // 1 3 4 5 7 10

    int q;
    cin>>q;

    while(q--) {
        int k;
        cin>>k;


        // 1 
        if (binary_search(v.begin(),v.end(),k)) {
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }

        // 0 1 2 3  5  10 11  N 

        int i1=5;
        int i2=10;
        if (binary_search(v.begin()+i1,v.begin()+i2+1,k)) {
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }


        // 2

        // vector --> greater then k 
        // 1 3 5  10  10 10  12 
        // 0 1 2   3   4  5  
        // 8 
        
        k=8;

        auto it=upper_bound(v.begin(),v.end(),k);

        int index=it-v.begin(); // 3 
        // v.end()-v.begin(); --> 5
        // v[5];

        if (index==num) {
            cout<<-1<<endl;
        }


        cout<<(*it);

        k=13; // 

        auto it=upper_bound(v.begin(),v.end(),k);

        if (it == v.end()) {
            // greatest 
            cout<<-1<<endl;
        }
        else {
            cout<<(*it)<<endl;
        }



        // lower bound 

        // greater then or equal to 

        //   1   3    5   5  6  6  10   12  15 
        //   0   1    2   3  4       5    6   7 
        
        // k=6

        k=6;
        auto it=lower_bound(v.begin(),v.end(),k);

        index=it-v.begin();

        
        if (it!=v.end()) {
            cout<<*it<<endl;
            // greater or equal
            if (*it == k) {
                cout<<"Eqaul"<<endl;
            }
            else {
                cout<<"Greater"<<endl;
            }
        }
        else {
            cout<<-1<<endl;
        }


    }


        
    return 0;
}