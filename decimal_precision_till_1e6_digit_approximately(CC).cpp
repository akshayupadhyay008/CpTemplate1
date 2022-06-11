// https://www.codechef.com/problems/APPROX
// https://discuss.codechef.com/t/approx-editorial/1712

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
	    int k;
	    cin>>k;
	    ll x = 46870, y = 33102;
    
        if(k==0)
        {
            cout<<"3\n"; 
            continue;
        }
        
        cout << "3.";
        
        while(k--)
        {
            cout << (x/y);
            x = 10*(x%y); 
        }
        cout<<"\n";
	    }
	return 0;
}


// now you will think that x%y is much less than 33102 then where will 0 come from 
// it will automatically come from x/y will generate 0 till remainder > y 
// hence the code 