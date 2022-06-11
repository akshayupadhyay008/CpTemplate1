#include<bits/stdc++.h>
using namespace std;

void print(vector <int> v) {
    v[0]=2;

    cout<<v[0] <<endl;
}

int main(){

    vector <int> v{1,2,3,4,5};

    print(v);

    cout<<v[0] <<endl;
    
    return 0;
}