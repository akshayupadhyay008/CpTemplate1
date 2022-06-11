#include <bits/stdc++.h>
using namespace std;

/*
// Ordered-Set (PBDS)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define os_find(k) os.find_by_order(k)
#define os_order(k) os.order_of_key(k)
*/

// #pragma GCC target ("avx2")
// #pragma GCC optimize ("O3")
// #pragma GCC optimize ("unroll-loops")
 
#define ill long long int
#define ld long double

#define fi first 
#define se second 
#define pb push_back 

#define MP make_pair

#define f0(i,a,b) for(ill i=a;i<b;i++)
#define f1(i,a,b) for(ill i=a;i<=b;i++)
#define f2(i,a,b) for(ill i=a;i>b;i--)
#define f3(i,a,b) for(ill i=a;i>=b;i--)
 
#define all(a) a.begin(),a.end()
#define pii pair<ill,ill>

#define vi vector<ill>
#define mii map<ill,ill>

#define illmax 2147483647
#define illmin -2147483648

#define inf ( (1e18) + 10)
#define neginf (-1 * (1e18 + 10))
#define PI 3.141592653589
#define mod 1000000007
// 998244353
#define md 998244353
#define endl '\n'

// google -->     cout<<"Case #"<<ic<<": "<<ans<<endl; 
// cout<<fixed<<setprecision(12)<<ans<<endl;

bool comp(const pair<ill,ill> &a, const pair<ill,ill> &b) {
    // ill val1=a.se-a.fi;
    // ill val2=b.se-b.fi;
    // // return (a.second < b.second);
    // if (val1>val2) {
    //     return true;
    // }
    // else {
    //     return false;
    // }
    
    if (a.fi==b.fi) {
        return (a.se>b.se);
    }
    
    return a.fi<b.fi;
}

ill gcd(ill a, ill b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);     
}

ill binpow(ill a, ill b,ill m) {
    if (b == 0)
        return 1;

    ill res = binpow(a, b / 2,m);
    if (b % 2)
        return (res%m * res%m * a%m)%m;
    else
        return (res%m * res%m)%m;
}

ill be_rec(ill x,ill n) {
	if(n==0){
		return 1;
	}
	if(n%2==0){
		return be_rec((x*x),n/2);
	}
	return x*be_rec(x*x,(n-1)/2);
}

ill lcm(ill a,ill b) {
    return ((a/gcd(a,b))*b); // to avoid overflow 
}

ill modInv(ill i, ill m) {return binpow(i,m-2,m);}

// ill fact[2000005];
// ill ncr(ill n,ill r) {
//     return (n>=r?(fact[n]*modInv(fact[r],mod))%mod*modInv(fact[n-r],mod)%mod:0);
//     // return (n>=r?(fact[n]*modInv(fact[r],md))%md*modInv(fact[n-r],md)%md:0);
// }

// void initialise_fact(){
//     fact[0]=1;
//     fact[1]=1;
//     f0(i,2,2000005) {
//         fact[i]=((fact[i-1]%mod)*(i%mod))%mod;
//         // fact[i]=((fact[i-1]%md)*(i%md))%md;
//     }
// }


// DSU ...

// const ill N=100005;
// const ill N=205;
// ill parent[N];
// ill size1[N];

// void make_set(ill v) {
//     parent[v] = v;
//     size1[v] = 1;
// }

// ill find_set(ill v) {
//     if (v == parent[v]) {
//         return v;
//     }
//     return parent[v] = find_set(parent[v]);
// }

// void union_set(ill a,ill b) {
//     a = find_set(a);
//     b = find_set(b);
//     if (a != b) {
//         if (size1[a] < size1[b]) {
//             swap(a, b);
//         }
//         parent[b] = a;
//         size1[a] += size1[b]; // updating the size of b is of no use because we will not use it anyway now 
//         // as when we will be asked to do sth with b we will operate on its parent b 

//     }
// }

// vector<ill> prefix_function(string &s) {
    
//     ill n = (ill)s.length();
//     vector<ill> pi(n,0);
    
//     for (ill i = 1; i < n; i++) {
//         ill j = pi[i-1];
//         while (j > 0 && s[i] != s[j])
//             j = pi[j-1];
//         if (s[i] == s[j])
//             j++;
//         pi[i] = j;
//     }

//     return pi;
// }


// vector <ill> lis(vector <ill> &v){
//     // lis in nlogn
//     ill n=v.size();
//     vector <ill> temp;

//     f0(i,0,n) {
      
