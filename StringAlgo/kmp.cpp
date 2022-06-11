#include<bits/stdc++.h>
using namespace std; 

vector<int> prefix_function(string s) {
    
    int n = (int)s.length();
    vector<int> pi(n);
    
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }

    return pi;
}


// 1 
// string matching use 

// 2 
// period = n - lps[n-1]    // n-1 is the last
// and n%period ==  0


int main(){

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    return 0;
}