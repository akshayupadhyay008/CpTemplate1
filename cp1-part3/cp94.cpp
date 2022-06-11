#include<bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout);
    #endif   
    
    int a[4]={1,2,3,4};
    int n=4;
    sort(a, a + n);
  
    // Find all possible permutations
    cout << "Possible permutations are:\n";
    do {
        // display(a, n);
        for(int i=0;i<4;i++) {
            cout<<a[i] <<"  ";
        }
        cout<<endl;
        cout<<endl;

    } while (next_permutation(a, a + n));

    return 0;
}