//         auto it = upper_bound(all(temp), v[i]); // for non decreasing (increasing and equal will work)
//         // auto it = lower_bound(all(temp), v[i]); // for strictly increasing 
            
//         if (it == temp.end()) {
//             temp.pb(v[i]);
//         }
//         else {
//             *it = v[i];
//         }
//     }
//    return temp;
// }


struct segtree {
    ill size;

    // at each node we have --> 1. inversion count in this node(range)
    //                      --> 2. freq array of this range 

    vector <ill> tree;

    void init(ill n) {
        size=1;

        while(size<n) {
            size=size*2;
        }

        tree.assign(2*size+1,0LL); // bitmask representing all the numbers which are present 
        //  40  39  38 ....  5 4 3 2 1 0  (0--> not present , 1--> present)
    }

    void build(vector <ill>& arr,ill num,ill x,ill lx,ill rx) {
        if (lx==rx) {
            if (lx<=num) {
                // tree[x]=arr[lx];
                tree[x]=(tree[x]|(1LL<<arr[lx]));
            }

            return;
        }

        ill mid=(lx+rx)/2;
        build(arr,num,2*x,lx,mid);
        build(arr,num,2*x+1,mid+1,rx);

        // tree[x]=tree[(2*x)] + tree[(2*x + 1)];
        tree[x] = (tree[(2*x)]|tree[(2*x+1)]);
    }

    void build(vector <ill> &arr,ill num) {
        build(arr,num,1,1,size); // x lx rx 
    }
    
    void update(ill index,ill prev,ill val,ill x,ill lx,ill rx) { // index is used to direct which side to update 
        if (lx==rx) {
            
            // tree[x]=val;
            tree[x]=0;
            tree[x]=(tree[x]|(1LL<<val));
            // cout<<x << "  " << tree[x] << endl;
            return;
        }

        ill mid=(lx+rx)/2;
        if (index <= mid) {
            update(index,prev,val,2*x,lx,mid);
        }
        else {
            update(index,prev,val,2*x+1,mid+1,rx);
        }

        // tree[x]=tree[(2*x)] + tree[(2*x+1)];

        // cout<<x << "  " << tree[x] <<endl;
        
        tree[x] = (tree[(2*x)]|tree[(2*x+1)]);

    }

    void update(ill index,ill prev,ill val) {
        update(index,prev,val,1,1,size); // x lx rx  --> range answer stored by x node
        // x --> 1 based 
        // [lx,rx] --> both inclusive 
    }
    
    ill range_query(ill l,ill r,ill x,ill lx,ill rx) {
        // cout<< l << "  " << r << "  " <<  x<< "   " << lx << "  "  <<rx << endl;

        if (l>rx || r<lx) { // no illersection
            return 0LL; // return null  which is 0 in case of sum
        }

        if (lx >= l && rx <= r) { // complete illersection 
            return tree[x]; // return answer stored at that index 
        }

        ill mid=(lx+rx)/2;
        // return range_query(l,r,2*x,lx,mid) + range_query(l,r,2*x+1,mid+1,rx);
        ill res1 = range_query(l,r,2*x,lx,mid);
        ill res2 = range_query(l,r,2*x+1,mid+1,rx);

        return (res1|res2);
    }

    ill range_query(ill l,ill r) {
        return range_query(l,r,1,1,size); 
        // l r --> actual query 
        // x --> node index 
        // lx rx --> answer of the range stored in node x 
    }

    void print() {
        ill i=0;
        for(auto x: tree) {
            cout<< i << " " << x << endl;
            i++;
        }
    }
};

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);  // --> for taking input output from .txt

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout);
    #endif   

    // initialise_fact();
    // final_seive();

    ill tt; 
	// cin>>tt;
    tt=1;

    f1(ic,1,tt) {

        ill num,q;
        cin>>num>>q;

        segtree st;
        st.init(num);

        // st.prill();
        // cout<<st.size<<endl;

        vector <ill> arr(num+1);

        f1(i,1,num) { // 1 based indexing 
            cin>>arr[i];
        }

        st.build(arr,num);

        // st.prill();

        while(q--){
            ill t; 
            cin>>t;

            if (t==1) {
                ill l,r;
                cin>>l>>r;
                
                ill ans=st.range_query(l,r);

                ill c=0;
                f0(i,0,45) {
                    if ((ans&(1LL<<i))) c++;
                }

                cout<<c<<endl;
            }
            else {
                ill i,v;
                cin>>i>>v;
                st.update(i,arr[i],v);
                arr[i]=v;
            }
        }

    }           
    return 0;
}