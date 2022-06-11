#include <bits/stdc++.h>
using namespace std;

int ok (double  mid,double  x){
    if (mid<=x/mid) return 1;
    else return 0;
}

int main() {
    int x;
    cin>>x;
    double ans;
    
    if (x==0) {
        ans=0;
        return 0;
    }
    
    double lo=0; // min answer
    double hi=x; // max answer
    double mid;
    // double epsilon=1e-6;
    
    for (int j=1;j<=80;j++){
    // fixed number of times loop run 
    // much better 
    // the previous method runs into infinite loop at some values 
    
    // while (hi-lo > epsilon){
        mid=lo+(hi-lo)/2;
        if (ok(mid,x)){
            lo=mid;
        }
        else {
            hi=mid;
        }
    }

    ans=lo;

	cout<<ans<<endl;   
	    
	return 0;
}
