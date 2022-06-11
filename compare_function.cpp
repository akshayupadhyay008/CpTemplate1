#include<bits/stdc++.h>
using namespace std;

// Driver function to sort the vector elements
// by second element of pairs
bool comp(const pair<ill,ill> &a, const pair<ill,ill> &b) {
    return (a.second < b.second);
    return (a.fi < a.fi);  // if not by second (second are equal ) then by first 
}

// worked --> https://www.codechef.com/viewsolution/46656236
bool compare(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.F == b.F)
        return a.S > b.S;
    return a.F < b.F;
}

// worked --> https://www.codechef.com/viewsolution/47358919 
bool sortbyproblem(const pair<int,int> &a , const pair<int,int> &b )
{
    if(a.ff==b.ff)
        return a.ss>b.ss;
    return a.ff<b.ff;
}





int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    return 0;
}