#include <bits/stdc++.h>
using namespace std;
 
#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
 
#define ill int long long
#define ld long double

#define fi first 
#define se second 
#define pb push_back 
// #define fo(i,k,n) for(ill i=k;i<n;i++)
// #define fr(i,n,k) for(ill i=n;i>=k;i--)
 
#define f0(i,a,b) for(int i=a;i<b;i++)
#define f1(i,a,b) for(int i=a;i<=b;i++)
#define f2(i,a,b) for(int i=a;i>b;i--)
#define f3(i,a,b) for(int i=a;i>=b;i--)
 
#define all(a) a.begin(),a.end()
#define pii pair<ill,ill>
#define intmax 2147483647
#define intmin -2147483648
#define pi 3.141592653589
#define mod 1000000007
#define mdl 998244353
#define endl '\n'


// dearrangements 
// 1 -> 0 
// 2 -> 1 
// 3 -> 2 
// 4 -> 9 
// 5 -> 44 


ill gcd(ill a, ill b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);     
}


ill solve(string str,ill i,ill num){

    // cout<<str<<"   "<<i<< endl;

    if (i<=-1) {

        cout<<str<<"   "<<i<<"   "<<(1)<<endl;

        return 1;
    }



    ill val=str[i]-'0';


    // if (i==0) {
    //     // return (val-1);
    //     // if (val==0 || val==1) {
    //     if (val==0){
    //         return 0;
    //     }

    //     if (val==1 && num==1) {
    //         return 0;
    //     }

    //     if (num==1) {
    //         return (val-1);
    //     }

    //     else {
    //         return (val+1);
    //     }


    //     // else {
    //     //     return (val-1);
    //     // }

    // }

    // no carry 
    ill ans1=(val+1) * solve(str,i-1,num);

    // carry 
    ill ans2;
    if (i-2 >=0) {
        if (str[i-2]=='0') {
            string str2=str;
            str2[i-2]='9';
            ans2=(19- (10+val) ) * solve(str2,i-2,num);
        }
        else {
            string str2=str;
            str2[i-2]=char(str2[i-2]-1);
            ans2=(19- (10+val) ) * solve(str2,i-2,num);
        }       
    }
    else {
        ans2=0;
    }

    cout<<str<<"   "<<i<<"   " << val<<"  " <<ans1<<"   "<<ans2<<"  " << (ans1+ans2)<<endl;
    return (ans1+ans2);


}


int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif  

	ill t,ic;
	cin>>t;
// 	for(ic=1;ic<=t;ic++){
    f1(ic,1,t) {


        string str;
        cin>>str;

        ill num=str.size();

        ill ans=solve(str,num-1,num);
        
        ans=ans-2;

        cout<<ans<<endl;
               
        
    }
	return 0;
}