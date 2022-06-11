#include<bits/stdc++.h>
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
#define intmax 2147483647
#define intmin -2147483648
#define PI 3.141592653589
#define mod 1000000007
#define endl '\n'

int main(){

    int t;
    cin>>t;

    while(t--) {
        
        ill l,a,b;
        cin>>l>>a>>b;

        if (l*l > a*b) {
            cout<<"Chef"<<endl;
        }
        else if (l*l < a*b) {
            cout<<"Divyam"<<endl;
        }
        else {
            cout<<"Equal"<<endl;
        }
        
    }
    return 0;
}