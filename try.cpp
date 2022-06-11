
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

struct node{
    string ss;
    ill counta;
    ill countb;
    ill countc;
    ill countd;
    ill counte;
    ill len;
};
 
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	ill t,ic;
	cin>>t;
// 	for(ic=1;ic<=t;ic++){
    f1(ic,1,t) {
	    ill num;
	    
	    cin>>num;
	    
	    vector <node> v(num);
	    
	    
	    f0(i,0,num){
	        struct node x;
	        cin>>x.ss;
	        
	        x.len=x.ss.size();
	        
	        ill ca=0,cb=0,cc=0,cd=0,ce=0;
	        for(auto y: x.ss) {
	            if (y=='a') {
	                ca++;
	            }
	            if (y=='b') {
	                cb++;
	            }
	            if (y=='c') {
	                cc++;
	            }
	            if (y=='d') {
	                cd++;
	            }
	            if (y=='e') {
	                ce++;
	            }
	        }
	        
	        v.pb(x);
	        
	        
	    }

        ill ans=0;
	    
	    
	    /// for a 
	    
	    ill totaldiffa=0;

        ill tempans=0;
	    
	    for(auto z: v) {
	        
	        ill v1=z.counta;
            ill v2=z.len-v1;

            if (v1>v2) {
                totaldiffa=totaldiffa+(v1-v2);
                tempans++;
            }

	        
	        
	    }

        if (totaldiffa==0) {
            // a is not possilbe 

        }
        else {

            vector <ill> tempa;

            for(auto z: v) {
	        
                ill v1=z.counta;
                ill v2=z.len-v1;

                if (v1<v2) {
                    // totaldiffa=totaldiffa+(v1-v2);
                    tempa.pb(v2-v1);
                }
                
                
            }

            sort(all(tempa));

            

            ill s=0;
            ill j=0;
            for (auto x: tempa) {
                
                if (s>totaldiffa) {
                    tempans=tempans+j-1;
                }
                s=s+x;
                j++;
                
            }


            ans=max(ans,tempans);

        }
	    
	    
	    /// for a 
	    
	    ill totaldiffb=0;

      tempans=0;
	    
	    for(auto z: v) {
	        
	        ill v1=z.countb;
            ill v2=z.len-v1;

            if (v1>v2) {
                totaldiffb=totaldiffb+(v1-v2);
                tempans++;
            }

	        
	        
	    }

        if (totaldiffb==0) {
            // a is not possilbe 

        }
        else {

            vector <ill> tempb;

            for(auto z: v) {
	        
                ill v1=z.countb;
                ill v2=z.len-v1;

                if (v1<v2) {
                    // totaldiffa=totaldiffa+(v1-v2);
                    tempb.pb(v2-v1);
                }
                
                
            }

            sort(all(tempb));

            

            ill s=0;
            ill j=0;
            for (auto x: tempb) {
                
                if (s>totaldiffb) {
                    tempans=tempans+j-1;
                }
                s=s+x;
                j++;
                
            }


            ans=max(ans,tempans);

        }
	    
	    
	    	    /// for a 
	    
	    ill totaldiffc=0;

      tempans=0;
	    
	    for(auto z: v) {
	        
	        ill v1=z.countc;
            ill v2=z.len-v1;

            if (v1>v2) {
                totaldiffc=totaldiffc+(v1-v2);
                tempans++;
            }

	        
	        
	    }

        if (totaldiffc==0) {
            // a is not possilbe 

        }
        else {

            vector <ill> tempc;

            for(auto z: v) {
	        
                ill v1=z.countc;
                ill v2=z.len-v1;

                if (v1<v2) {
                    // totaldiffa=totaldiffa+(v1-v2);
                    tempc.pb(v2-v1);
                }
                
                
            }

            sort(all(tempc));

            

            ill s=0;
            ill j=0;
            for (auto x: tempc) {
                
                if (s>totaldiffc) {
                    tempans=tempans+j-1;
                }
                s=s+x;
                j++;
                
            }


            ans=max(ans,tempans);

        }
	    
	    	    /// for a 
	    
	    ill totaldiffd=0;

     tempans=0;
	    
	    for(auto z: v) {
	        
	        ill v1=z.countd;
            ill v2=z.len-v1;

            if (v1>v2) {
                totaldiffd=totaldiffd+(v1-v2);
                tempans++;
            }

	        
	        
	    }

        if (totaldiffd==0) {
            // a is not possilbe 

        }
        else {

            vector <ill> tempd;

            for(auto z: v) {
	        
                ill v1=z.countd;
                ill v2=z.len-v1;

                if (v1<v2) {
                    // totaldiffa=totaldiffa+(v1-v2);
                    tempd.pb(v2-v1);
                }
                
                
            }

            sort(all(tempd));

            

            ill s=0;
            ill j=0;
            for (auto x: tempd) {
                
                if (s>totaldiffd) {
                    tempans=tempans+j-1;
                }
                s=s+x;
                j++;
                
            }


            ans=max(ans,tempans);

        }
	    
	    

	    /// for a 
	    
	    ill totaldiffe=0;

      tempans=0;
	    
	    for(auto z: v) {
	        
	        ill v1=z.counte;
            ill v2=z.len-v1;

            if (v1>v2) {
                totaldiffe=totaldiffe+(v1-v2);
                tempans++;
            }

	        
	        
	    }

        if (totaldiffe==0) {
            // a is not possilbe 

        }
        else {

            vector <ill> tempe;

            for(auto z: v) {
	        
                ill v1=z.counte;
                ill v2=z.len-v1;

                if (v1<v2) {
                    // totaldiffa=totaldiffa+(v1-v2);
                    tempe.pb(v2-v1);
                }
                
                
            }

            sort(all(tempe));

            

            ill s=0;
            ill j=0;
            for (auto x: tempe) {
                
                if (s>totaldiffe) {
                    tempans=tempans+j-1;
                }
                s=s+x;
                j++;
                
            }


            ans=max(ans,tempans);

        }
	    
	    cout<<ans<<endl;

	    
	    
	    
	}
	return 0;
}