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


vector <int> add_two_big_number(string str1 ,string str2) {
        if (str2.size()>str1.size()) {
            swap(str2,str1);
        }

        vector <int> v1;
        vector <int> v2;

        f0(i,0,str1.size()){
            v1.pb(str1[i]-'0');
        }

        f0(i,0,str2.size()){
            v2.pb(str2[i]-'0');
        }

        reverse(all(v1));
        reverse(all(v2));

        ill sz=v2.size();

        // vector <int> ans(v2.size()+1);
        vector <int> ans;

        int carry=0;
        f0(i,0,sz){
            int val=v1[i]+v2[i]+carry;
            if (val<=9) {
                // ans[i]=val;
                ans.pb(val);
                carry=0;
            }
            else {
                int rm=val%10;
                ans.pb(rm);
                carry=val/10;
            }

        }

        f0(i,sz,v1.size()){
            int val=v1[i]+carry;
            if (val<=9) {
                // ans[i]=val;
                ans.pb(val);
                carry=0;
            }
            else {
                int rm=val%10;
                ans.pb(rm);
                carry=val/10;
            }
        }

        if (carry>0) {
            ans.pb(carry);
        }

        reverse(all(ans));

        return ans;
}



vector <int> divide_by_2(vector <int>& v) {

    vector <int> res;

    int num=v.size();

    int rm=0;


    // consider these cases 132 / 2 
    // or 2014 / 2 or 
    // 2134 / 2   --> 2(1)34  we have to leave a 0 in is place and move 
    // but this will like automatically happen 
    // check 


    f0(i,0,num){
        if (rm>0) {
            int temp=10*rm + v[i];
            int div=temp/2;
            rm=temp%2;
            res.pb(div);
        }
        else if (rm==0) {
            if (v[i]<2) {
                res.pb(0);
                // rm=v[i]%2; 
                rm=rm+v[i]; // sir did like rm=rm+v[i]  so that it can be used ingeneral and not just for 2 
                // i think for this to work in general then it should be 
                // 1 append 0 here 
                // 2 rm=10*rm+v[i];
                // yes 
                // rm=10*rm+v[i]; // correct 

            }
            else {
                rm=v[i]%2;
                res.pb(v[i]/2);
            }
        }
    }


    // 132 -> 066 
    // prepending 0's remove 

    vector <int > result;
    int index=-1;

    f0(i,0,res.size()){
        if (res[i]!=0) {
            index=i;
            break;
        }
    }

    f0(i,index,res.size()){
        result.pb(res[i]);
    }

    return result;


/*

    f0(i,0,num){
        int val=10*rm+v[i];
        int div=val/2;
        rm=val%2;
        res.pb(div);
    }

    // removing the first comming zeros 

    reverse(all(res));

    // f0(i,res.size()-1,0) {
    //     if (res[i]==0) {
    //         res.pop_back();
    //     }
    // }

    vector <int>  res2;

    int index=-1;
    f3(i,res.size()-1,0) {
        if (res[i]!=0) {
            // res.pop_back();
            index=i;
            break;
        }
    }

    f3(i,index,0){
        res2.pb(res[i]);
    }

    // reverse(all(res));

    // return res;
    return res2;

*/



}



vector <int> subtract(vector <int > & v1 , vector <int > & v2) {
    
    int n1=v1.size();
    int n2=v2.size();

    reverse(all(v1));
    reverse(all(v2));

    vector <int > ans;

/*
my -


    // int carry=0;

    f0(i,0,n2){

        if (v1[i]==-1) {
            ans.pb(9-v2[i]);
            v1[i+1]--;
        }
        else {

            if (v1[i]>=v2[i]){
                ans.pb(v1[i]-v2[i]);
            }
            else {
                int val=10+v1[i];
                ans.pb(val-v2[i]);
                v1[i+1]--;
            }

        }

    }




    f0(i,n1,n2){
        ans.pb(v1[i]);
    }

    // f3(i,ans.size()-1,0) {
    //     if (ans[i]==0) {
    //         ans.pop_back();
    //     }
    // }

    vector <int>  res2;

    int index=-1;
    f3(i,ans.size()-1,0) {
        if (ans[i]!=0) {
            // res.pop_back();
            index=i;
            break;
        }
    }

    f3(i,index,0){
        res2.pb(ans[i]);
    }
    


    // reverse(all(ans));

    // return ans;
    return res2;
*/


    f0(i,0,n2) {
        if (v1[i]<v2[i]) {
            v1[i+1]--;
            // see if it becomes -1 then also that will work 
            // like there v[i+1]-- again will happen and 10-1-v2[i] will be equivalent to 9-v2[i]
            ans.pb(10+v1[i]-v2[i]);
        }
        else if (v1[i]>=v2[i]) {
            ans.pb(v1[i]-v2[i]);
        }
    }

    // if (n1>n2) {
    //     if (v1[n2]==-1) {
    //         ans.pb(9);
    //         ... this will be under while loop ... because this carry can continue till last 
    //         ... like    1000000000 - 9 = ?
    //     }
    // }

    int i=n2;
    while(1) {
        if (i==n1) {
            break;
        }

        if (v1[i]>=0) {
            ans.pb(v1[i]);
        }
        else {
            // v[i]==-1 this can happen 
            // ans.pb(9); // my 
            ans.pb(10+v1[i]);
            v1[i+1]--;
        }
        i++;

    }

    reverse(all(ans));


    // here also the leading places can have 0

    vector <int> res;
    int index=-1;
    
    f0(i,0,ans.size()){
        if (ans[i]>0) {
            index=i;
            break;
        }
    }   


    f0(i,index,ans.size()) {
        res.pb(ans[i]);
    }
    
    return res;


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
    // t=10;


// 	for(ic=1;ic<=t;ic++){
    f1(ic,1,t) {
        
        string str1,str2;
        cin>>str1>>str2;

        vector <int> v1;
        vector <int> v2;

        f0(i,0,str1.size()){
            v1.pb(str1[i]-'0');
        }

        f0(i,0,str2.size()){
            v2.pb(str2[i]-'0');
        }

        // str1 is sum = A+B
        // str2 is diff = A-B 
        // adding both equation
        // A= (sum+diff)/2 
        // B= sum - A  
        // here -> v1 - ans2 

        vector <int> ans=add_two_big_number(str1,str2);

        // for(auto x: ans) {
        //     cout<<x;
        // }
        // cout<<endl;

        vector <int> ans2=divide_by_2(ans);

        for(auto x: ans2) {
            cout<<x;
        }

        vector <int> res=subtract(v1,ans2);


        cout<<endl;
        for(auto x: res) {
            cout<<x;
        }
        cout<<endl;
        

    }
	return 0;
}