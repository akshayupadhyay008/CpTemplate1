#include <bits/stdc++.h>
using namespace std;
 
#define ill long long int
#define ld long double

#define fi first 
#define se second 
#define pb push_back 

#define MP make_pair

#define f0(i,a,b) for(int i=a;i<b;i++)
#define f1(i,a,b) for(int i=a;i<=b;i++)
#define f2(i,a,b) for(int i=a;i>b;i--)
#define f3(i,a,b) for(int i=a;i>=b;i--)
 
#define all(a) a.begin(),a.end()
#define pii pair<ill,ill>

#define vi vector<ill>
#define mii map<ill,ill>

#define intmax 2147483647
#define intmin -2147483648

#define inf ( (1e18) + 10)
#define neginf (-1 * (1e18 + 10))
#define PI 3.141592653589
#define mod 1000000007
#define md 998244353


struct node {
	ill index,right;
};


struct cmp {
	bool operator()(const node& x, const node& y) const { 
        // // return x.right <= y.right; 
        // if (x.right < y.right) {
        //     return 1; // --> dont use this 
        // }
        // else {
        //     return x.index<=y.index;
        // }
        
        // MP(x.right,x.index) < MP(y.right,y.index); // --> yes worked 

        // Generally kabhi aise mat kiya kar return 0 ya 1
        // sidha
        // if(condition1) return x.something < y.something

        // If(condition2) return x.somethingelse < y.somethingelse

        // return x.third < y.third



        // wrong 
        // no  --> not work 

        // if (x.right <= y.right) {
        //     return x.right<=y.right;
        // }
        // // else if (x.index <= y.index){
        // else {
        //     return x.index<=y.index;
        // }


        // no  --> not work 

        // if (x.right < y.right) {
        //     return true;
        // }
        // else if (x.index <= y.index) {
        //     return true;
        // }
        // else {
        //     return false;
        // }
    }
};


int main() {

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif   
    
    set <struct node,cmp> s;

    node n1;
    n1.index=1;
    n1.right=5;
    s.insert(n1);

    
    node n2;
    n2.index=2;
    n2.right=10;
    s.insert(n2);

    
    node n3;
    n3.index=3;
    n3.right=4;
    s.insert(n3);


    node n4;
    n4.index=4;
    n4.right=1;
    s.insert(n4);
    

    node n5;
    n5.index=5;
    n5.right=-5;
    s.insert(n5);
    
    
    node n6;
    n6.index=6;
    n6.right=-5;
    s.insert(n6);
    

    for(auto x: s) {
        cout<<x.index << "  " << x.right <<endl;
    }

    node x;
    x.index=4;
    x.right=1;
    if (s.find(x)!=s.end()) {
        cout<<"Yes"<<endl;
        s.erase(x);
    }
    else {
        cout<<"No"<<endl;
    }

    for(auto x: s) {
        cout<<x.index << "  " << x.right <<endl;
    }

    return 0;
}